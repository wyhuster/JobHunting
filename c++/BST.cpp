/*!
*二叉排序(查找)树的定义，查找、插入、删除等算法实现
*\author tongywang
*\date 2014/4/21 09:00
*/

#include<stdio.h>
#include<malloc.h>

typedef struct BiTNode
{
	int data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

/**
* 递归查找二叉排序树T中是否存在key
*/
bool searchBST(BiTree T, int key)
{
	if(T==NULL)
		return false;
	else if(key==T->data)
		return true;
	else if(key<T->data)
		return searchBST(T->lchild, key);
	else
		return searchBST(T->rchild, key);

}

/**
* 非递归查找二叉排序树T中是否存在key
*/
bool searchBST2(BiTree T, int key)
{
	while(T)
	{
		if(key==T->data)
			return true;
		else if(key<T->data)
			T = T->lchild;
		else
			T = T->rchild;
	}
	return false;
}


/**
* 往二叉排序树T中插入元素节点key
*/
void insertBST(BiTree *T, int key)
{	
	if (*T==NULL)
	{
		BiTree x;
		x=new BiTNode;
		x->data=key;
		x->lchild=x->rchild=NULL;
		*T=x;
	}
	else
	{
		if (key<(*T)->data)
		{
			insertBST(&((*T)->lchild),key);
		}
		else
		{		
			insertBST(&((*T)->rchild),key);
		}
	}
	
}

/**
* 从二叉排序树中删除节点元素key
*/
bool del(BiTree *p);
bool deleteBST(BiTree *T, int key)
{
	if(*T==NULL)  return false;
	else
	{
		if(key==(*T)->data)
			return del(T);
		else if(key<(*T)->data)
			return deleteBST(&((*T)->lchild),key);
		else
			return deleteBST(&((*T)->rchild),key);
	}
}

/**
* 删除节点p,并使二叉排序树结构不改变
*/
bool del(BiTree *p)
{
	BiTree q, s;
	if((*p)->rchild == NULL)
	{
		q = *p;
		*p = (*p)->lchild;
		free(q);
	}
	else if((*p)->lchild == NULL)
	{
		q = *p;
		*p = (*p)->rchild;
		free(q);
	}
	else//寻找前驱结点
	{
		q = *p;
		s = (*p)->lchild;
		while(s->rchild)
		{
			q = s;
			s = s->rchild;
		}
		(*p)->data = s->data;
		if(q!=*p)
			q->rchild = s->lchild;
		else
			q->lchild = s->lchild;
		free(s);
	}
	return true;
}

/**
* 中序遍历二叉排序树，按排序结果打印输出
*/
void inOrderBST(BiTree T)
{
	if(T == NULL)	return;
	inOrderBST(T->lchild);
	printf("%d ", T->data);
	inOrderBST(T->rchild);
}

int main()
{
	int arr[10] = {1,3,4,10,3,6,7,5,4,0};
	BiTree T = NULL;
	for(int i=0;i<10;i++)
		insertBST(&T, arr[i]);
	printf("中序遍历: ");
	inOrderBST(T);
	printf("\n");

	if(searchBST(T,4))
		printf("find 4.\n");
	if(searchBST(T,11))
		printf("find 11.\n");
	if(searchBST2(T,10))
		printf("non-recursion find 10.\n");
	if(searchBST2(T,9))
		printf("non-recursion find 9.\n");

	if(deleteBST(&T,9))
		printf("delete 9.\n");
	
	//printf("中序遍历: ");
	//inOrderBST(T);
	//printf("\n");

	if(deleteBST(&T,3))
		printf("delete 3.\n");

	printf("中序遍历: ");
	inOrderBST(T);
	printf("\n");
	
	insertBST(&T,11);
	printf("insert 11.\n");
	
	printf("中序遍历: ");
	inOrderBST(T);
	printf("\n");
	
	insertBST(&T,4);
	printf("insert 4.\n");

	printf("中序遍历: ");
	inOrderBST(T);
	printf("\n");

	return 0;
}

