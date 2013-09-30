/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <queue>
#include <iostream>

#define fi "562.inp"
#define fo "562.out"
/**/
using namespace std;
/**/
long long a[110];
int d[50010];
priority_queue<long long, vector<long long>, greater<long long> > pq;
int n;
long long tong;
/**/
void solve()
{
    long i,j;
    long div2,kq,maxvt;
    i = 0;
    div2 = tong / 2;
    
    while(!pq.empty())
    {
        a[i++] = pq.top();
        pq.pop();
    }
    // reset
    for(i=0;i<=50000;i++)
        d[i] = 0;
        
    d[0] = 1;
    // dcow
    for(i=0;i<n;i++)
        for(j=div2;j>=0;j--)
            if(d[j] && a[i] + j <= div2)
                d[a[i] + j] = 1;
    for(i=div2;i>=0;i--)
        if(d[i])
        {
            kq = tong - i;
            kq = i > kq ? (i-kq) : (kq-i);
            break;
        }
    printf("%ld\n",kq);
}
/**/
void input()
{
    int i;
    long long val;
    int ntest;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d",&n);
        while(!pq.empty())
            pq.pop();
        tong = 0;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&val);
            tong += val;
            pq.push(val);
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
