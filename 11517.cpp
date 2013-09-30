/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <iostream>

#define fi "11517.inp"
#define fo "11517.out"
/**/
using namespace std;
/**/
priority_queue<int, vector<int>, greater<int> > pq;
int d[10100];
int n,m,dollar;
/**/
void khoitao()
{
    int i;
    for(i=1;i<=10000;i++)
        d[i] = 0;
    d[0] = 1;
}
/**/
void solve()
{
    int i;
    
    khoitao();
    
    while(!pq.empty())
    {
        dollar = pq.top();
        pq.pop();
        for(i=10000-dollar;i>=0;i--)
            if(d[i])
            {
                if(!i)
                    d[dollar] = 1;
                else if(d[i+dollar] == 0)
                    d[i+dollar] = d[i] + 1;
                else if(d[i] + 1 < d[i+dollar])
                    d[i+dollar] = d[i] + 1;
            }
    }
    
    for(i=m;i<=10000;i++)
        if(d[i])
        {
            printf("%d %d\n",i,d[i]);
            break;
        }
}
/**/
void input()
{
    int i;
    int ntest;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d",&m);
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&dollar);
            pq.push(dollar);
        }
        solve();
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
