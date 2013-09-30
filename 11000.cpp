/*
                                                    Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "11000.inp"
#define fo "11000.out"

#define maxvalue 4294967297ll
/**/
using namespace std;
/**/
struct data{
                long long f,m;
            };
data bee[10000],t[10000];
int maxbee;
/**/
void precal()
{
    maxbee = 0;
    bee[maxbee].f = 1;
    bee[maxbee].m = 0;
    t[maxbee].f = 1;
    t[maxbee].m = 0;
    while(true)
    {
        maxbee++;
        bee[maxbee].f = bee[maxbee-1].m;
        bee[maxbee].m = bee[maxbee-1].f + bee[maxbee-1].m;
        t[maxbee].f = bee[maxbee].f + t[maxbee-1].f; ////////////
        t[maxbee].m = bee[maxbee].m + t[maxbee-1].m;
        if(maxbee == 51)
            break;
    }
}
/**/
void input()
{
    int n;
    precal();
    while(true)
    {
        scanf("%d",&n);
        if(n < 0)
            break;
        printf("%lld %lld\n",t[n].m,t[n].f+t[n].m);
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
