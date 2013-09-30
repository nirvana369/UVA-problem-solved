/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <vector>
#include <iostream>

#define fi "1148.inp"
#define fo "1148.out"
/**/
using namespace std;
/**/
vector<long > a[100100];
queue<long > q;
bool d[100100];
long nhan[100100];
long n;
/**/
void solve()
{
    long io,i;
    long xp,kt;
    
    while(!q.empty())
        q.pop();
    scanf("%ld %ld",&xp,&kt);
    nhan[xp] = 0;
    q.push(xp);
    
    while(!q.empty()) // shortest path faster algorithm :v :v dijsktra update :v
    {
        io = q.front();
        q.pop();
        if(io == kt)
            break;
        
        d[io] = false;
        for(i=0;i<a[io].size();i++)
            if(nhan[io] + 1 < nhan[a[io][i]])
            {
                nhan[a[io][i]] = nhan[io] + 1;
                if(d[a[io][i]])
                    q.push(a[io][i]);
            }
    }
    printf("%ld %ld %ld\n",xp,kt,nhan[kt]-1);
}
/**/
void input()
{
    long i,j;
    long m,x,y;
    int ntest;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%ld",&n);
        for(i=0;i<n;i++)
        {
            d[i] = true;
            nhan[i] = 32000;
            
            scanf("%ld %ld",&x,&m);
            a[x].clear();
            for(j=0;j<m;j++)
            {
                scanf("%ld",&y);
                a[x].push_back(y);
            }
        }
        solve();
        if(ntest)
            printf("\n");
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
