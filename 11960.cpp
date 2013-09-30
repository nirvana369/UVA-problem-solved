/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "11960.inp"
#define fo "11960.out"
#define m 1000000
/**/
using namespace std;
/**/
bool d[m+10];
long divx[m+10];
long nt[m+10];
long dnt;
/**/
int divisor(long val)
{
    long i;
    int dval,dem;
    
    dval = 1;
    dem = 0;
    i = 0;
    while(i < dnt)
    {       
        while(val % nt[i] == 0)
        {
            val /= nt[i];
            dem++;
        }
        if(dem)
        {
            dval *= dem + 1;
            dem = 0;
        }
        i++;
        
        if(nt[i] * nt[i] > val)
            break;
    }
    
    if(val != 1)
        dval *= 2;
    return dval;
}
/**/
void _init()
{
    long i,j;
    long val,tmp,vt;
    
    for(i=1;i<=m;i++)
        d[i] = true;
    
    dnt = 0;
    
    val = 1;
    vt = 1;
    divx[1] = 1;
    for(i=2;i<=m;i++)
    {
        if(d[i])
        {
            nt[dnt++] = i;
            if(val <= 2)
            {
                vt = i;
                val = 2;
                divx[i] = i;
            }
            else
                divx[i] = vt;
            if(i <= 1000)
                for(j=i*i;j<=m;j+=i)
                    d[j] = false;
        }
        else
        {
            tmp = divisor(i);
            if(tmp >= val)
            {
                vt = i;
                val = tmp;
                divx[i] = i;
            }
            else
                divx[i] = vt;
        }
    }
}
/**/
void input()
{
    long n;
    long ntest;
    
    _init();
    scanf("%ld",&ntest);
    while(ntest--)
    {
        scanf("%ld",&n);
        printf("%ld\n",divx[n]);
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
