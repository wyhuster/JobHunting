/*!
* 字符串全排列，比如'abc','acb','bac','bca','cab','cba'
* 递归实现，非递归实现，有重复字符的全排列
* \author tonywang
* \date 2014/5/1 17:44
*/
#include<stdio.h>
#include<string.h>
int count = 0;

//交换字符串指针p,q位置的字符值
void swap(char *p, char *q)
{
	char temp = *p;
	*p = *q;
	*q = temp;
}

//递归方法一
void permutation(char *pStr, char *pBegin)
{
	if(!(pStr&&pBegin))
		return;
	if(*pBegin=='\0')
		printf("第%d个排列: %s\n",++count,pStr);
	else
	{
		for(char *pCh=pBegin; *pCh!='\0'; pCh++)
		{
			swap(pBegin,pCh);
			permutation(pStr,pBegin+1);
			swap(pBegin,pCh);
		}
	} 
}

/**
* 递归方法二
* k表示当前选取到第几个数，m表示共有多少个数
*/
void permutation(char *pStr, int k, int m)
{
	if(!pStr)  return;
	if(k==m)
		printf("第%d个排列: %s\n",++count,pStr);
	else
	{
		for(int i=k;i<=m;i++)
		{
			swap(pStr+k, pStr+i);
			permutation(pStr, k+1, m);
			swap(pStr+k, pStr+i);
		}
	}
}


/**
* 有重复的解决办法
* 每次交换的时候，只交换后面非重复的字符，即abb，则a不与第二个b交换
*/
//判断是否需要交换,在[i,j)区间中是否有字符与下标为j的字符相等
bool isSwap(char *pStr, int i, int j)
{
	for(int k=i;k<j;k++)
	{
		if(*(pStr+k)==*(pStr+j))
			return false;
	}
	return true;
}
void permutation_repeat(char *pStr, int k, int m)
{
	if(!pStr)  return;
	if(k==m)
		printf("第%d个排列: %s\n",++count,pStr);
	else
	{
		for(int i=k;i<=m;i++)
		{
			if(isSwap(pStr,k,i))
			{
				swap(pStr+k, pStr+i);
				permutation_repeat(pStr, k+1, m);
				swap(pStr+k, pStr+i);
			}
		}
	}
}

int main()
{
	char *str = new char [256];
	printf("input a string:\n");
	scanf("%s",str);
	//char str[]="abc";
	//permutation(str,str);
	//permutation(str,0,strlen(str)-1);
	permutation_repeat(str,0,strlen(str)-1);
	//delete str;
	return 0;
}
