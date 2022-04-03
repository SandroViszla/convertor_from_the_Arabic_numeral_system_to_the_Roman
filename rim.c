#include <stdio.h>

char *conversion(int);
void function(int, int, char *, int *);
void output(char *);

int main() {
    int ArabicNumber = 0;
    char *RomanNumber = NULL;
    char ch;

    printf("Пожалуйста введите число, если вы захотите завершить работу то нажмите Cntrl+D\n");
    int return_code = scanf("%d", &ArabicNumber);
    while (return_code != 0 && (ch = getchar()) != EOF) {
        RomanNumber = conversion(ArabicNumber);
        if (RomanNumber == NULL) {
            return_code = scanf("%d", &ArabicNumber);
            continue;
        }
        return_code = scanf("%d", &ArabicNumber);
    }
    return 0;
}

char* conversion(int num) {
    char* a;
    int check;
    if (num > 3999){
        printf("Извините, но нельзя вводить число больше чем 3999. Введите новое число:\n");
        return NULL;
    }
    int arabic[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char* roman[] = {"M\0", "CM\0", "D\0", "CD\0", "C\0", "XC\0", "L\0", "XL\0", "X\0", "IX\0", "V\0", "IV\0", "I\0"};
    printf("Римский вид:\n");
    for (int i = 0; i < 13; i++) {
        while (num >= arabic[i]) {
            printf("%s",roman[i]);
            num-= arabic[i];
        }
    }
    printf("\n");
    return a;
}
