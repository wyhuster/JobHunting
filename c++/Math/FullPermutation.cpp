/*!
* 字符串全排列，比如'abc','acb','bac','bca','cab','cba'
* 递归实现，非递归实现，有重复字符的全排列
* \author tonywang
* \date 2014/5/1 17:44
*/
#include<stdio.h>
#include<stdlib.h>
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
	count = 0;
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
	count = 0;
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
	count = 0;
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


/**
* 非递归实现全排列
* 关键在于如何找下一个排列
* 首先进行一次排序，然后从后往前两两比较，选择第一个递增的点，该点为替换点，该数为替换数，
* 再往后选择大于替换数的最小的数，两者交换，然后再将替换点后面的数反转，返回true，再在这个基础上找下一个排列，
* 如果找不到递增点（说明是逆序了），则反转一次（恢复顺序），返回false，结束
*/
//反转字符串，a指向字符串首，b指向尾
void reverse(char *a, char *b)
{
	while(a<b)
		swap(a++,b--);
}

//寻找下一个排列，找到则返回true，否则返回false
bool next_permutation(char *str)
{
	if(!str)  return false;
	char *pEnd = str+strlen(str)-1; //指向字符串尾部
	char *p = pEnd; //选择第一个递增的字符时，指向前面一个，找到后即为替换点
	char *q; //选择第一个递增的字符时，指向后面一个
	while(p!=str)
	{
		q = p;
		p--;
		if(*p<*q)
		{
			//从后向前找比替换数大的第一个数
			char *pFind = pEnd;
			while(*pFind <= *p)
				pFind--;
			//替换
			swap(pFind, p);
			//替换点后的数反转
			reverse(q, pEnd);
			return true;	
		}
	}
	reverse(p, pEnd);
	return false;
}
//STL sort要用的比较器
int qsort_cmp(const void *pa, const void *pb)  
{  
    return *(char*)pa - *(char*)pb;  
}
//非递归实现全排列
void non_recursion_permutation(char *str)
{
	count = 0;
	//STL排序
	qsort(str, strlen(str), sizeof(str[0]), qsort_cmp);
	do{
		printf("第%d个排列：%s\n",++count,str);
	}while(next_permutation(str));
}


int main()
{
	char *str = new char [256];
	printf("input a string:\n");
	scanf("%s",str);
	//char str[]="abc";
	//printf("递归实现全排列：\n");
	//permutation(str,str);
	//permutation(str,0,strlen(str)-1);
	//printf("递归实现去重全排列：\n");
	//permutation_repeat(str,0,strlen(str)-1);  //去除重复的
	printf("非递归实现全排列：\n");
	non_recursion_permutation(str);
	delete str;
	return 0;
}
