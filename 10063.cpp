/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
//#include <queue>
//#include <vector>
//#include <map>

#define fi "10063.inp"
#define fo "10063.out"
/**/
using namespace std;
/**/
int len;
char s[12],s1[12];
/**/
void dfs(int id)
{
    int i;
    
    if(id == len)
    {
        s1[len] = 0;
        printf("%s\n",s1);
        return;
    }
    
    for(i=id;i>0;i--) 
        s1[i] = s1[i-1];
    
    for(i=0;i<=id;i++)
    {
        s1[i] = s[id];  
        dfs(id+1);
        s1[i] = s1[i+1];
    }
}
/**/
void input()
{
    bool fst;
    fst = true;
    
    while(scanf("%s",&s) == 1)
    {
        if(fst)    
            fst = false;
        else
            printf("\n");
        len = strlen(s);
        dfs(0);
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
