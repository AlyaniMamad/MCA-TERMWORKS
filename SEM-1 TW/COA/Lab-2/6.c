#include <stdio.h>

void copyArray(int *source, int *target, int size) {
    int i;
    for (i = 0; i < size; i++) {
        *(target + i) = *(source + i);
    }
}

int main() {
    int source[100], target[200], size;

    printf("Enter the size of the source array: ");
    scanf("%d", &size);

    printf("Enter elements of the source array: ");
    int i;
    for (i = 0; i < size; i++) {
        scanf("%d", &source[i]);
    }

    copyArray(source, target, size);

    printf("Elements of the target array: ");
    for (i = 0; i < size; i++) {
        printf("%d ", target[i]);
    }
    printf("\n");

    return 0;
}
