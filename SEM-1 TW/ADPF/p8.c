#include <stdio.h>

int main()
{
	int N;

	printf("Enter the number of rows : ");
	scanf("%d", &N);
	printf("*\n");

	for(int i=1; i<=N; i++)
		{
			for(int j=1; j<=i; j++)
				{
					if(j == 1)
						printf("*");
					printf("%d", j);
				}
			for(int j=i-1; j>=1; j--)
				{		
					printf("%d", j);
				}
			printf("*");
			printf("\n");
		}
        for(int i=N-1; i>=1; i--)
            {
                for(int j=1; j<=i; j++)
                    {
                        if(j == 1)
                            printf("*");
                        printf("%d", j);
                    }
                for(int j=i-1; j>=1; j--)
                    {
                        printf("%d", j);
                    }
                printf("*");
                printf("\n");
            }
	printf("*\n");
	return 0;
}