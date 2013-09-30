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

#define fi "11369.inp"
#define fo "11369.out"
/**/
using namespace std;
/**/
priority_queue <int, vector<int>, less <int> > pq;
/**/
void solve()
{
    int i;
    long discount;
    discount = 0;
    i = 1;
    while(!pq.empty())
    {
        if(i == 3)
        {
            discount += pq.top();
            i = 0;
        }
        pq.pop();
        i++;
    }
    printf("%ld\n",discount);
}
/**/
void input()
{
    int i;
    int ntest;
    int val,n;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&val);
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
