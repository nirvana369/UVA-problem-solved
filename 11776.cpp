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

#define fi "11776.inp"
#define fo "11776.out"
/**/
using namespace std;
/**/
struct khoang{
                long x,y;
            };
khoang k[1010];
/**/
void input()
{
    int i,j;
    int n,id;
    int kq,c1,c2;
    
    id = 1;
    while(scanf("%d",&n))
    {
        if(n < 0)
            break;
        for(i=0;i<n;i++)
            scanf("%ld %ld",&k[i].x,&k[i].y);
        kq = 0;
        
        for(i=0;i<n;i++)
        {
            c1 = c2 = 0;
            for(j=0;j<n;j++)
            {
                if(k[i].y >= k[j].x && k[i].y <= k[j].y)
                    c1++;
                if(k[i].x >= k[j].x && k[i].x <= k[j].y)
                    c2++;
            }
            kq = c1 > kq ? c1 : kq;
            kq = c2 > kq ? c2 : kq;
        }
        printf("Case %d: %d\n",id++,kq);
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
