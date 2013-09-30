/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <iostream>

#define fi "988.inp"
#define fo "988.out"
/**/
using namespace std;
/**/
vector<int > a[30000];
int n,dem;
int d[30000];
/**/
int dq(int xp)
{
    int i;
    
    if(!xp)
        return 1;
    if(d[xp])
        return d[xp];
    
    for(i=0;i<a[xp].size();i++)
        d[xp] += dq(a[xp][i]);
    return d[xp];
}
/**/
void input()
{
    int i,j;
    int m,x;
    int id;
    
    id = 0;
    while(true)
    {
        n = -1;
        scanf("%d",&n);
        if(n < 0)
            break;
            
        for(i=0;i<n;i++)
        {
            a[i].clear();
            d[i] = 0;
        }
            
        dem = 0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&m);
            if(!m)
                dem += dq(i);
                
            for(j=0;j<m;j++)
            {
                scanf("%d",&x);
                a[x].push_back(i);
            }
        }
        if(id)
            printf("\n");
        printf("%d\n",dem);
        id++;
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
