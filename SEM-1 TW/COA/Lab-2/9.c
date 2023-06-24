#include <stdio.h>

int main() {
    int sales[4][4] = { { 10, 20, 30, 40 }, { 50, 60, 70, 80 }, { 90, 100, 110, 120 }, { 130, 140, 150, 160 } };
    int quarter, company;

    printf("Enter the quarter (Q1 = 1, Q2 = 2, Q3 = 3, Q4 = 4): ");
    scanf("%d", &quarter);

    printf("Enter the company (C1 = 1, C2 = 2, C3 = 3, C4 = 4): ");
    scanf("%d", &company);

    int *p = &sales[0][0];
    printf("The sales figure for quarter Q%d and company C%d is: %d\n", quarter, company, *(p + (quarter-1)*4 + company-1));

    return 0;
}
