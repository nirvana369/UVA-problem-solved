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

#define fi "166.inp"
#define fo "166.out"
#define maxval 30000
/**/
using namespace std;
/**/
int c[6],d[510],d1[510],a[6],q[1000];
int dif;
/**/
/**/
void _init()
{
    int i,j,k;
    
    c[0] = 5;
    c[1] = 10;
    c[2] = 20;
    c[3] = 50;
    c[4] = 100;
    c[5] = 200;
    
    for(i=0;i<501;i++)
        d[i] = maxval;
        
    d[0] = 0;
    k = 0;
    for (i=0;i<6;i++)
        for (j=0;j<=k;j++)
            if(d[j] != maxval && c[i] + j <= 500)
            {
                d[c[i]+j] = min(d[c[i]+j], d[j] + 1);
                k = max(k,c[i]+j);        
            }
}
/**/
void solve(int val)
{
    int i,j,k,x;
    int ans;
    
    k = 0;
    for(i=0;i<6;i++)
        for(j=0;j<a[i];j++)
            q[k++] = c[i];
    
    for(i=0;i<501;i++)
        d1[i] = maxval;
    
    x = 0;
    d1[0] = 0;
    for(i=0;i<k;i++)
        for(j=x;j>=0;j--)
            if(d1[j] != maxval && q[i] + j <= 500)
            {
                d1[q[i] + j] = min(d1[q[i] + j],d1[j] + 1);
                x = max(x,q[i] + j);
            }
            
    ans = maxval;
    for(i=val;i<501;i++)
        ans = min(ans,d1[i] + d[i-val]);
    
    printf("%3d\n",ans);
}
/**/
void input()
{
    int i;
    int dem;
    int n1,n2;

    _init();    
    while(1)
    {
        dem = 0;
        for(i=0;i<6;i++)
        {
            scanf("%d",&a[i]);
            if(!a[i])
                dem++;
        }
        if(dem == 6)
            break;
        scanf("%d.%d",&n1,&n2);
        n1 = n1 * 100 + n2;
        solve(n1);
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
