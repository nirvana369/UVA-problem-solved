/*
                                                    Hoang Linh
                                        
                                        Problem: ANAGRAM 0.5 - 195 (anagram.*) 
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define fi "195.inp"
#define fo "195.out"
/**/
using namespace std;
/**/
char luu[100],s[100];
int d[200];
int len;
/**/
bool sosanh(char a,char b)
{
    char tempa,tempb;
    
    if(a < 97)
        tempa = a + 32;
    else
        tempa = a;
        
    if(b < 97)
        tempb = b + 32;
    else
        tempb = b;
    
    if(tempa == tempb && a > 96)
        return true;
    if(tempa > tempb)        
        return true;
    return false;
}
/**/
void sapxep()
{
    int i,j;
    char temp;
    
    for(i=0;i<len-1;i++)
        for(j=i+1;j<len;j++)
            if(sosanh(s[i],s[j]))
            {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
}
/**/
void dequy(int id)
{
    int i;
    int mark[200];
    
    if(id == len)
    {
        luu[id] = 0;
        printf("%s\n",luu);
        return;
    }
    
    for(i=65;i<123;i++)
        mark[i] = 0;
        
    for(i=0;i<len;i++)
        if(d[i] == 0 && mark[s[i]] == 0)
        {
            d[i] = 1;
            mark[s[i]] = 1;
            luu[id] = s[i];
            
            dequy(id+1);
            
            d[i] = 0;
        }
}
/**/
void khoitao()
{
    int i;
    
    for(i=0;i<len;i++)
        d[i] = 0;
}
/**/
void input()
{
    int itest;
    int ntest;
    scanf("%d",&ntest);
    gets(s);
    for(itest=0;itest<ntest;itest++)
    {
        khoitao();
        gets(s);
        len = strlen(s);
        sapxep();    
        dequy(0);
    }
}
/**/
int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    input();
    return 0;
}
