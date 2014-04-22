/*!
*散列表实现
*\author tonywang
*\date 2014/4/22 19:59
*/

#include<stdio.h>
#include<malloc.h>

#define HASHSIZE 12
#define NULLKEY -32768

typedef struct
{
	int *elem;  //动态分配数组
	int count;
}HashTable;

/**
* 初始化Hash表
*/
void initHashTable(HashTable *H)
{
	H->count = HASHSIZE;
	H->elem = (int *)malloc(HASHSIZE*sizeof(int));
	for(int i=0;i<HASHSIZE;i++)
		H->elem[i] = NULLKEY;
}

/**
* hash算法
*/
int hash(int key)
{
	return key % HASHSIZE;  //除留余数法
}

/**
* 插入数据到Hash表
*/
void insertHash(HashTable *H, int key)
{
	int addr = hash(key);
	//解决冲突
	while(H->elem[addr] != NULLKEY)
		addr = (addr+1) % HASHSIZE; //线性探测
	H->elem[addr] = key;
}

/**
* Hash表查找关键字
*/
bool searchHash(HashTable H, int key, int *addr)
{
	*addr = hash(key);
	while(H.elem[*addr] != key)
	{
		*addr = (*addr+1) % HASHSIZE;
		//如果Hash值为NULLKEY，或者循环回到原点，说明没找到
		if((H.elem[*addr] == NULLKEY) || (*addr == hash(key)))
			return false;
	}
	return true;
}


int main()
{
	int arr[HASHSIZE] = {22,25,38,15,47,29,78,67,56,21,12,16};
	HashTable hashTable;
	initHashTable(&hashTable);
	for(int i=0;i<HASHSIZE;i++)
		insertHash(&hashTable, arr[i]);
	
	int *elem = hashTable.elem;
	for(int i=0;i<hashTable.count;i++)
		printf("%d ", elem[i]);
	printf("\n");
	
	int addr;
	if(searchHash(hashTable,47,&addr))
		printf("find 47.\n");
	if(searchHash(hashTable,30,&addr))
		printf("find 47.\n");

	return 0;
}



