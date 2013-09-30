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

#define fi "11646.inp"
#define fo "11646.out"
/**/
using namespace std;
/**/
void input()
{
    double tile,goc,r,w,l;
    int id;
    char s[10];
    id = 1;
    while(scanf("%lf %s %lf",&l,&s,&w) == 3)
    {
        goc = atan(w/l);
        r = sqrt(l / 2 * l / 2 + w / 2 * w / 2);
        tile = 200.0 / (l + 2 * r * goc);
        printf("Case %d: %0.10lf %0.10lf\n",id++,l*tile,w*tile);
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
