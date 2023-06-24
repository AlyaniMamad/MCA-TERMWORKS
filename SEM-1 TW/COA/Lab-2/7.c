#include <stdio.h>

int checkEvenOdd(int num) {
    if (num % 2 == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int num;
    int (*check)(int);

    check = &checkEvenOdd;

    printf("Enter a number: ");
    scanf("%d", &num);

    if ((*check)(num)) {
        printf("The number is even.\n");
    } else {
        printf("The number is odd.\n");
    }

    return 0;
}
