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

#define fi "11292.inp"
#define fo "11292.out"
/**/
using namespace std;
/**/
priority_queue <long, vector<long>, greater <long> > kng,head;
/**/
void solve()
{
    long dh,kh;
    long coin;
    coin = 0;
    while(!head.empty() && !kng.empty())
    {
        dh = head.top();
        kh = kng.top();
        if(dh > kh)
            kng.pop();
        else
        {
            coin += kh;
            kng.pop();
            head.pop();
        }
    }
    if(!head.empty())
        printf("Loowater is doomed!\n");
    else
        printf("%ld\n",coin);
}
/**/
void input()
{
    int i;
    int n,m;
    long h;
    
    while(scanf("%d %d",&n,&m))
    {
        if(!n && !m)
            break;
        while(!head.empty())
            head.pop();
        while(!kng.empty())
            kng.pop();
            
        for(i=0;i<n;i++)
        {
            scanf("%ld",&h);
            head.push(h);
        }
        for(i=0;i<m;i++)
        {
            scanf("%ld",&h);
            kng.push(h);
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
