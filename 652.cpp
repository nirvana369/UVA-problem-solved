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

#define fi "652.inp"
#define fo "652.out"
/**/
using namespace std;
/**/
struct toado{
                int x,y;
            };
struct eight{
                char str[10];
                int pos;
            };
toado h[4] = {-1,0,
                0,1,
                1,0,
                0,-1};
map<string, long > mmap;
queue<eight > q;
char a[1000];
char dir[5];
int mov[1000000];
long trc[1000000];
int vt;
/**/
void swappos(int i,int j,char s[])
{
    char tmp;
    
    tmp = s[i];
    s[i] = s[j];
    s[j] = tmp;
}
/**/
void output(long vitri)
{
    if(strcmp(a,"12345678x") != 0)
        while(vitri != 0)
        {
            printf("%c",dir[mov[vitri]]);
            vitri = trc[vitri];
        }
    printf("\n");
}
/**/
void solve()
{
    int i;
    long dau,cuoi;
    eight tmp,t;
    int r,c,tg;
    toado p;
    
    while(!q.empty())
        q.pop();
    mmap.clear();  
    
    strcpy(tmp.str,a);
    tmp.pos = vt;
    mmap[a] = 1;
    q.push(tmp);
    dau = -1;
    cuoi = 0;
    while(!q.empty())
    {
        dau++;
        tmp = q.front();
        q.pop();
        r = tmp.pos / 3;
        c = tmp.pos % 3;
        for(i=0;i<4;i++)
        {
            p.x = r + h[i].x;
            p.y = c + h[i].y;
            if(p.x >= 0 && p.y >= 0 && p.x < 3 && p.y < 3)
            {
                tg = p.x * 3 + p.y;
                swappos(tg,tmp.pos,tmp.str);
                if(!mmap[tmp.str])
                {
                    cuoi++;
                    trc[cuoi] = dau;
                    mmap[tmp.str] = cuoi;
                    mov[cuoi] = i;
                    strcpy(t.str,tmp.str);
                    t.pos = tg;
                    q.push(t);                    
                }
                swappos(tg,tmp.pos,tmp.str);
            }
        }
    }
}
/**/
void _init()
{
    dir[0] = 'd';
    dir[1] = 'l';
    dir[2] = 'u';
    dir[3] = 'r';
    
    strcpy(a,"12345678x");
    vt = 8;
    solve();
}
void input()
{
    int i,j,k;
    int ntest;
    long tmp;
    
    _init();

    scanf("%d",&ntest);
    gets(a);
    while(ntest--)
    {
        gets(a);
        gets(a);
        i = 0;
        j = 0;
        while(a[i])
        {
            if(a[i] != ' ')
            {
                if(a[i] == 'x')
                    vt = j;
                a[j++] = a[i];
            }
            i++;
        }
        a[j] = 0;
        tmp = mmap[a];
        if(tmp)    
            output(tmp);
        else
            printf("unsolvable\n");
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
