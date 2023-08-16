#include <stdio.h>

int maxOrbitSize(int M, int N) {
    int orbit_set[100];
    for (int i = 0; i < N; i++) {
        orbit_set[i] = 0;
    }

    int x = M % N;
    orbit_set[x] = 1;
    while (1) {
        x = (2 * x) % N;
        if (orbit_set[x] == 1) {
            break;
        }
        orbit_set[x] = 1;
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
        if (orbit_set[i] == 1) {
            count++;
        }
    }
    return count;
}

int main() {
    int M,N;
    printf("Enter the M and N Value : ");
    scanf("%d %d",&M,&N);
    int result = maxOrbitSize(M, N);
    printf("Maximum number of distinct integers in the orbit: %d\n", result);
    return 0;
}