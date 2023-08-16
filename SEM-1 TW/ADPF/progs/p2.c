#include<stdio.h>
#include<string.h>
void charfun()
{
    char str;
    scanf("%c",&str);
    if(str!='\n')
    {
        charfun();
        printf("%c",str);
    }
}
int main()
{
    printf("\nEnter String : ");
    charfun();
    return 0;
}