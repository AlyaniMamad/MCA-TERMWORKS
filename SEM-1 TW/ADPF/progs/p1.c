#include<stdio.h>
int fun1(int no,int count)
{
    //base
    if(no==1)
    {
        return count;
    }else{
        if (no%2==0)
        {
            return fun1(no/2,++count);
        }else{
            return fun1(3*no+1,++count);
        }
        
    }
}
int main()
{
    int count=0;
    int no;
    printf("Enter N : ");
    scanf("%d",&no);
    int ans=fun1(no,count);
    printf("Ans : %d",ans);
    return 0;
}