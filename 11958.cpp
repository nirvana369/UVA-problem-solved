/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "11958.inp"
#define fo "11958.out"
/**/
using namespace std;
/**/
void input()
{
    int i;
    int ntest,id,n;
    int maxm,h,m,t,tmp,xmin,ymin;
    
    id = 1;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d %d:%d",&n,&h,&m);
        xmin = h*60+m;
        maxm = 30000;
        for(i=0;i<n;i++)
        {
            scanf("%d:%d %d",&h,&m,&t);
            ymin = h*60+m;
            if(ymin < xmin)
                ymin += 1440;
            tmp = ymin + t;
            if(tmp - xmin < maxm)
                maxm = tmp - xmin;
        }
        printf("Case %d: %d\n",id++,maxm);
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
