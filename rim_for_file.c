#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
void conversion(int num, FILE* bufer) {
    if (num > 3999)
    {
        exit (0);
    }
    int arabic[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char* roman[] = {"M\0", "CM\0", "D\0", "CD\0", "C\0", "XC\0", "L\0", "XL\0", "X\0", "IX\0", "V\0", "IV\0", "I\0"};
    for (int i = 0; i < 13; i++) {
        if (bufer)
        {
            while (num >= arabic[i]) {
                fputs(roman[i],bufer);
                num-= arabic[i];
            }
        }
        else {
            while (num >= arabic[i]) {
                printf("%s",roman[i]);
                num -= arabic[i];
            }
        }
    }
}

int main(int argc,char* argv[])
{
    FILE* in = fopen(argv[1],"r+b");
    FILE* buf = fopen("bufer.txt", "wb+");
    int i = 0;
    int n = 0;
    char c;
    char* a;

    if (in == NULL)
    {
        int q = atoi(argv[1]);
        conversion(q, in = NULL);
        remove("bufer.txt");
    } else
    {
        while( (c = fgetc(in)) != EOF)
        {
            char num[100];
            if (isdigit(c))
            {
                num[i++] = c;
                n = atoi(num);
                continue;
            }
            else
            {
                if(n)
                    conversion(n, buf);
                for(int a = 0; a < 100; a++)
                {
                    num[a] = 0;
                }
                n = 0;
                i = 0;
            }
            fputc(c,buf);
        }
        fclose(in);
        fclose(buf);
        FILE* in_ = fopen(argv[1],"wb");
        FILE* buf_ = fopen("bufer.txt", "r");
        while((c = getc(buf_)) != EOF)
        {
            fputc(c, in_);
        }
        fclose(in_);
        fclose(buf_);
        remove("bufer.txt");
    }
}

