// Sort.cpp : 定义控制台应用程序的入口点。
// 
#include "stdafx.h"

void swap(int* arr, int i, int j);
void bubbleSort(int* arr, int length);
void selectSort(int* arr, int length);
void insertSort(int* arr,int length);


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
	insertSort(number,length);

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

//冒泡排序
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

//简单选择排序
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

//直接插入排序
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

//希尔排序
//void shellSort(int* arr,int length)
//{
//	int increment = length/3+1;
//	while(increment>=1){
//		//for(int i=)
//		increment = increment/3+1;
//	}
//}
