/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10292.inp"
#define fo "10292.out"
/**/
using namespace std;
/**/
int a[40000],b[40000];
int da,db,n,k;
/**/
int ucln(int ga,int gb)
{
    int r;
    while(gb != 0)
    {
        r = ga % gb;
        ga = gb;
        gb = r;
    }
    return ga;
}
/**/
void solve()
{
    char kq[100000];
    int i,j;
    double va,vb;
    int temp,l;
    
    va = vb = 1;
    for(i=0;i<da;i++)
    {
        for(j=0;j<db;j++)
        {
            temp = ucln(a[i],b[j]);
            if(temp != 1)
            {
                a[i] /= temp;
                b[j] /= temp;
            }
        }
        va *= a[i];
    }
    for(i=0;i<vb;i++)
        vb *= b[i];
    va /= vb;
    sprintf(kq,"%lf",va);
    l = strlen(kq);
    for(i=0;i<l;i++)
        if(kq[i] == '.')
            break;
    printf("%d\n",i);
}
/**/
void input()
{
    int i,maxgt,mingt;
    while(true)
    {
        n = k = 0;
        scanf("%d %d",&n,&k);
        if(!n && !k)
            break;
        if(n-k > k)
        {
            maxgt = n-k;
            mingt = k;
        }
        else
        {
            maxgt = k;
            mingt = n-k;
        }
        da = db = 0;
        for(i=maxgt+1;i<=n;i++)
            a[da++] = i;
        for(i=2;i<=mingt;i++)
            b[db++] = i;
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
