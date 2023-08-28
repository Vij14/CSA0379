#include<stdio.h>
int main()
{
	int i,fact=1,number;
	printf("enter a number:");
	scanf("%d",&number);
	{
	if(number<0){
		printf("please enter a positive");
		return 0;}
	else
	for(i=1;i<=number;i++)
	{
		fact=fact*i;
	}
		
	}
	printf("factorial of %d is: %d0",number,fact);
	return 0;
}
