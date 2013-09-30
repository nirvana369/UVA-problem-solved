/*
                                                    Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "846.inp"
#define fo "846.out"
/**/
using namespace std;
/**/
void input()
{
    int dem;
    long step,x,y;
    int ntest;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%ld %ld",&x,&y);
        step = 1;
        dem = 0;
        while(x < y)
        {
            x += step;
            dem++;
            if(x >= y)
                break;
            y -= step;
            dem++;
            step++;
        }
        printf("%d\n",dem);
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
