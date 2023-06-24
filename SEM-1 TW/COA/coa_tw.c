#include<stdio.h>
#include<math.h>
#include<string.h>
int main()
{
    mylbl :
    /*For Taking Inputs From User*/
    int N=0;
    printf("\nHow Many Inputs? : ");
    scanf("%d",&N);
    int a[N];
    char F[400]="";

    /*Removing Default Garbage*/
    for (int i=0;i<N;i++)
    {
        a[i]=0;
    }
    if(N<9 && N>0)
    {
        /*Display All Possible Inputs*/
        //Header
        int f[20];
        int temp=pow(2,N);
        printf("\nEnter F one by one for %d times : \n",temp);
        for(int k=0;k<temp;k++)
        {
            scanf("%d",&f[k]);   
        }
        printf("\n\n\t*  TRUTH TABLE  *\n\n\t");
        //Title Of Truth Table
        for(int head=65;head<65+N;head++)
        {
            printf("%c ",head);
        }
        /*Minterm Logic*/
        printf("Minterm");
        printf("\tF\n");
        for(int decimal=0,j=0;decimal<pow(2,N);decimal++)
        {
            printf("\n\t");
            for(int bit=N-1,d=decimal;d>0;d/=2,bit--)
            {
                a[bit]=d%2;
            }
            for(int i=0;i<N;i++)
            {
                printf("%d ",a[i]);
            }
            char ch='A';
            printf(" ");
                if(f[decimal]==1)
                {
                    strcat(F,"(");
                    j++;
                    for(int i=0;i<N;i++,ch++,j++)
                    {
                        printf("%c",ch);
                        F[j]=ch;
                        if(a[i]==0)
                        {
                            j++;
                            F[j]='`';
                            printf("'");
                        }
                        else
                            printf(" ");  
                    }
                    strcat(F,")+");   
                    j+=2;
                }
                else
                {
                    for(int i=0;i<N;i++,ch++)
                    {
                        printf("%c",ch);
                        if(a[i]==0)
                            printf("'");
                        else
                            printf(" "); 
                    }
                }
                printf("\t%d",f[decimal]);
        }
        F[strlen(F)-1]='\0'; //Removing last + sign from boolean funtion
        printf("\n\nF = %s\b",F);
    }
    else{
        printf("\nInvalid Input.......please Re-input");
        goto mylbl;
    }
    int io=0;
    printf("\n-->Wants to Re-Input?<--");
    printf("\n------------------------------");
    printf("\n-->Enter 1 for Re-input    <--");
    printf("\n-->Enter Anything For Exit <--");
    printf("\n-->Your Choice :");
    scanf("%d",&io);
    printf("------------------------------");
    if(io==1) // checking for Re-choice
    {
        goto mylbl;
    }
    else{
        printf("\nExiting...");
    }
    return 0;
}