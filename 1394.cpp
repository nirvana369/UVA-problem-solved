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

#define fi "1394.inp"
#define fo "1394.out"
/**/
using namespace std;
/**/
int d[10010];
int n,vt,k;
/**/
void donmang(int vt)
{
    int i;
    for(i=vt;i<n;i++)
        d[i] = d[i+1];
}
/**/
void khoitao()
{
    int i,j;
    for(i=1;i<=n;i++)
        d[i] = i;
    donmang(vt);
    n--;
}
/**/
void solve()
{
    while(n != 1)
    {
        vt--;
        vt += k;
        vt %= n;
        if(!vt)
            vt = n;
        donmang(vt);
        n--;
    }
    printf("%d\n",d[n]);
}
/**/
void input()
{
    while(scanf("%d %d %d",&n,&k,&vt) == 3)
    {
        if(!n && !k && !vt)
            break;
        khoitao();
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
