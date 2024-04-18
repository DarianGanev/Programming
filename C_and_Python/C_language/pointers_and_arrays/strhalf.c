#include <stdio.h>

void strhalf(char *str, char **half) {
    int len = 0;
    while (str[len] != '\0')
        len++;

    *half = str + len/2;
}

int main() {
    char str[] = "Hello, World!";
    char *half;

    strhalf(str, &half);

    printf("%s", half);

    return 0;
}