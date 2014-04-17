// Sort.cpp : 定义控制台应用程序的入口点。
// 
#include "stdafx.h"

#define MAXSIZE 10

void swap(int* arr, int i, int j);
void bubbleSort(int* arr, int length);
void selectSort(int* arr, int length);
void insertSort(int* arr,int length);
void shellSort(int* arr,int length);
void heapSort(int* arr, int length);
void mergeSort(int* arr, int length);
void mergeSort2(int* arr, int length);


int _tmain(int argc, _TCHAR* argv[])
{
	int number[10]={10,2,3,5,7,7,2,1,0,-1};
	int length = sizeof(number)/sizeof(int);
	printf("before sort: ");
	for(int i=0;i<length;i++)
		printf("%d  ",number[i]);
	printf("\n");

	//bubbleSort(number,length);
	//selectSort(number,length);
	//insertSort(number,length);
	//shellSort(number,length);
	//heapSort(number,length);
	//mergeSort(number,length);
	mergeSort2(number,length);

	printf("after  sort: ");
	for(int i=0;i<length;i++)
		printf("%d  ",number[i]);
	
	getchar();
	return 0;
}

void swap(int* arr, int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}


/**
---------------------冒泡排序----------------------------
*时间复杂度：O(n^2)
*空间复杂度：O(1)
*稳定
---------------------------------------------------------*/
void bubbleSort(int* arr, int length)
{
	bool flag = true;
	for(int i=0;i<length && flag;i++)
	{
		bool flag = false;
		for(int j=length-1;j>i;j--)
		{
			if(arr[j-1]>arr[j]){
				swap(arr,j-1,j);
				flag = true;
			}
		}
	}
}


/**
----------------------简单选择排序-----------------------
*时间复杂度：O(n^2)
*空间复杂度：O(1)
*稳定
---------------------------------------------------------*/
void selectSort(int* arr, int length)
{
	for(int i=0;i<length;i++)
	{
		int min = i;
		for(int j=i+1;j<length;j++)
		{
			if(arr[j]<arr[min])
			{
				min = j;
			}
		}
		if(min != i)
			swap(arr,i,min);
	}
}


/**
---------------------直接插入排序------------------------
*时间复杂度：O(n^2)
*空间复杂度：O(1)
*稳定
---------------------------------------------------------*/
void insertSort(int* arr,int length)
{
	for(int i=1;i<length;i++)
	{
		if(arr[i]<arr[i-1])
		{
			int temp = arr[i];
			int j;
			for(j=i-1;arr[j]>temp;j--)
				arr[j+1] = arr[j];
			arr[j+1] = temp;
		}
	}
}


/**
----------------------希尔排序---------------------------
*时间复杂度：O(nlogn)~O(n^2)
*空间复杂度：O(1)
*不稳定
---------------------------------------------------------*/
void shellSort(int* arr,int length)
{
	int increment = length;
	while(increment>1){
		increment = increment/3+1;
		//printf("%d\n",increment);
		for(int i=increment;i<length;i++)
		{
			if(arr[i]<arr[i-increment])
			{
				int temp = arr[i];
				int j;
				for(j=i-increment;j>=0&&arr[j]>temp;j-=increment)
					arr[j+increment] = arr[j];
				arr[j+increment] = temp;
			}
		}
	}
}


/**
----------------------堆排序------------------------------
*时间复杂度：构建堆O(n)，重建堆O(nlogn)，总复杂度为O(nlogn)
*空间复杂度：O(1)
*不稳定
---------------------------------------------------------*/
void heapSort(int* arr, int length)
{
	void heapAdjust(int* arr, int s, int e);

	for(int i=length/2;i>0;i--)
		heapAdjust(arr, i, length);
	
	for(int i=length;i>1;i--)
	{
		swap(arr,0,i-1);
		heapAdjust(arr, 1, i-1);
	}
}

/*
已知arr[s-1..e-1]除arr[s-1]外，都符合堆的定义，
调准arr[s-1]，使arr[s-1..e-1]成为一个大顶堆
*/
void heapAdjust(int* arr, int s, int e)
{
	int temp = arr[s-1];  //需要调准的根节点
	for(int j=2*s;j<=e;j*=2)
	{
		if(j<e && arr[j-1]<arr[j]) //左孩子和右孩子哪个较大,沿大的往下比较
			++j;
		if(temp>=arr[j-1])
			break;
		arr[s-1] = arr[j-1];
		s = j;
	}
	arr[s-1] = temp;
}



/**
*--------------归并排序，递归实现------------------
*时间复杂度：logn次归并，每次归并遍历n，O(nlogn)
*空间复杂度: 归并过程中的存储空间O(n)+递归深度O(logn)
*稳定
**/
void mergeSort(int* arr, int length)
{
	void mSort(int* arr1, int* arr2, int s, int e);

	mSort(arr,arr,0,length-1);
}

//将arr1[s..e]归并排序为arr2[s..e]
void mSort(int* arr1, int* arr2, int s, int e)
{
	void merge(int* arr1, int* arr2, int s, int m, int e);

	int *arr = new int[MAXSIZE];
	if(s == e)
		arr2[s]=arr1[s];
	else
	{
		int m = (s+e)/2;
		mSort(arr1,arr,s,m);
		mSort(arr1,arr,m+1,e);
		merge(arr,arr2,s,m,e);
	}
}

//将有序的arr1[s..m]和arr1[m+1..e]归并到有序的arr2[s..e]
void merge(int* arr1, int* arr2, int s, int m, int e)
{
	int i;
	for(i=s;s<=m&&m+1<=e;i++)
	{
		if(arr1[s]<arr1[m+1])
			arr2[i] = arr1[s++];
		else
		{
			arr2[i] = arr1[m+1];
			m++;
		}
	}
	if(s<=m)
	{
		for(int k=0;k<=m-s;k++)
			arr2[i+k] = arr1[s+k];
	}
	if(m+1<=e)
	{
		for(int k=0;k<=e-m-1;k++)
			arr2[i+k] = arr1[m+1+k];
	}

}


/**
*--------------归并排序，非递归实现------------------
*时间复杂度：O(nlogn)
*空间复杂度: 归并过程中的存储空间O(n)
*稳定
**/
void mergeSort2(int* arr, int length)
{
	void mergePass(int* arr1, int* arr2, int s, int n);

	int* tr = new int[length];
	int k=1;
	while(k<length)
	{
		mergePass(arr,tr,k,length);
		k = 2*k;
		mergePass(tr,arr,k,length);
		k = 2*k;
	}
}

//将arr1中相邻为s的子序列两两归并到arr2中
void mergePass(int* arr1, int* arr2, int s, int n)
{
	int i = 1;
	while(i<=n-2*s+1)
	{
		merge(arr1,arr2,i-1,i+s-1-1,i+2*s-1-1);
		i=i+2*s;
	}
	if(i<n-s+1)
		merge(arr1,arr2,i-1,i+s-1-1,n-1);
	else
		for(int j=i-1;j<n;j++)
			arr2[j] = arr1[j]; 
}