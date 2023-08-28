#include<stdio.h>
#include<conio.h>
int main()
{
	int num,first=0,second=1,next,i;
	printf("Enter a number:");
	scanf("%d",&num);
	printf("First %d terms of the fibonacci series are :\n",num);
	for(i=0;i<num;i++)
	{
		if(i<=1)
		next=i;
		else
		{
			next=first+second;
			first=second;
			second=next;
		}
		printf("%d\t",next);
	}
}
