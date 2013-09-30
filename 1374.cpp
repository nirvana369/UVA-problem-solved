/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "1374.inp"
#define fo "1374.out"
/**/
using namespace std;
/**/
int bac,n;
int x[1000];
/**/
bool laybac()
{
    int val;
    
    bac = 0;
    val = 1;
    
    while(val < n)
    {
        val *= 2;
        bac++;
    }
    if(val == n)
        return true;
    bac+=4;
    return false;
}
/**/
bool kiemtra(int value,int b)
{
    int i;
    if(value == n)
        return true;
    for(i=0;i<b;i++)
    {
        value = value * 2;
        if(value >= n)
            return true;
    }
    return false;
}
/**/
void dq(int id,int b)
{
    int i;
    if(x[id] == n)
    {
        if(b < bac)
            bac = b;
        return;
    }
        
    if(kiemtra(x[id]*2,bac-b))
    {
        x[id+1] = x[id] * 2 ;
        dq(id+1,b+1);
    }
    for(i=id-1;i>=0;i--)
    {
        if(kiemtra(x[id] - x[i],bac-b))
        {
            x[id+1] = x[id] - x[i];
            dq(id+1,b+1);
        }
    }
}
/**/
void input()
{
    while(scanf("%d",&n) && n)
    {
        bac = laybac();
        if(laybac())
            printf("%d\n",bac);
        else
        {
            x[0] = 1;
            dq(0,0);
            printf("%d\n",bac);
        }
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
