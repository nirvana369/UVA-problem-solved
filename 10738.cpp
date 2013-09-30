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

#define fi "10738.inp"
#define fo "10738.out"
/**/
using namespace std;
/**/
int d[1000010],mu_n[1000010];
long nt[900000],m_n[1000010];
long dnt;
/**/
int extract(long val)
{
    long i;
    int dem,t;

    if(val == 22)
    {
        i = 0;
    }
    dem = t = 0;
    i = 0;
    while(i < dnt)
    {
        while(val % nt[i] == 0)
        {
            val /= nt[i];
            dem++;
        }
        t += dem;
        if(dem > 1)
        {
            return 0;
            dem = 0;
        }
        else
            dem = 0;
        i++;
        if(nt[i] * nt[i] > val)
            break;
    }
    if(val != 1)
        t++;
    if(t % 2 == 0)
        return 1;
    return -1;
}
void mark(long i)
{
    long j,temp;
    for(j=i*i;j<=1000000;j+=i)
        d[j] = 0;
}
/**/
void _init()
{
    long i,j;
    int temp;
    
    for(i=1;i<=1000000;i++)
        d[i] = 1;
    
    d[1] = 1;
    mu_n[1] = 1;
    m_n[1] = 1;
    
    dnt = 0;
    
    for(i=2;i<=1000000;i++)
    {
        if(d[i])
        {
            nt[dnt++] = i;
            mu_n[i] = -1;
            m_n[i] = mu_n[i] + m_n[i-1];
            
            if(i <= 1000)
                mark(i);
        }
        else
        {
            mu_n[i] = extract(i);
            m_n[i] = mu_n[i] + m_n[i-1];
        }
    }
}
/**/
void input()
{
    long n;
    _init();
    while(scanf("%ld",&n))
    {
        if(!n)
            break;
        printf("%8ld%8d%8ld\n",n,mu_n[n],m_n[n]);
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
