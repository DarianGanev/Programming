#include <stdio.h>

int get_string_length(const char *str) {
    const char *start = str;
    while (*str != '\0') {
        str++;
    }

    return str - start;
}

int main(){
    char str[] = "Ivan";

    int length = get_string_length(str);

    printf("Length of the string is %d\n", length);

    return 0;
}