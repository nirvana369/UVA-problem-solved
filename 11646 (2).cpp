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
    int a,b;
    float tile,l,w,r,c;
    char s[10];
    int id;
    id = 1;
    while(scanf("%d %s %d",&a,&s,&b) == 3)
    {
        c = (float)sqrt(a * a +b * b);
        l = w = 200.0;
        c += a + b;
        l = 200 / c;
        w = l * b;
        l *= a;
        if(w > l)
            printf("Case %d: %f %f\n",id++,w,l);
        else
            printf("Case %d: %f %f\n",id++,l,w);
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
