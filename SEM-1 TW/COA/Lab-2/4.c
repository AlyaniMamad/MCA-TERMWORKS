#include <stdio.h>
#include <string.h>

int main() {
    char str[100], *p1, *p2;
    int flag = 1;

    printf("Enter a string: ");
    gets(str);

    p1 = str; // set the first pointer to the first character of the string
    p2 = str + strlen(str) - 1; // set the second pointer to the last character of the string

    while (p1 < p2) {
        if (*p1 != *p2) {
            flag = 0;
            break;
        }
        p1++;
        p2--;
    }

    if (flag == 1) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}
