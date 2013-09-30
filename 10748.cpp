/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <iostream>

#define fi "10748.inp"
#define fo "10748.out"
/**/
using namespace std;
/**/
struct toado{
                long x,y;
                int st;
            };
            
toado h[8] = {-2,1,0,
                -2,-1,0,
                1,2,0,
                -1,2,0,
                2,-1,0,
                2,1,0,
                1,-2,0,
                -1,-2,0};
toado k[32];
map<string, int > mmap;
vector<int > kc;
queue<toado > q;
long dem;
int n;
/**/
void khoitao()
{
    dem = 0;
    mmap.clear();
}
/**/
bool chk(long a,long b)
{
    int i,j;
    char tmp[1000];
    char t1[100],t2[100];
    sprintf(t1,"%ld",a);
    sprintf(t2,"%ld",b);
    
    i = 0;
    j = 0;
    while(t1[j])    
        tmp[i++] = t1[j++];
    tmp[i++] = '.';
    j = 0;
    while(t2[j])    
        tmp[i++] = t2[j++];
    tmp[i] = 0;
    if(mmap[tmp])
        return false;
    dem++;
    mmap[tmp] = 1;
    return true;
}
/**/
void loang(long x,long y,int step)
{
    int i;
    toado p,tmp;
    
    p.x = x;
    p.y = y;
    p.st = 0;
    q.push(p);
    
    while(!q.empty())
    {
        tmp = q.front();
        q.pop();
        if(tmp.st < step)
            for(i=0;i<8;i++)
            {
                p.x = tmp.x + h[i].x;
                p.y = tmp.y + h[i].y;
                chk(p.x,p.y);
                p.st = tmp.st + 1;
                q.push(p);
            }
    }
}
/**/
void solve()
{
    int i;
    
    for(i=0;i<n;i++)
        loang(k[i].x,k[i].y,k[i].st);
}
/**/
void input()
{
    int i;
    while(scanf("%d",&n) && n)
    {
        khoitao();
        for(i=0;i<n;i++)
        {
            scanf("%ld %ld %d",&k[i].x,&k[i].y,&k[i].st);
            chk(k[i].x,k[i].y);
        }
        solve();
        printf("%ld\n",dem);
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
