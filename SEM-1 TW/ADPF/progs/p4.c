#include<stdio.h>
int main()
{
	char str[100];
	int i,count,len=999;
        printf("Enter the string:\n");
	    scanf("%s",str);
	for(i=0,count=0;str[i]!='\0';i++,count++)
	{
		if(str[i]!=str[i+1])
		{
			if(count<len)
				len=count;
			count=0;
		}
	}
	printf("%d",len);
	return 0;
}
