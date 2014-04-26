#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef char TElemType;
typedef struct BiTNode
{
	TElemType data;
	struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

TElemType arr[] = {'a','b','#','d','#','#','c','#','#'};
int i=0;

/**
* 构造二叉树
*/
void createBiTree(BiTree *T)
{
	TElemType ch;
	//scanf("%c", &ch);
	ch = arr[i++];

	if(ch=='#')
		*T = NULL;
	else
	{
		*T = (BiTree)malloc(sizeof(BiTNode));
		if(!*T)
			exit(-1);
		(*T)->data = ch;
		createBiTree(& (*T)->lchild);
		createBiTree(& (*T)->rchild);
	}
}

/**
* 前序遍历
*/
void inOrderTraverse(BiTree T)
{
	if(T==NULL)
		return;
	inOrderTraverse(T->lchild);
	printf("%c ", T->data);
	inOrderTraverse(T->rchild);
}
int main()
{
	BiTree T;
	//printf("input former sequence traversal, like:\nab#d##c##\n");
	createBiTree(&T);
	inOrderTraverse(T);
	printf("\n");
	
	return 0;	
}
