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

#define fi "10702.inp"
#define fo "10702.out"
/**/
using namespace std;
/**/
long long earn[210][110],a[110][110];
int end[110];
int n,nend,ngo,start;
/**/
void solve(int x)
{
    int i,j,k;
    
    for(i=1;i<=n;i++)
        earn[1][i] = a[start][i];

    k = 2;
    
    while(k <= x)
    {
        for(i=1;i<=n;i++)
        {
            earn[k][i] = 0;
            for(j=1;j<=n;j++)
                if(i != j)
                    earn[k][i] = max(earn[k][i],earn[k-1][j] + a[j][i]);
        }
        k++;
    }
   /* for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            printf("%d ",earn[i][j]);
        printf("\n");
    }*/
}
/**/
void output()
{
    int i,j;
    long long maxe,ans,tmp;
    int id;
    
    maxe = 0;
    ans = 0;
    
    for(i=1;i<=n;i++)
        earn[1][i] = a[start][i];
        
    if(ngo / n > 1)    
    {
        tmp = 0;
        for(i=1;i<=n;i++)
            tmp = max(tmp,earn[n][i]);
        
        ans = tmp * (ngo / n - 1);
    }
    
    if(ngo < n * 2)
        id = ngo;
    else
        id = ngo % n + n;
        
    maxe = 0;
    for(i=0;i<nend;i++)
    {
        tmp = 0;
        for(j=1;j<=n;j++)
            if(end[i] != j)
                tmp = max(tmp,earn[id-1][j] + a[j][end[i]]);
        maxe = max(maxe,tmp);
    }

    ans += maxe;
    printf("%lld\n",ans);
}
/**/
void input()
{
    int i,j;
    
    while(scanf("%d %d %d %d",&n,&start,&nend,&ngo))
    {
        if(!n && !start && !nend && !ngo)
            break;
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                scanf("%lld",&a[i][j]);
                
        for(i=0;i<nend;i++)
            scanf("%d",&end[i]);
        solve(ngo % n + n);
        output();
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
