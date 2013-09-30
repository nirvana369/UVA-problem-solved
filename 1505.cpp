/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <iostream>

#define fi "1505.inp"
#define fo "1505.out"
/**/
using namespace std;
/**/
struct toado{
                int x,y;
            };
toado h[4] = {-1,0,
                0,1,
                1,0,
                0,-1};
int a[9][9];
int n,minstep;
/**/
void mini_bfs(int r,int c,bool d1[9][9],int a1[9][9],vector<toado > &vt)
{
    int i;
    int dau,cuoi;
    toado p;
    toado q[100];
    int color;
    
    dau = -1;
    cuoi = 0;
    q[0].x = r;
    q[0].y = c;
    d1[r][c] = false;
    color = a1[r][c];
    
    vt[color].push_back(q[0]);
    
    while(dau != cuoi)
    {
        dau++;
        for(i=0;i<4;i++)
        {
            p.x = q[dau].x + h[i].x;
            p.y = q[dau].y + h[i].y;
            if(p.x >= 0 && p.y >= 0 && p.x < n && p.y < n && d1[p.x][p.y])
                if(a1[p.x][p.y] == color)
                {
                    cuoi++;
                    q[cuoi] = p;
                    d1[p.x][p.y] = false;
                    vt[color].push_back(p);
                }
        }
    }
}
/**/
void bfs(int r,int c,bool d1[9][9],int a1[9][9],vector<toado > &vt) // loang lay vung chinh 0 , 0
{
    int i,j;
    toado p;
    int color;
    
    color = a1[r][c];
    
    for(i=0;i<4;i++)
    {
        p.x = r + h[i].x;
        p.y = r + h[i].y;
        if(p.x >= 0 && p.y >= 0 && p.x < n && p.y < n && d1[p.x][p.y])
        {
            if(a1[p.x][p.y] != color)
                mini_bfs(p.x,p.y,d1,a1,vt); // loang cac vung lien quan den vung toa do 0 , 0
        }
    }
}
/**/
bool chk()
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        if(a[0][0] != a[i][j])
            return false;
    return true;
}
/**/
void output(int a1[9][9])
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
    printf("\n");
}
/**/
void dfs(int step,bool d1[9][9],int a1[9][9],vector<toado > &vt)
{
    int i,j;
    int color;
    vector<toado > tmp[6];
    
    if(chk())
    {
        //output(a1);
        if(step < minstep)
            minstep = step;
        return;
    }
    if(step >= minstep)
        return;
        
    for(i=0;i<6;i++)
    {
        tmp[i].clear();
        tmp[i] = vt[i];
    }
    //output(a1);
    color = a1[0][0];
    tmp[color].clear();
    
    for(i=0;i<6;i++)
        if(color != i && vt[i].size() != 0)
        {
            for(j=0;j<vt[color].size();j++)
            {
                a1[vt[color][j].x][vt[color][j].y] = i;
                tmp[i].push_back(vt[color][j]);
            }
            
            for(j=0;j<vt[i].size();j++)
                d1[vt[i][j].x][vt[i][j].y] = false;
                
            for(j=0;j<vt[i].size();j++)
                bfs(vt[i][j].x,vt[i][j].y,d1,a1,tmp);
                
            dfs(step+1,d1,a1,vt);
            
            tmp[i] = vt[i];
            
            for(j=0;j<vt[i].size();j++)
                d1[vt[i][j].x][vt[i][j].y] = true;
        }
        
    for(j=0;j<len[color];j++)
        a1[vt[color][j].x][vt[color][j].y] = color;
}
/**/
void solve()
{
    int i;
    vector<toado > vt[6];
    
    for(i=0;i<6;i++)
        vt[i].clear();
        
    minstep = 30000;
    mini_bfs(0,0,d,a,vt);
    color = a[0][0];
    
    for(i=0;i<a[color].size();i++)
        bfs(a[color][i].x,a[color][i].y,d,a,vt);
        
    dfs(0,d,a,vt);
    printf("%d\n",minstep);
}
/**/
void input()
{
    int i,j;
    
    while(scanf("%d",&n) && n)
    {
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            {
                d[i][j] = true;
                scanf("%d",&a[i][j]);
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
