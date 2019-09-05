#include<stdio.h>

int a=16;
int main()
{
for(int i=1;i<16;i++)
{
	printf("%d",a%2);
	a/=2;
}
}
