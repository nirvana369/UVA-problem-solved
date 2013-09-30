/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "11834.inp"
#define fo "11834.out"
/**/
using namespace std;
/**/
void input()
{
    double cheo,thua1,thua2,dr,tmpl,tmpw;
    int l,w,r1,r2;
    while(scanf("%d %d %d %d",&l,&w,&r1,&r2))
    {
        if(!l && !w && !r1 && !r2)
            break;
        dr = r1 + r2;
        tmpl = l - dr;
        tmpw = w - dr;
        cheo = sqrt(tmpl * tmpl + tmpw * tmpw);
        r1 = r1 > r2 ? r1 : r2;
        w = l > w ? w : l;
        if(cheo >= dr && 2 * r1 <= w)
            printf("S\n");
        else
            printf("N\n");
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
