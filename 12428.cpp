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

#define fi "12428.inp"
#define fo "12428.out"
/**/
using namespace std;
/**/
long long v[100010];
long long n;
/**/
void precal()
{
    long i;
    
    v[0] = v[1] = 0;
    for(i=2;i<=100000;i++)
        v[i] = i*(i-1)/2;
}
/**/
void input()
{
    long long m;
    long i;
    int ntest;
    precal();
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%ld %lld",&n,&m);
        if(m < n)
            printf("%lld\n",m);
        else
        {
            i = 0;
            while(true)
            {
                i++;
                if(v[i] + n - i >= m)
                    break;
            }
            if(n-i < 0)
                i = n;
            printf("%lld\n",n-i);
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
