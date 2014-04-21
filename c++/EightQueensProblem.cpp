/*!
*回溯算法，解决八皇后问题：8行8列的棋盘上，
*摆放8个皇后，要求任意两个皇后不在同一行同一列同一斜线上 
*\author tonywang
*\date 2014/4/21 20:55
*/

#include<stdio.h>

#define NUM 8

bool check(int row, int column);
void output();
void solve(int row);

int a[NUM][NUM] = {0}; //棋盘
int num = 0; //解的数目

int main()
{
	solve(0); //从第0行开始摆放皇后
	return 0;
}

/**
* 第row行之前的已经符合条件，在第row行，
* 搜索一列来摆放皇后，要求与之前摆好的都不冲突
*/
void solve(int row)
{
	for(int col=0;col<NUM;col++)
	{
		a[row][col] = 1;
		if(check(row,col))
		{
			if(row==NUM-1)  output();
			else  solve(row+1);
		}
		//取出该列的皇后，进行回溯，在其他列放置皇后 
		a[row][col] = 0;
	}
}

/**
* 检查同一列，同一斜线上不能已经有皇后
*/
bool check(int row, int column)
{
	if(row==0) return true;
	//检查同一列
	for(int i=row-1;i>=0;i--)
		if(a[i][column]==1)  return false;
	//往左上检查
	for(int i=row-1,j=column-1;i>=0&&j>=0;i--,j--)
		if(a[i][j]==1)  return false;
	//往右上检查
	for(int i=row-1,j=column+1;i>=0&&j<NUM;i--,j++)
		if(a[i][j]==1)  return false;
	
	return true;
}

/**
* 输出解矩阵
*/
void output()
{
	num++;
	printf("answer %d:\n",num);
	for(int i=0;i<NUM;i++)
	{
		for(int j=0;j<NUM;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	printf("-------------------------------\n");
}
