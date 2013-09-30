/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <queue>
#include <iostream>
#include <vector>

#define fi "10906.inp"
#define fo "10906.out"
/**/
using namespace std;
/**/
char var[110][15],bt[110][15],v1[110][15],v2[110][15];
int n;
map<string, int> mmap;
/**/
bool kiemtra(char s[])
{
    int i;
    i = 0;
    while(s[i])
    {
        if(s[i] >= '0' && s[i] <= '9')
            return false;
        i++;
    }
    if(!mmap[s])
        return false;
    return true;
}
/**/
int getsign(char s)
{
    if(s == '*')
        return 2;
    return 1;
}
/**/
void solve(int node,int id,int sign)
{
    int flg;
    flg = getsign(bt[id][0]);
    if(node % 2 != 0 && sign == flg && !kiemtra(v1[id]) || sign > flg)
        printf("(");
        
    if(kiemtra(v1[id]))    
        solve(node*2,mmap[v1[id]],flg);
    else
        printf("%s",v1[id]);
        
    printf("%s",bt[id]);
    
    if(kiemtra(v2[id]))    
        solve(node*2+1,mmap[v2[id]],flg);        
    else
        printf("%s",v2[id]);
        
    if(node % 2 != 0 && sign == flg && !kiemtra(v2[id]) || sign > flg)
        printf(")");
}
/**/
void input()
{
    int i;
    char equal[100];
    int ntest,id;
    scanf("%d",&ntest);
    id = 1;
    while(ntest--)
    {
        scanf("%d",&n);
        mmap.clear();
        for(i=1;i<=n;i++)
        {
            scanf("%s %s %s %s %s",&var[i],&equal,&v1[i],&bt[i],&v2[i]);
            mmap[var[i]] = i;
        }
        printf("Expression #%d: ",id++);
        
        solve(1,n,-1);
        printf("\n");
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
