#include<stdio.h>

int factorial(int n)
{
	return n == 0 ? 1 : factorial(n-1)*n;
}

int main()
{
	printf("%d\n",factorial(10));
	return 0;
}