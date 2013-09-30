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

#define fi "11609.inp"
#define fo "11609.out"
#define maxgt 1000000007l
/**/
using namespace std;
/**/
long long way(long mu)
{
    long long temp;
    
    if(mu == 1)
        return 2;
    if(mu == 0)
        return 1;
    temp = way(mu/2);
    
    if(mu % 2 != 0)
        mu = 2;
    else
        mu = 1;
    
    return (temp * temp * mu) % maxgt;
}
/**/
void input()
{
    int ntest,id;
    long long n;
    scanf("%d",&ntest);
    id = 1;
    while(ntest--)
    {
        scanf("%lld",&n);
        n *= way(n-1);
        n %= maxgt;
        printf("Case #%d: %lld\n",id++,n);
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
