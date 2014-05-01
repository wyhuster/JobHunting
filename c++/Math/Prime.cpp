/*!
* 输出不大于n的所有素数(质数)
* 素数是指大于1的自然数中，只能被1和自己整除的数
* \author tonywang
* \date 2014/5/1 15:47
*/

#include<stdio.h>
#include<math.h>

/**
* 筛选法
* 假设开始从2到n所有的数都为素数，然后从2开始筛选，每次循环剔除当前数的倍数
*/
void getPrime(int n)
{
	if(n<2)
		return;
	int res[n+1];
	for(int i=2;i<n+1;i++)
		res[i] = 1;     //初始化假设从2开始所有的数字为素数，然后筛选
	
	for(int i=2;i<n+1;i++)  //开始筛选
	{
		if(res[i]==0)   //如果某个数已经被剔除，说明它的倍数也被剔除了，跳过它的筛选
			continue;
		for(int j=i+i;j<n+1;j+=i)  //从2倍开始，筛选某个数的倍数
			res[j] = 0;
	}

	//输出素数
	for(int i=2;i<n+1;i++)
	{
		if(res[i]==1)
			printf("%d ",i);
	}
}

/**
* 开方法
* 一个数不为素数，则一定有一个约束m,1<m<=sqrt(n)
*/
void getPrime2(int n)
{
	for(int i=2;i<n+1;i++)
	{
		bool is_prime = true;
		int evolution = (int)sqrt(n);
		for(int j=2;j<=evolution;j++)
		{
			if(i%j==0)
			{
				is_prime = false;
				break;
			}
		}
		if(is_prime)
			printf("%d ",i);
	}
}

int main()
{
	int num;
	printf("input a number bigger than 2:");
	scanf("%d",&num);
	//getPrime(num);
	getPrime2(num);
	printf("\n");
}


