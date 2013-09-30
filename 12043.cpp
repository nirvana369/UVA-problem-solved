/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "12043.inp"
#define fo "12043.out"
#define n 100001
/**/
using namespace std;
/**/
int uc[n+10];
long long s[n+10];
bool d[n+10];
/**/
void _init()
{
    long i,j;
    long tmp;
    
    for(i=0;i<n;i++)
    {
        d[i] = true;
        s[i] = 0;
        uc[i] = 2;
    }
    s[1] = 1;
    uc[1] = 1;
    
    for(i=2;i<n;i++)
    {
        if(d[i])
        {
            s[i] = i+1;
            j = 2;
            tmp = i;
            while(tmp * j < n)            
            {
                d[tmp*j] = false;
                uc[tmp*j]++;
                s[tmp*j] += i;
                j++;
            }
        }
        else
        {
            s[i] += i+1;
            j = 2;
            tmp = i;
            while(tmp * j < n)            
            {
                uc[tmp*j]++;
                s[tmp*j] += i;
                j++;
            }
        }
    }
}
/**/
void input()
{
    long i;
    long sumu,a,b;
    long long sums;
    int k;
    int ntest;
    
    _init();
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%ld %ld %d",&a,&b,&k);
        sumu = sums = 0;
        for(i=a;i<=b;i++)
            if(i % k == 0)
            {
                sumu += uc[i];
                sums += s[i];
            }
        printf("%ld %lld\n",sumu,sums);
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
