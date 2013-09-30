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

#define fi "11076.inp"
#define fo "11076.out"
/**/
using namespace std;
/**/
unsigned long long a[13],luu[13];
unsigned long long val,tong;
long gt[14];
int d[14];
int n,dl;
/**/
void solve()
{
    int i,j;
    long long tmp,giatri;

    giatri = 0;
    
    for(i=0;i<dl;i++)
    {
        tmp = gt[n-1];
        for(j=0;j<dl;j++)
            if(i != j)
                tmp /= gt[d[j]];
            else if(d[j] > 1)
                tmp /= gt[d[j] - 1];
        giatri += luu[i] * tmp;
    }
    
    val = 0;
    for(i=0;i<n;i++)   
    {
        val *= 10;
        val += giatri;
    }
    
    printf("%llu\n",val);
}
/**/
void _init()
{
    int i;
    gt[0] = 1;
    gt[1] = 1;
    for(i=2;i<13;i++)
        gt[i] = i * gt[i-1];
}
/**/
void input()
{
    int i,j;
    _init();
    while(scanf("%d",&n))
    {
        if(!n)
            break;
        dl = 0;
        tong = 0;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
            for(j=0;j<dl;j++)
                if(a[i] == luu[j])
                {
                    d[j]++;
                    break;
                }
            if(j == dl)
            {
                d[dl] = 1;
                luu[dl++] = a[i];
                tong += a[i];
            }
        }
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
