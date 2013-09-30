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
bool d[9][9];
int a[9][9],len[6],kc[1001000];
toado vt[6][66];
char s[100];
map <string, int > mmap;
queue<string > qe;
int n;
long kt,xp;
/**/
void getstr()
{
    int i,j,k;
    k = 0;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            s[k++] = a[i][j] + 48;
    s[k] = 0;
}
/**/
void getnum()
{
    int i,j,k;
    k = 0;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            d[i][j] = true;
            a[i][j] = s[k++] - 48;
        }
}
/**/
void mini_bfs(int r,int c)
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
    d[r][c] = false;
    color = a[r][c];
    
    vt[color][len[color]++] =  q[0];
    
    while(dau != cuoi)
    {
        dau++;
        for(i=0;i<4;i++)
        {
            p.x = q[dau].x + h[i].x;
            p.y = q[dau].y + h[i].y;
            if(p.x >= 0 && p.y >= 0 && p.x < n && p.y < n && d[p.x][p.y])
                if(a[p.x][p.y] == color)
                {
                    cuoi++;
                    q[cuoi] = p;
                    d[p.x][p.y] = false;
                    vt[color][len[color]++] = p;
                }
        }
    }
}
/**/
void bfs(int r,int c) // loang lay vung chinh 0 , 0
{
    int i;
    int dau,cuoi;
    toado p;
    toado q[100];
    int color;
    
    for(i=0;i<6;i++)
        len[i] = 0;
        
    dau = -1;
    cuoi = 0;
    q[0].x = r;
    q[0].y = c;
    d[r][c] = false;
    color = a[r][c];
    
    vt[color][len[color]++] =  q[0]; // luu vi tri
    
    while(dau != cuoi)
    {
        dau++;
        for(i=0;i<4;i++)
        {
            p.x = q[dau].x + h[i].x;
            p.y = q[dau].y + h[i].y;
            if(p.x >= 0 && p.y >= 0 && p.x < n && p.y < n && d[p.x][p.y])
            {
                if(a[p.x][p.y] == color)
                {
                    cuoi++;
                    q[cuoi] = p;
                    d[p.x][p.y] = false;
                    vt[color][len[color]++] = p;
                }
                else
                    mini_bfs(p.x,p.y); // loang cac vung lien quan den vung toa do 0 , 0
            }
        }
    }
}
/**/
bool chk()
{
    int i,j;
    for(i=0;i<n*n;i++)
        if(s[i] != s[0])
            return false;
    return true;
}
/**/
bool solve()
{
    int i,j;
    int color;
    
    getnum();
    bfs(0,0);
    color = a[0][0];
    for(i=0;i<6;i++)
        if(color != i && len[i] != 0)
        {
            for(j=0;j<len[color];j++)
                a[vt[color][j].x][vt[color][j].y] = i;
            
            getstr();
            j = mmap[s];
            if(!j)
            {
                kt++;
                qe.push(s);
                mmap[s] = 1;
                kc[kt] = kc[xp] + 1;
                if(chk())
                {
                    printf("%d\n",kc[kt]);    
                    return true;
                }
            }      
        }
    return false;
}
/**/
void loang()   // loang trang thai mang 2 chieu
{
    int i;
    string str;
    getstr();
    if(chk())
    {
        printf("0\n");
        return;
    }
    
    mmap.clear(); // dung map danh dau trung , lap
    while(!qe.empty())
        qe.pop();
    
    mmap[s] = 1;
    qe.push(s);
    xp = -1;
    kt = 0;
    kc[0] = 0;
    while(!qe.empty())
    {
        xp++;
        str = qe.front();
        for(i=0;i<str.length();i++)
            s[i] = str[i];
        s[i] = 0;
        qe.pop();
        if(solve())
            return;
    }
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
        loang();
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
