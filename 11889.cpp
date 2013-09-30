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

#define fi "11889.inp"
#define fo "11889.out"
/**/
using namespace std;
/**/
long long ucln(long long a,long long b)
{
    long long r;
    while(b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
/**/
long long bcnn(long long a,long long b)
{
    return a / ucln(a,b) * b;
}
/**/
void input()
{
    long i,moc;
    long long a,b,c,uc,temp,tg;
    long ntest;
    moc = 10000000;
    scanf("%ld",&ntest);
    while(ntest--)
    {
        scanf("%lld %lld",&a,&c);
        if(c % a != 0)
            printf("NO SOLUTION\n");
        else
        {
            tg = c/a;
            b = c/a;
            for(i=1;i<=moc;i++)
            {
                temp = tg * i;
                if(temp > moc)
                    break;
                if(bcnn(temp,a) == c)
                {
                    b = temp;
                    break;
                }
            }
            printf("%lld\n",b);
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
