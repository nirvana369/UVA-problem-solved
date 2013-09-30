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

#define fi "413.inp"
#define fo "413.out"
/**/
using namespace std;
/**/
int da;
long long a[40];
/**/
void solve()
{
    int i;
    int giam,tang;
    int dtang,dgiam,dbang;
    int ftang,fgiam;
    double kqtang,kqgiam;
    
    ftang = fgiam = 0;
    giam = tang = 0;
    dtang = dgiam = dbang = 0;
    for(i=0;i<da-1;i++)
    {
        if(a[i] > a[i+1])
        {
            if(!giam)
                fgiam++;
            dgiam += dbang;
            dbang = 0;
            giam = 1;
            tang = 0;
        }
        if(a[i] < a[i+1])
        {
            if(!tang)
                ftang++;
            dtang += dbang;
            dbang = 0;
            tang = 1;
            giam = 0;
        }
        if(giam)        
            dgiam++;
        else if(tang)
            dtang++;
        else
            dbang++;
    }
    if(!dtang || !ftang)
        kqtang = 0;
    else
        kqtang = (double)dtang / ftang;
    
    if(!dgiam || !fgiam)
        kqgiam = 0;
    else
        kqgiam = (double)dgiam / fgiam;
    printf("Nr values = %d:  %0.6lf %0.6lf\n",da,kqtang,kqgiam);
}
/**/
void input()
{
    while(true)
    {
        da = 0;
        scanf("%lld",&a[da]);
        if(!a[da])
            break;
        while(a[da] != 0)
        {
            da++;
            scanf("%lld",&a[da]);
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
