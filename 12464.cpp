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

#define fi "12464.inp"
#define fo "12464.out"
/**/
using namespace std;
/**/
long long tinh(long long a,long long b,int id)
{
    if(id == 0)
        return a;
    if(id == 1)
        return b;
    if(id == 2)
        return (1 + b) / a;
    if(id == 3)
        return (1 + (1 + b) / a) / b;
    if(id == 4)
        return (1 + a) / b;
}
/**/
void input()
{
    long long a,b,n,kq;
    
    while(scanf("%lld %lld %lld",&a,&b,&n))
    {
        if(!a && !b && !n)
            break;
        n %= 5;
        kq = tinh(a,b,n);
        printf("%lld\n",kq);
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
