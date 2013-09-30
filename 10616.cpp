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

#define fi "10616.inp"
#define fo "10616.out"
/**/
using namespace std;
/**/
int a[210],dm[15],m[15],divx[15];
long d[25][15];
int q,n;
/**/
void dfs(long long val,int id,int j)
{
    int i,k;
    
    if(dm[id])
    {
        k = dm[id];
        if(!val || !(val % divx[k]))
            d[divx[k]][id]++;
    }
    
    for(i=j;i<n;i++)
        dfs(val + a[i],id+1,i+1);
}
/**/
void input()
{
    int i,j;
    int id;
    id = 1;
    while(scanf("%d %d",&n,&q))
    {
        if(!n && !q)
            break;
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        ////////
        for(i=0;i<21;i++)
            divx[i] = 0;
        
        for(i=0;i<11;i++)
        {
            m[i] = 0;
            dm[i] = 0;
        }
            
        for(i=0;i<21;i++)
            for(j=0;j<11;j++)
                d[i][j] = 0;
                
        for(i=1;i<=q;i++)
        {
            scanf("%d %d",&divx[i],&m[i]);
            if(m[i] <= 10)
                dm[m[i]] = i;
            else
                dm[m[i]] = 0;
        }
            
        dfs(0,0,0);
        ///            
        printf("SET %d:\n",id);
        for(i=1;i<=q;i++)
            printf("QUERY %d: %ld\n",i,d[divx[i]][m[i]]);
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
