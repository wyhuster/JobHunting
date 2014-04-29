/*!
* 找最小生成树（n-1条边连接n个顶点的权重最小的连通图），
* 两种经典算法:普里姆算法(Prim)和克鲁斯卡尔算法(Kruskal)
* \author tonywang
* \date 2014/4/28 18:07
*/

#include<stdio.h>
#include<malloc.h>

#define INFINITY 65535 
#define MAXVEX 9

/**
* 【Prim算法】从顶点出发
* 首先以一个结点作为最小生成树的初始结点，然后以迭代的方式
* 找出与最小生成树中各结点权重最小边，并加入到最小生成树中。
* 加入之后如果产生回路则跳过这条边，选择下一个结点。
* 当所有结点都加入到最小生成树中之后，就找出了连通图中的最小生成树了。
*/
void miniSpanTree_Prim(int graph[][MAXVEX])
{
	int lowcost[MAXVEX];  //保存已加入到最小生成树中顶点到其他顶点的最小权重，为0表示此下标的顶点已加入生成树
	int adjvex[MAXVEX]; //保存lowcost中权值所对应的出发顶点

	lowcost[0] = 0;  //初始化第一个权值为0，即V0加入生成树
	adjvex[0] = 0;  //初始化第一个顶点下标为0
	for(int i=1;i<MAXVEX;i++)
	{
		lowcost[i] = graph[0][i];   //将V0顶点与之有边的权值存入数组
		adjvex[i] = 0;
	}
	for(int i=1;i<MAXVEX;i++)
	{
		int min = INFINITY;  //初始化最小权重为无穷大
		int k = 0;  //保存当前最小生成树外连权重最小的下标
		
		for(int j=1;j<MAXVEX;j++)
		{
			if(lowcost[j]!=0 && lowcost[j]<min)
			{
				min = lowcost[j];
				k = j;
			}
		}
		printf(" (%d,%d) ", adjvex[k], k);     //打印当前顶点边中权值最小边，即新加入最小生成树的边

		lowcost[k] = 0;  //将当前顶点的权值设为0，表示已加入最小生成树
		for(int j=1;j<MAXVEX;j++)
		{
			if(lowcost[j]!=0 && graph[k][j] < lowcost[j])  //若下标为k顶点各边权值小于此前这些顶点未被加入生成树权值
			{
				lowcost[j] = graph[k][j];   //将较小权值存入lowcost
				adjvex[j] = k;
			}
		}
	}
}


/**
* 【Kruskal算法】从边出发
* 使用边集数组结构，将每条边按权重大小排序，
* 从权值最小的边选取，选择过程中形成环，则放弃该条边，继续选择
*/

//边集数组Edge结构的定义
typedef struct
{
	int begin;
	int end;
	int weight;
}Edge;

//查找连线顶点的尾部下标，用于判断是否形成环
int find(int *parent, int f)
{
	while(parent[f]>0)
		f = parent[f];
	return f;
}

void miniSpanTree_Kruskal(Edge edges[], int MAXEDEG)
{
	int parent[MAXVEX];    //用于判断边与边是否形成环路
	for(int i=0;i<MAXVEX;i++)
		parent[i] = 0;
	for(int i=0;i<MAXEDEG;i++)
	{
		int n = find(parent,edges[i].begin);
		int m = find(parent,edges[i].end);
		if(n!=m)  //没有形成环
		{
			parent[n] = m;  //表面这条边已在最小生成树中
			printf("(%d,%d) %d\n",edges[i].begin,edges[i].end,edges[i].weight);
		}
	}

}

/**
* 将图的邻接矩阵转换成边集数组
*/
void graphToEdges(int graph[][MAXVEX], Edge edges[])
{
	int count=0;
	while(true)
	{
		int min = INFINITY;
		int min_x,min_y;
		for(int i=0;i<MAXVEX;i++)
		{
			for(int j=i+1;j<MAXVEX;j++)
			{
				if(graph[i][j]<min)
				{
					min = graph[i][j];
					min_x = i;
					min_y = j;
				}
			}
		}
		if(min==INFINITY)  //已经没有可行边了
			break;
	
		graph[min_x][min_y] = INFINITY;//剔除最小的，方便寻找次小的
	
		Edge *edge = (Edge*)malloc(sizeof(Edge));
		edge->begin = min_x;
		edge->end = min_y;
		edge->weight = min;
		edges[count++] = *edge;
	}	
}


int main()
{
	int graph[MAXVEX][MAXVEX];
	for(int i=0;i<MAXVEX;i++)
	{
		for(int j=0;j<MAXVEX;j++)
		{
			if(i == j)
				graph[i][j] = 0;
			else
				graph[i][j] = INFINITY; 
		}
	}
	graph[0][1] = graph[1][0] = 10;
	graph[0][5] = graph[5][0] = 11;
	graph[1][2] = graph[2][1] = 18;
	graph[1][6] = graph[6][1] = 16;
	graph[1][8] = graph[8][1] = 12;
	graph[2][3] = graph[3][2] = 22;
	graph[2][8] = graph[8][2] = 8;
	graph[3][4] = graph[4][3] = 20;
	graph[3][6] = graph[6][3] = 24;
	graph[3][7] = graph[7][3] = 16;
	graph[3][8] = graph[8][3] = 21;
	graph[4][5] = graph[5][4] = 26;
	graph[4][7] = graph[7][4] = 7;
	graph[5][6] = graph[6][5] = 17;
	graph[6][7] = graph[7][6] = 19;


	printf("Prim:\n");
	miniSpanTree_Prim(graph);
	printf("\n\n");

	printf("Kruskal:\n");
	Edge edges[15];
	graphToEdges(graph,edges);
	miniSpanTree_Kruskal(edges,15);
	
	return 0;
}
