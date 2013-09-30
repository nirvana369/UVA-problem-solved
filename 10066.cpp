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

#define fi "10066.inp"
#define fo "10066.out"
/**/
using namespace std;
/**/
int a[110],b[110],l[110][110];
int n1,n2;
/**/
void solve()
{
    int i,j;
    int high;
    
    high = 0;
    
    i = 1;
    j = n1;
    
    while(i < j)
    {
        a[i] ^= a[j];
        a[j] ^= a[i];
        a[i] ^= a[j];
        i++;
        j--;
    }
    
    i = 1;
    j = n2;
    
    while(i < j)
    {
        b[i] ^= b[j];
        b[j] ^= b[i];
        b[i] ^= b[j];
        i++;
        j--;
    }
    
    for(i=0;i<=n1;i++)
        for(j=0;j<=n2;j++)
            l[i][j] = 0;
            
    for(i=1;i<=n1;i++)
        for(j=1;j<=n2;j++)
        {
            if(a[i] == b[j])
                l[i][j] = l[i-1][j-1] + 1;
            else
                l[i][j] = max(l[i-1][j],l[i][j-1]);
        }
    
    printf("Number of Tiles : %d\n\n",l[n1][n2]);
}
/**/
void input()
{
    int i;
    int id;
    
    id = 1;
    while(scanf("%d %d",&n1,&n2))
    {
        if(!n1 && !n2)
            break;

        for(i=1;i<=n1;i++)
            scanf("%d",&a[i]);

        for(i=1;i<=n2;i++)
            scanf("%d",&b[i]);

        printf("Twin Towers #%d\n",id++);
        solve();
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
