/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "10791.inp"
#define fo "10791.out"
/**/
using namespace std;
/**/
long long n,m;
/**/
bool chk(long long val)
{
    long i;
    long add,tmp;
    
    if(val == 1 || val == 2 || val == 3)
        return true;
    if(val % 2 == 0 || val % 3 == 0)
        return false;
    tmp = (int) sqrt(val);
    add = 2;
    
    for(i=5;i<=tmp;i+=add,add=6-add)
        if(val % i == 0)
            return false;
    return true;
}
/**/
void solve()
{
    long i;
    long tmp,val,tmpn;
    
    if(chk(n))
        printf("%lld\n",n+1);
    else
    {
        tmp = (int)sqrt(n);
        tmpn = n;
        m = 0;
        for(i=2;i<=tmp;i++)
        {
            if(n % i == 0)
            {
                val = 1;
                while(n % i == 0)
                {
                    val *= i;
                    n /= i;
                }
                m += val;
            }
            if(n == 1)
                break;
        }
        if(n != 1)
            m += n;
        if(m == tmpn)
            m += 1;
        printf("%lld\n",m);
    }
}
/**/
void input()
{
    long i;
    int id;
    id = 1;
    while(scanf("%lld",&n) && n)
    {
        printf("Case %d: ",id++);
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
