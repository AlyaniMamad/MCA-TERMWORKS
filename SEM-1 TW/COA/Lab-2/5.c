#include <stdio.h>

void removeChar(char *string, char ch) {
    char *p1, *p2;

    p1 = string;
    p2 = string;

    while (*p2 != '\0') {
        if (*p2 != ch) {
            *p1 = *p2;
            p1++;
        }
        p2++;
    }

    *p1 = '\0';
}

int main() {
    char str[100], ch;

    printf("Enter a string: ");
    gets(str);

    printf("Enter a character to remove: ");
    scanf("%c", &ch);

    removeChar(str, ch);

    printf("Modified string: %s\n", str);

    return 0;
}
