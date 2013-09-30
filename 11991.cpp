/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <vector>

#define fi "11991.inp"
#define fo "11991.out"
/**/
using namespace std;
/**/
vector<long> a[1000010];
int d[1000010];
long xh,kq,val;
long n,m;
/**/
void resetd()
{
    long i;
    for(i=0;i<=1000000;i++)
        d[i] = 0;
}
/**/
void input()
{
    long i;
    while(scanf("%ld %ld",&n,&m) == 2)
    {
        resetd();
        for(i=1;i<=n;i++)
        {
            scanf("%ld",&val);
            if(!d[val])
            {
                d[val] = 1;
                a[val].clear();
                a[val].push_back(i);
            }
            else
                a[val].push_back(i);
        }
        for(i=0;i<m;i++)
        {
            scanf("%ld %ld",&xh,&val);
            if(!d[val] || a[val].size() == 0)
                printf("0\n");
            else
            {
                kq = 0;
                if(xh <= a[val].size())
                    kq = a[val][xh-1];
                printf("%ld\n",kq);
            }
        }
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
