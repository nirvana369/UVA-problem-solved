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

#define fi "11650.inp"
#define fo "11650.out"
/**/
using namespace std;
/**/
/**/
void input()
{
    int ntest;
    int h,h1,m;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d:%d",&h,&m);
        h1 = 12 - h;
        if(h1 == 0)
            h1 = 12;
        h1 *= 60;
        h1 -= m;
        h = h1 / 60;
        m = h1 % 60;
        if(h == 0)
            h = 12;
        printf("%02d:%02d\n",h,m);
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
