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

#define fi "10015.inp"
#define fo "10015.out"
/**/
using namespace std;
/**/
int d[4000];
int nt[4000];
int dnt;
int n;
/**/
bool isnt(long value)
{
    long i;
    long add,temp;
    
    if(value % 2 == 0 || value % 3 == 0)
        return false;
    add = 2;
    temp = (long)sqrt(value);
    for(i=5;i<=temp;i+=add,add=6-add)
        if(value % i == 0)
            return false;
    return true;
}
/**/
void precal()
{
    long i;
    nt[0] = 2;
    nt[1] = 3;
    dnt = 2;
    for(i=4;i<=33000;i++)
    {
        if(isnt(i))
            nt[dnt++] = i;
        if(dnt == 3502)
            break;
    }
}
/**/
void khoitao()
{
    long i;
    for(i=1;i<=n;i++)
        d[i] = i;
}
/**/
void donmang(long vt,long k)
{
    long i;
    for(i=vt;i<k;i++)
        d[i] = d[i+1];
}
/**/
void solve()
{
    long i,j;
    long dn;
    long temp;
    dn = n;
    j = 0;
    i = 1;
    while(dn != 1)
    {
        temp = i + nt[j] - 1;
        while(temp > dn)
            temp -= dn;
        donmang(temp,dn);
        dn--;
        i = temp;
        if(temp > dn)   
            temp = dn;
        if(dn == 1)
            break;
        j++;
    }
    printf("%d\n",d[dn]);
}
/**/
void input()
{
    precal();
    while(true)
    {
        scanf("%d",&n);
        if(!n)
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
