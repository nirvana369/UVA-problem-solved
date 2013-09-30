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

#define fi "12463.inp"
#define fo "12463.out"
/**/
using namespace std;
/**/
/**/
void input()
{
    long a,b,c,d,e,kq;
    while(scanf("%ld %ld %ld %ld %ld",&a,&b,&c,&d,&e) == 5)
    {
        if(!a)
            break;
        kq = a * b * c * d * d * e * e;
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
