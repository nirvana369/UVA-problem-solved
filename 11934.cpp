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

#define fi "11934.inp"
#define fo "11934.out"
/**/
using namespace std;
/**/
int a,b,c;
long d;
/**/
bool magicf(int x)
{
    long long val;
    val = a * x * x + b * x + c;
    if(val % d == 0)
        return true;
    return false;
}
/**/
void input()
{
    int i;
    int kq,l;
    while(scanf("%d %d %d %ld %d",&a,&b,&c,&d,&l))
    {
        if(!a && !b && !c && !d && !l)
            break;
        kq = 0;
        for(i=0;i<=l;i++)
            if(magicf(i))
                kq++;
        printf("%d\n",kq);
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
