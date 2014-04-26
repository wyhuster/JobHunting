/*!
*二叉树的中序线索化
*@author tonywang
*@date 2014/4/26 17:24
*/

/** 
* Link = 0表示指向左右孩子指针
* Thread = 1表示指向前驱或后继的线索
*/
typedef enum{Link,Thread} PointerTag;

typedef char TElemType;

//二叉树的二叉线索存储结构定义
typedef struct BiThrNode
{
	TElemType data;
	struct BiThrNode *lchild, *rchild;
	PointerTag LTag, RTag;
} BiThrNode, *BiThrTree;


BiThrTree pre;//全局变量，指向刚访问过的结点

/**
* 中序遍历进行中序线索化
*/
void inThreading(BiThrTree p)
{
	if(!p)
		return;
	inThreading(p->lchild);
	//该结点的前驱线索
	if(!p->lchild)
	{
		p->LTag = Thread;
		p->lchild = pre;
	}
	//刚访问过的结点的后继线索
	if(pre)
	{
		if(!pre->rchild)
		{
			pre->RTag = Thread;
			pre->rchild = p;
		}
	}
	pre = p;

	inThreading(p->rchild);
}
