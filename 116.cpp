/*
                                                        Hoang Linh
        
                                            SPFA (shortest path faster algorithm)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <iostream>

#define fi "116.inp"
#define fo "116.out"
/**/
using namespace std;
/**/
struct toado{
                int x,y;
            };
toado h[6] = {-1,1,
                0,1,
                1,1,
                -1,-1,
                0,-1,
                1,-1};
int nhang,ncot;
long long a[11][101],gt[11][101];
int trc[11][101],kq[101],luu[101];
bool d[11][101];
queue<toado > q;
long long maxgt;
/**/
void sapxep(int arr[])
{
    int i,j;
    
    for(i=0;i<3;i++)
        for(j=i+1;j<3;j++)
            if(arr[i] > arr[j])
                swap(arr[i],arr[j]);
}
/**/
void dfs(int row,int col)
{
    int i,j;
    toado t;
    int arr[3];
    
    if(col == ncot-1)
    {
        for(i=0;i<ncot;i++)
            kq[i] = luu[i];
        return;
    }
    j = 0;
    for(i=0;i<3;i++)
    {
        t.x = row + h[i].x;
        if(t.x == nhang)
            t.x = 0;
        if(t.x < 0)
            t.x = nhang-1;
        arr[j++] = t.x;
    }
    
    sapxep(arr);
    t.y = col + 1;
    for(i=0;i<3;i++)
    {
        t.x = arr[i];
        if(gt[row][col] - a[row][col] == gt[t.x][t.y] && t.x <= kq[t.y])
        {
            luu[col+1] = t.x;
            dfs(t.x,t.y);
            return;
        }
    }
}
/**/
void solve()
{
    int i;
    toado t,tmp;
    long long val;
    
    for(i=0;i<nhang;i++)
    {
        gt[i][ncot-1] = a[i][ncot-1];
        t.x = i;
        t.y = ncot-1;
        trc[i][ncot-1] = i;
        q.push(t);
    }
    
    while(!q.empty())
    {
        t = q.front();
        q.pop();
        d[t.x][t.y] = false;
        
        if(t.y == 0)
            continue;
        for(i=3;i<6;i++)
        {
            tmp.x = t.x + h[i].x;
            tmp.y = t.y + h[i].y;
            if(tmp.x == nhang)
                tmp.x = 0;
            if(tmp.x < 0)
                tmp.x = nhang - 1;

            if(gt[tmp.x][tmp.y] > gt[t.x][t.y] + a[tmp.x][tmp.y])
            {
                gt[tmp.x][tmp.y] = gt[t.x][t.y] + a[tmp.x][tmp.y];
                trc[tmp.x][tmp.y] = t.x;
                if(d[tmp.x][tmp.y])
                    q.push(tmp);
            }
            else if(gt[tmp.x][tmp.y] == gt[t.x][t.y] + a[tmp.x][tmp.y])
                if(trc[tmp.x][tmp.y] > t.x)
                    trc[tmp.x][tmp.y] = t.x;
        }
    }
    
    val = maxgt;
    for(i=0;i<nhang;i++)
        val = gt[i][0] < val ? gt[i][0] : val;
    
    for(i=0;i<ncot;i++)
        kq[i] = nhang;
    
    for(i=0;i<nhang;i++)
        if(gt[i][0] == val)
        {
            luu[0] = i;
            dfs(i,0);
            break;
        }
    
    for(i=0;i<ncot;i++)
    {
        if(i)
            printf(" ");
        printf("%d",kq[i]+1);
    }
    printf("\n%lld\n",val);
}
/**/
void input()
{
    int i,j;
    maxgt = (long long)pow(2,50);
    while(scanf("%d %d",&nhang,&ncot) == 2)
    {
        for(i=0;i<nhang;i++)
            for(j=0;j<ncot;j++)
            {
                scanf("%lld",&a[i][j]);
                d[i][j] = true;
                trc[i][j] = nhang;
                gt[i][j] = maxgt;
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
