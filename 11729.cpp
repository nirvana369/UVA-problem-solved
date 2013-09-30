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

#define fi "11729.inp"
#define fo "11729.out"
/**/
using namespace std;
/**/
struct war{
                int bs,js;
            };
war a[1100];
int n;
/**/
void sapxep()
{
    int i,j;
    war temp;
    
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(a[i].js < a[j].js)
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
}
/**/
void input()
{
    long kq,tg;
    int id,i;
    id = 1;
    while(scanf("%d",&n))
    {
        if(!n)
            break;
        for(i=0;i<n;i++)
            scanf("%d %d",&a[i].bs,&a[i].js);
        sapxep();
        kq = 0;
        tg = 0;
        for(i=0;i<n;i++)
        {
            tg += a[i].bs;
            kq = kq > (tg + a[i].js) ? kq : (tg + a[i].js);
        }
        printf("Case %d: %ld\n",id++,kq);
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
