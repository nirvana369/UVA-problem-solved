/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <iostream>

#define fi "12028.inp"
#define fo "12028.out"
#define m 1000007
/**/
using namespace std;
/**/
priority_queue<long, vector<long >, less<long > > pq;
long a[100010];
long n;
int k,c;
/**/
long long _abs(long long val)
{
    if(val < 0)
        return -val;
    return val;
}
/**/
void input()
{
    long i,j;
    int ntest,id;
    long long sum,tong;
    scanf("%d",&ntest);
    id = 1;
    while(ntest--)
    {
        scanf("%d %d %ld %ld",&k,&c,&n,&a[0]);
        while(!pq.empty())
            pq.pop();
        tong = a[0];
        pq.push(a[0]);
        for(i=1;i<n;i++)
        {
            a[i] = (k * a[i-1] + c) % m;
            pq.push(a[i]);
            tong += a[i];
        }
        i = 0;
        while(!pq.empty())
        {
            a[i] = pq.top();
            pq.pop();
            i++;
        }
        sum = 0;
        for(i=1;i<n;i++)
        {
            tong -= a[i-1];
            sum += _abs(tong - a[i-1] * (n-i));
        }
        printf("Case %d: %lld\n",id++,sum);
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
