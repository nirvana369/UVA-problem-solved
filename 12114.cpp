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

#define fi "12114.inp"
#define fo "12114.out"
/**/
using namespace std;
/**/
void input()
{
    int id;
    double val1,val2;
    long b,s;
    id = 1;
    while(scanf("%ld %ld",&b,&s) == 2)
    {
        if(!b && !s)
            break;
        printf("Case %d: ",id++);
        if(!(b-1) || !b)
        {
            printf(":-\\\n");
            continue;
        }
        val1 = ((double)s/b) > 1 ? 1 : ((double)s/b);
        val2 = ((double)(s-1)/(b-1)) > 1 ? 1 : ((double)(s-1)/(b-1));
        if(val1 < val2)
            printf(":-)\n");
        else if(val1 > val2)
            printf(":-(\n");
        else
            printf(":-|\n");
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
