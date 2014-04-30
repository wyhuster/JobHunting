/*!
* 字符串模式匹配，目标串S，模式串T，匹配开始位置pos
* 朴素的模式匹配算法，最差的情况，是每次子串比较到最后一位时不匹配，算法复杂度为O(m*n)
* KMP,算法复杂度O(m+n)
* \author tonywang
* \date 2014/4/30 13:59
*/

#include<stdio.h>

/**
* 朴素模式匹配
* 目标串回溯到下一个开头，模式串回溯到开头
*/
int index_BF(char S[], char T[], int pos)
{
	int i=pos, j=0;
	while(S[i+j]!='\0' && T[j]!='\0')
	{
		if(S[i+j] == T[j])
			j++;   //比较后一个字符
		else   //重新开始一轮匹配
		{
			i++;
			j = 0;
		}
	}
	if(T[j] == '\0')
		return i;  //匹配成功
	else
		return -1; //串S从第pos个字符起，不存在和串T相同的子串
}


/**
* KMP
*/
//根据模式串求模式函数
void get_nextval(const char *T, int next[]) 
{
	// 求模式串T的next函数值并存入数组 next。
	int j = 0, k = -1;
	next[0] = -1;
	while(T[j] != '\0')
	{
		if (k == -1 || T[j] == T[k])  //T[j]表示后缀字符，T[k]表示前缀字符
		{
			++j; 
			++k; 
                   	if (T[j] != T[k]) 
                          	next[j] = k;
                   	else 
                          	next[j] = next[k];
            	}
            	else
                   	k = next[k];
     	}
}

//目标串不回溯，模式串按照模式函数回溯
int index_KMP(char S[], char T[], int pos)
{
	int next[255];
	get_nextval(T,next);

	int i=pos, j=0;
	while(S[i]!='\0' && T[j]!='\0')
	{
		if(S[i] == T[j]) //比较后一个字符
		{
			i++;
			j++;  	
		}
		else   //重新开始一轮匹配
		{
			i++;
			j = next[j];
		}
	}
	if(T[j] == '\0')
		return (i-j);  //匹配成功
	else
		return -1; //串S从第pos个字符起，不存在和串T相同的子串

}

int main()
{
	char *s = "goodgoogle";
	char *t = "google";
	//int result = index_BF(s,t,5);
	int result = index_KMP(s,t,0);
	printf("%d\n",result);
	return 0;
}
