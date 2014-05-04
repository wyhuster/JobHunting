/*!
* word break问题
* 给定一个长字符串，和一个单词词典，将长字符串划分成单词组成的句子
* \author tonywang
* \date 2014/5/4
*/
#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <vector>
using namespace std;

/**
* 给定词典dict，判断字符串s能否进行单词划分
* 动态规划，借助空间H[n]暂存结果，状态量H[i]表示字符串前i个字符组成的字串能够进行单词划分，
* 从1个字符开始判断，每次判断前i个字符能否划分，能划分则标记H[i]为1，
* 判断i时，从j=0开始到j<i，若H[j]=1,说明前j个可划分，则判断s[j..i-j]是否是一个单词，若是则标记H[i]=1，
* 最后若H[n]=1，表明整个字符串能划分。
*/
bool is_word_break(string s, set<string> dict, int H[])
{
	int n = s.size();
	if(n==0)  return false;
	//int H[n+1];
	memset(H,0,(n+1)*sizeof(int));
	H[0] = 1;
	for(int i=1;i<=n;i++)  //判断字符串前i个字符组成的串能否进行单词划分
	{
		for(int j=0;j<i;j++)  //判断0..i-1这i个字符组成的串
		{
			//若前j(0<=j<i)个字符能划分，且s[j..i-j]在字典中能找到，则说明前i个能划分
			if(H[j]==1 && dict.find(s.substr(j,i-j))!=dict.end())
			{
				H[i] = 1;
				break;
			}
		}
	}
	return (H[n] == 1);
}


/**
* 根据H[]输出分割字符串，递归实现
* s 待分割字符串
* now 当前已分割成功的字符串
* idx 每次递归分割时，开始判断的位置，递归时该值为上一次找到的单词尾+1
* H 分割标记数组
* n 字符串长度
* dict 字典
* re 分割的结果，可能有不同组合情况，所以用vector
*/
void backtrack(string s, string now, int idx, int H[], int n, set<string> dict, vector<string> &re)  
{
	if(idx == n)  
	{
		re.push_back(now);  
            	return;  
        }  
	for(int i=idx;i<n;i++)  
      	{
		//后一个条件保证单词中嵌套单词的情况，比如cats，cat和cats都是单词的情况
         	if(H[i+1] == 1 && dict.find(s.substr(idx, i-idx+1)) != dict.end())  
            	{  
                	string new_now;  
                	if(now == "")  
                    		new_now = s.substr(idx, i-idx+1);  
                	else  
                		new_now = now + " " + s.substr(idx, i-idx+1);  
                	backtrack(s, new_now, i+1, H, n, dict, re);  
            	}
       	}  
} 


int main()
{
	set<string> dict;
	//dict.insert("leet");
	//dict.insert("code");
	//string str = "leetcode";
	dict.insert("cat");
	dict.insert("cats");
	dict.insert("sand");
	dict.insert("and");
	dict.insert("dog");
	string str = "catsanddog";
	int n = str.size();
	int H[n+1];
	if(is_word_break(str,dict,H))
	{
		printf("yes\n");
		vector<string> result;
		backtrack(str,"",0,H,n,dict,result);
		printf("split result:\n");
		int count=0;	
		for(vector<string>::iterator iter = result.begin();iter!=result.end();++iter)
			cout<<++count<<") "<<*iter<<endl;
			//printf("%s\n",*iter);
	}
	else
		printf("no\n");
	
	return 0;
}
