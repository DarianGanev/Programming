#include <stdio.h>
#include <string.h>

void removeNewLine(char *str) {
    char *newLine = strchr(str, '\n');
    if (newLine) {
        *newLine = '\0';
    }
}

int main() {
    char input[100];
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    removeNewLine(input);
    printf("Modified string: %s\n", input);
    return 0;
}