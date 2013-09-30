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

#define fi "12468.inp"
#define fo "12468.out"
/**/
using namespace std;
/**/
int minval(int a,int b)
{
    if(a > b)
        return b;
    return a;
}
/**/
void input()
{
    int id;
    int a,b,kq;
    while(scanf("%d %d",&a,&b) == 2)
    {
        if(a < 0 && b < 0)
            break;
        kq = a > b ? minval(a-b,100-(a-b)) : minval(b-a,100-(b-a));
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
