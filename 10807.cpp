/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
//#include <queue>
#include <vector>
//#include <map>

#define fi "10807.inp"
#define fo "10807.out"
/**/
using namespace std;
/**/
struct road{
                int x,y;
                int w;
            };
long ans;
int n,m;
int pre[30];
bool d[100];
vector<road> r;
/**/
void _init()
{
    int i;
    for(i=1;i<=n;i++)
        pre[i] = i;
}
/**/
int fpre(int v)
{
    while(v != pre[v])
        v = pre[v];
    return v;
}
/**/
void solve(long val,int id,int v)
{
    int i;
    int x,y;
    road t;
    int tmp[11];
    
    if(id == 0 && v == n && val < ans)
    {
        for(i=1;i<=n;i++)    
            tmp[i] = pre[i];
        _init();
        solve(val,id +1, 1);
        for(i=1;i<=n;i++)    
            pre[i] = tmp[i];
    }
    else if(id == 1 && v == n)
    {
        if(val < ans)
            ans = val;
        return;
    }
    
    for(i=0;i<m;i++)
    {
        if(d[i])
        {
            t = r[i];
            
            x = fpre(t.x);
            y = fpre(t.y);
            if(x != y)
            {
                d[i] = false;
                pre[y] = x;
                
                if(val + t.w < ans)
                    solve(val + t.w, id, v + 1);
                
                d[i] = true;
                pre[y] = y;
            }
        }
    }
}
/**/
void input()
{
    int i;
    road t;
    while(scanf("%d",&n) && n)
    {
        scanf("%d",&m);

        r.clear();

        for(i=0;i<m;i++)
        {
            scanf("%d %d %d",&t.x,&t.y,&t.w);
            r.push_back(t);
            d[i] = true;
        }
        ans = 1000000;
        _init();
        solve(0,0,1);
        if(ans != 1000000)
            printf("%ld\n",ans);
        else
            printf("No way!\n");
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
