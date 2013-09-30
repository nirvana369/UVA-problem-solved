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

#define fi "1230.inp"
#define fo "1230.out"
/**/
using namespace std;
/**/
int x,n;
long y;
/**/
long process(long mu)
{
    long val;
    if(mu == 1)
        return x % n;
    val = process(mu/2);
    val %= n;
    val *= val;
    val %= n;
    if(mu % 2 != 0)
    {
        val *= x;
        val %= n;
    }
    return val % n;
}
/**/
void input()
{
    int ntest;
    long kq;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d %ld %d",&x,&y,&n);
        kq = process(y);
        printf("%ld\n",kq);
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
