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

#define fi "985.inp"
#define fo "985.out"
/**/
using namespace std;
/**/
struct toado{
                int x,y;
            };
toado h[5] = {0,0,
                -1,0,
                0,1,
                1,0,
                0,-1};
vector<int > a[510][510];
bool d[505][505][5];
int tt[1100000];
long kc[1100000];
queue<toado > q;
int nhang,ncot;
/**/
int solve()
{
    toado p,t;
    long dau,cuoi;
    int i,k;
    int huong;
    
    while(!q.empty())
        q.pop();
    t.x = 0;
    t.y = 0;
    kc[0] = 0;
    q.push(t);
    dau = -1;
    cuoi = 0;
    tt[0] = 0;
    while(!q.empty())
    {
        dau++;
        t = q.front();
        q.pop();
        huong = (tt[dau] + 1) % 4; // huong di , trang thai mui ten o vi tri hien tai
        
        if(d[t.x][t.y][huong])
        {
            d[t.x][t.y][huong] = false;
            for(i=0;i<a[t.x][t.y].size();i++)
            {
                k = (a[t.x][t.y][i] + kc[dau]) % 4;
    
                if(!k)
                    k = 4;
    
                p.x = t.x + h[k].x;
                p.y = t.y + h[k].y;
                if(p.x >= 0 && p.x < nhang && p.y >= 0 && p.y < ncot)
                {
                    cuoi++;
                    q.push(p);
                    kc[cuoi] = kc[dau] + 1;
                    tt[cuoi] = huong;
                    if(p.x == nhang-1 && p.y == ncot-1)
                        return kc[cuoi];
                }
            }
        }
    }
    return -1;
}
/**/
void input()
{
    int i,j,k;
    long kq;
    int dir[100];
    char s[1000];
    
    dir['N'] = 1;
    dir['E'] = 2;
    dir['S'] = 3;
    dir['W'] = 4;
    
    while(scanf("%d %d",&nhang,&ncot) == 2)
    {
        for(i=0;i<nhang;i++)    
            for(j=0;j<ncot;j++)
            {
                if(i == nhang-1 && j == ncot-1)
                    break;
                    
                for(k=0;k<4;k++)
                    d[i][j][k] = true;
                    
                a[i][j].clear();
                scanf("%s",&s);
                k = 0;
                while(s[k])
                    a[i][j].push_back(dir[s[k++]]);
            }
        kq = solve();
        if(kq == -1)
            printf("no path to exit\n");
        else
            printf("%d\n",kq);
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
