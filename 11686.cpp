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

#define fi "11686.inp"
#define fo "11686.out"
/**/
using namespace std;
/**/
long kq[1000010];
bool r[1000010],d[1000010];
vector<long> s1[1000010],s[1000010],p;

long n,m;
/**/
void khoitao()
{
    long i;
    for(i=1;i<=n;i++)
    {
        d[i] = r[i] = false;
        s1[i].clear();
        s[i].clear();
    }
}
/**/
void picks(long id)
{
    int i;
    if(d[id])
        return;
    d[id] = true;
    for(i=0;i<s[id].size();i++)
        if(!d[s[id][i]])
            picks(s[id][i]);
    p.push_back(id);
}
/**/
void solve()
{
    long i,j,k,x;
    bool ip;
    
    p.clear();
    for(i=1;i<=n;i++)
        if(!d[i])
            picks(i);
            
    ip = true;
    k = 1;
    for(i=p.size()-1;i>=0;i--)
    {
        x = p[i];
        if(!r[x])
        {
            for(j=0;j<s1[x].size();j++)
                if(!r[s1[x][j]])
                {
                    ip = false;
                    break;
                }
            r[x] = true;
            kq[k++] = x;
        }
        if(!ip)
            break;
    }
    if(ip)
        for(i=1;i<k;i++)
            printf("%ld\n",kq[i]);
    else
        printf("IMPOSSIBLE\n");
}
/**/
void input()
{
    long i;
    long x,y;
    while(scanf("%ld %ld",&n,&m))
    {
        if(!n && !m)
            break;
        khoitao();
        for(i=0;i<m;i++)    
        {
            scanf("%ld %ld",&x,&y);
            s[x].push_back(y);
            s1[y].push_back(x);
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
