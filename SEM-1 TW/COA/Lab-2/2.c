#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100], *p1, *p2;
    int result;

    printf("Enter the first string: ");
    gets(str1);

    printf("Enter the second string: ");
    gets(str2);

    p1 = str1; // set the first pointer to the first character of the first string
    p2 = str2; // set the second pointer to the first character of the second string

    while (*p1 != '\0' && *p2 != '\0') {
        if (*p1 != *p2) {
            break;
        }
        p1++;
        p2++;
    }

    result = *p1 - *p2;

    if (result == 0) {
        printf("The strings are equal.\n");
    } else if (result < 0) {
        printf("The first string is less than the second.\n");
    } else {
        printf("The first string is greater than the second.\n");
    }

    return 0;
}
