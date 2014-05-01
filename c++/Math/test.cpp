#include<stdio.h>

void swap(char *p, char *q)
{
        char temp = *p;
        *p = *q;
        *q = temp;
}

bool isSwap(char *pBegin , char *pEnd)  
{  
    char *p;  
    for(p = pBegin ; p < pEnd ; p++)  
    {  
        if(*p == *pEnd)  
            return false;  
    }  
    return true;  
}  

void permutation(char *pStr , char *pBegin)  
{  
    //assert(pStr);  
  
    if(*pBegin == '\0')  
    {  
        static int num = 1;
        printf("第%d个排列: %s\n",num++,pStr);
    }  
    else  
    {  
        for(char *pCh = pBegin; *pCh != '\0'; pCh++)
        {  
            if(isSwap(pBegin , pCh))  
            {  
                swap(pBegin , pCh);  
                permutation(pStr , pBegin + 1);  
                swap(pBegin , pCh);  
            }  
        }  
    }  
}  
  
int main()  
{  
    char str[] = "baa";  
    permutation(str , str);  
    return 0;  
}  
