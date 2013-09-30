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

#define fi "11614.inp"
#define fo "11614.out"
/**/
using namespace std;
/**/
void input()
{
    int ntest;
    long long n,temp,delta;
    double gt,tg;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%lld",&n);
        delta = (long long)sqrt(1 + 2 * n);
        delta++;
        temp = delta/2;
        gt = (double)temp;
        gt *= (delta+1);
        tg = (double)n;
        while(gt > tg)
        {
            delta--;
            temp = delta/2;
            gt = (double)temp;
            gt *= (delta+1);
            if(delta % 2 != 0)
                gt += temp+1;
        }
        printf("%lld\n",delta);
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
