/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "11207.inp"
#define fo "11207.out"
/**/
using namespace std;
/**/
void input()
{
    int i,id;
    int n;
    double x,y,tmp,sizeb;
    
    while(scanf("%d",&n) && n)
    {
        sizeb = 0;
        id = 0;
        for(i=1;i<=n;i++)
        {
            scanf("%lf %lf",&x,&y);
            tmp = max(max(min(x,y/4),min(y,x/4)),min(x,y)/2);
            if(tmp > sizeb)
            {
                sizeb = tmp;
                id = i;
            }
        }
        printf("%d\n",id);
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
