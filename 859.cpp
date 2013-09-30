/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <iostream>

#define fi "859.inp"
#define fo "859.out"
/**/
using namespace std;
/**/
struct toado{
                int x,y;
            };
            
class sosanh{
public:
    bool operator()(toado a,toado b){
        if(a.x < b.x)    
            return true;
            
        if(a.x == b.x)
            if(a.y > b.y)
                return true;
        return false;
    };          
};
toado h[5] = {0,1,
                1,0,
                0,-1,
                1,1,
                1,-1};
                
priority_queue<toado, vector<toado > , sosanh >   pq;
int d[110][110],kc[110][110];
toado q[10010];
int nhang,ncot,m;
toado xp;
/**/
void khoitao()
{
    int i,j;
    
    for(i=1;i<=nhang;i++)
        for(j=1;j<=ncot;j++)
            d[i][j] = 0;
}
/**/
void bfs()
{
    int i;
    int dau,cuoi;
    toado p1,p2;
    
    dau = -1;
    cuoi = 0;
    q[0] = xp;
    kc[xp.x][xp.y] = 0;
    
    while(dau != cuoi)
    {
        dau++;
        for(i=0;i<5;i++)
        {
            p1.x = q[dau].x + h[i].x;
            p1.y = q[dau].y + h[i].y;
            p2.x = p1.x + h[i].x;
            p2.y = p1.y + h[i].y;
            if(p2.x > 0 && p2.y > 0 && p2.x <= nhang && p2.y <= ncot)
                if(d[p1.x][p1.y] == 1 && !d[p2.x][p2.y])
                {
                    cuoi++;
                    q[cuoi] = p2;
                    d[p2.x][p2.y] = 2;
                    kc[p2.x][p2.y] = kc[q[dau].x][q[dau].y] + 1;
                    pq.push(p2);
                }
        }
    }
}
/**/
void solve()
{
    int i;
    toado tmp;
    
    for(i=0;i<3;i++)
    {
        tmp.x = xp.x + h[i].x;
        tmp.y = xp.y + h[i].y;
        if(tmp.x > 0 && tmp.y > 0 && tmp.x <= nhang &&  tmp.y <= ncot)
            if(!d[tmp.x][tmp.y])
            {
                d[tmp.x][tmp.y] = 2;
                kc[tmp.x][tmp.y] = 1;
                pq.push(tmp);
            }
    }
    
    bfs();
    
    while(!pq.empty())
    {
        tmp = pq.top();
        
        printf("%d %d %d\n",tmp.x,tmp.y,kc[tmp.x][tmp.y]);
        
        pq.pop();
    }
}
/**/
void input()
{
    int x,y;
    int id;
    
    id = 0;
    while(scanf("%d %d",&nhang,&ncot) == 2)
    {
        if(id++)
            printf("\n");
            
        khoitao();
        m = 4 * ncot;
        while(m--)
        {
            scanf("%d %d",&x,&y);
            d[x][y] = 1;
        }
        scanf("%d %d",&xp.x,&xp.y);
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
