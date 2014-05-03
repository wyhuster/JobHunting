/*!
* 字符串的组合问题，abc的组合有a,b,c,ab,bc,abc
* \author tonywang
* \date 2014/5/3 19:52
*/

/**
* 递归实现
* 在长度为n的字符串中选择m个字符的组合，有两种情况：
* 1.选择第一个字符，那么要在剩下的长度为n-1中选择m-1个；
* 2.不选择第一个字符，那么要在剩下的长度为n-1中选择m个。
* 递归结束的条件是，当m=0，即不从字符串中再选择字符，那么这时候已经找到m个字符的组合
*/
#include <stdio.h>
#include <string.h>
using namespace std;
#include <vector>

int count=0;

/**
* 从str字符串中选择num个字符，加入result
*/
void combination(char *str, int num, vector<char> &result)
{
	if(!str) return;
	if(num==0)
	{
		printf("the %d combination: ",++count);
		vector<char>::iterator iter = result.begin();
		for( ;iter!=result.end();++iter)
			printf("%c",*iter);
		printf("\n");
		return;
	}
	if(*str == '\0')
		return;
	result.push_back(*str);
	combination(str+1,num-1,result);
	result.pop_back();
	combination(str+1,num,result);
}

void get_all_combination(char *str)
{
	if(!str) return;
	vector<char> result;
	int length = strlen(str);
	for(int i=1;i<=length;i++)
		combination(str, i, result);
}

int main()
{
	char str[256];
	printf("input a string:\n");
	scanf("%s",str);
	get_all_combination(str);
	return 0;
}
