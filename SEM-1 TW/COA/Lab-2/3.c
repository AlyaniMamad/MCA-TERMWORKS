#include <stdio.h>

int main() {
    char source[100], target[100], *p1, *p2;

    printf("Enter the source string: ");
    gets(source);

    p1 = source;  // set the first pointer to the first character of the source string
    p2 = target;  // set the second pointer to the first character of the target string

    while (*p1 != '\0') {
        *p2 = *p1;
        p1++;
        p2++;
    }

    *p2 = '\0';  // add the null character to the end of the target string

    printf("Target string: %s\n", target);

    return 0;
}
