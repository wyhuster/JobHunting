/*!
* 
* 实现有序表的查找算法，包括递归实现二分查找，
* 非递归实现二分查找，插值查找
* \author tonywang
* \date 2014/4/17 21:50
*
*/

#include<stdio.h>
#include <stdlib.h> 

int binarySearch(int* arr, int length, int key);
int binarySearch2(int* arr, int begin, int end, int key);
int interpolationSearch(int* arr, int length, int key);

int main(int argc, char* argv[])
{
	int arr[10] = {1,2,3,4,5,6,7,8,9,10}; 
	
	if(argc!=2)
	{
		printf("usage: ./Search [key]");
		return -1;
	}
	int key = atoi(argv[1]);
	
	//int result = binarySearch(arr, 10, key);
	//int result = binarySearch2(arr, 0, 9, key);
	int result =  interpolationSearch(arr, 10, key);
	
	if(result>-1)
		printf("find %d at position %d.\n", key, result+1);
	else 
		printf("not find %d.\n", key);
        
	return 0;
}

//非递归实现二分查找
int binarySearch(int* arr, int length, int key)
{
        int i = 0;
        int j = length-1;
        while(i<=j)
        {
                int m = (i+j)/2;
                if(key==arr[m])
                        return m;
                else if(key<arr[m])
                        j = m-1;
                else
                        i = m+1;
        }
        
        return -1;
}

//递归实现二分查找
int binarySearch2(int *arr, int begin, int end, int key)
{
	if(begin<=end)
	{
		int m = (begin+end)/2;
		if(key<arr[m])
			return binarySearch2(arr,begin,m-1,key);
		else if(key>arr[m])
			return binarySearch2(arr,m+1,end,key);
		else
			return m;
	}
	return -1;
}

//插值查找，二分查找的优化，(low+high)/2换成插值计算公式
int interpolationSearch(int* arr, int length, int key)
{
        int i = 0;
        int j = length-1;
        while(i<=j)
        {
                //int m = (i+j)/2;
		//插值
		int m = i;
                if(i!=j)
			int m = i + ((key-arr[i])/(arr[j]-arr[i]))*j;
		if(key==arr[m])
                        return m;
                else if(key<arr[m])
                        j = m-1;
                else
                        i = m+1;
        }
        
        return -1;
}
