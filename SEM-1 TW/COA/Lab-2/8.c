#include <stdio.h>

float average(float arr[], int m) {
    int i;
    float sum = 0;
    for (i = 0; i < m; i++) {
        sum += arr[i];
    }
    return sum / m;
}

int main() {
    float arr[10];
    int m, i;

    printf("Enter 10 float numbers: ");
    for (i = 0; i < 10; i++) {
        scanf("%f", &arr[i]);
    }

    printf("Enter the number of elements to calculate average: ");
    scanf("%d", &m);

    float result = average(arr, m);
    printf("The average of the first %d numbers is: %f\n", m, result);

    return 0;
}
