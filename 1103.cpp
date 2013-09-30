/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <iostream>

#define fi "1103.inp"
#define fo "1103.out"
/**/
using namespace std;
/**/
struct toado{
                int x,y;
            };
toado dir[4] = {-1,0,
                0,1,
                1,0,
                0,-1};
bool d[300][300];
priority_queue<char,vector<char >,greater<char> > pq;
char bin[17][5],a[300][300],s[300][100],mes[10];
int h[200];
int nhang,ncot;
/**/
void conv(char s1[],int val)
{
    int i,j;
    i = 0;
    char tmp[100];
    
    while(val != 0)
    {
        tmp[i++] = val % 2 + 48;
        val /= 2;
    }
    for(j=0;j<4-i;j++)
        s1[j] = '0';
    i--;
    while(i>=0)
        s1[j++] = tmp[i--];
    s1[j] = 0;
}
/**/
void _init()
{
    int i,j;
    
    for(i=0;i<16;i++)
        conv(bin[i],i);

    for(i='0',j=0;i<='9';i++,j++)
        h[i] = j;
    for(i='a';i<='f';i++,j++)
        h[i] = j;
    mes[0] = 'W';
    mes[1] = 'A';
    mes[2] = 'K';
    mes[3] = 'J';
    mes[4] = 'S';
    mes[5] = 'D';
}
/**/
void xuly()
{
    int i,j,j1,k;
    int x;
    
    for(i=0;i<nhang;i++)
    {
        j1 = 0;
        for(j=0;j<ncot;j++)
        {
            x = h[s[i][j]];
            k = 0;
            while(bin[x][k])
            {
                d[i][j1] = true;
                a[i][j1++] = bin[x][k++];
            }
        }    
        a[i][j1] = 0;
    }
    ncot *= 4;
}
/**/
void loang0(int r,int c)
{
    int i;
    long dau,cuoi;
    toado p;
    toado q[90000];
    
    dau = -1;
    cuoi = 0;
    q[0].x = r;
    q[0].y = c;
    
    d[r][c] = false;
    
    while(dau != cuoi)
    {
        dau++;
        for(i=0;i<4;i++)
        {
            p.x = q[dau].x + dir[i].x;
            p.y = q[dau].y + dir[i].y;
            if(p.x >= 0 && p.x < nhang && p.y >= 0 && p.y < ncot && d[p.x][p.y])
                if(a[p.x][p.y] == '0')
                {
                    cuoi++;
                    d[p.x][p.y] = false;
                    q[cuoi] = p;
                }
        }
    }
}
/**/
/**/
int loang1(int r,int c)
{
    int i;
    long dau,cuoi;
    toado p;
    int dem;
    toado q[90000];
    
    dau = -1;
    cuoi = 0;
    q[0].x = r;
    q[0].y = c;
    d[r][c] = false;
    dem = 0;
    
    while(dau != cuoi)
    {
        dau++;
        for(i=0;i<4;i++)
        {
            p.x = q[dau].x + dir[i].x;
            p.y = q[dau].y + dir[i].y;
            if(p.x >= 0 && p.x < nhang && p.y >= 0 && p.y < ncot && d[p.x][p.y])
            {
                if(a[p.x][p.y] == '1')
                {
                    cuoi++;
                    d[p.x][p.y] = false;
                    q[cuoi] = p;
                }
                else
                {
                    dem++;
                    loang0(p.x,p.y);
                }
            }
        }
    }
    return dem;
}
/**/
void sapxep(char str[],int c)
{
    int i,j;
    char tmp;
    
    for(i=0;i<c;i++)
        for(j=i+1;j<c;j++)
            if(str[i] > str[j])
            {
                tmp = str[i];
                str[i] = str[j];
                str[j] = tmp;
            }
}
/**/
void solve()
{
    int i,j,k;
    bool phubi;
    
    phubi = false;
    
    for(i=0;i<nhang;i++)
    {
        if(a[i][0] == '0' && d[i][0])
        {
            phubi = true;
            loang0(i,0);
        }
        if(a[i][ncot-1] == '0' && d[i][ncot-1])
        {
            phubi = true;
            loang0(i,ncot-1);
        }
    }
        
    for(i=0;i<ncot;i++)
    {
        if(a[0][i] == '0' && d[0][i])
        {
            phubi = true;
            loang0(0,i);
        }
        if(a[nhang-1][i] == '0' && d[nhang-1][i])
        {
            phubi = true;
            loang0(nhang-1,i);
        }
    }
    
    while(!pq.empty())
        pq.pop();
    
    if(!phubi)
        pq.push('A');
    else
    {
        for(i=0;i<nhang;i++)
            for(j=0;j<ncot;j++)
                if(d[i][j] && a[i][j] == '1')
                    pq.push(mes[loang1(i,j)]);
    }
    
    while(!pq.empty())
    {
        cout << pq.top();
        pq.pop();
    }
    printf("\n");
}
/**/
void input()
{
    int i;
    int id = 1;
    _init();
    while(scanf("%d %d",&nhang,&ncot))
    {
        if(!nhang && !ncot)
            break;
        for(i=0;i<nhang;i++)
            scanf("%s",&s[i]);
        xuly();
        printf("Case %d: ",id++);
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
