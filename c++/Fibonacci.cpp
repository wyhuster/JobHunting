#include<stdio.h>

int fibonacci_recursion(int n);
int fibonacci_non_recursion(int n);

int main()
{
	//printf("%d\n",fibonacci_recursion(10));
	printf("%d\n",fibonacci_non_recursion(10));
	return 0;
}

//递归计算Fibonacci数列中第n+1个值
int fibonacci_recursion(int n)
{
	if(n == 0)
		return 0;
	else if(n==1)
		return 1;
	else if(n>1)
		return fibonacci_recursion(n-1)+fibonacci_recursion(n-2);
	else
		return -1;
	
}

//非递归计算Fibonacci数列中第n+1个值
int fibonacci_non_recursion(int n)
{
	int f0=0, f1=1;
	if(n==0) return 0;
	if(n==1) return 1;
	if(n>2)
	{
		int f;
		for(int i=2;i<=n;i++)
		{
			f = f0 + f1;
			f0 = f1;
			f1 = f;
		}
		return f;
	}
	return -1;
}





