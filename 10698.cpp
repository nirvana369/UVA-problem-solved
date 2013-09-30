/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10698.inp"
#define fo "10698.out"
/**/
using namespace std;
/**/
struct fb{
            char name[100],cs[100];
            double tile;
            int score,win,lose,play,dif;
            };
fb f[1000];
map<string, int > mmap;
int n,m;
/**/
void swapfb(int x,int y)
{
    fb tmp;
    
    tmp = f[x];
    f[x] = f[y];
    f[y] = tmp;
}
/**/
bool sosanh(int x,int y)
{
    if(f[x].score != f[y].score)
        return true;
    if(f[x].win != f[y].win)
        return true;
    if(f[x].dif != f[y].dif)
        return true;
    return false;
}
/**/
void output()
{
    int i;
    bool id;
    for(i=1;i<=n;i++)
    {
        id = false;
        if(i == 1)
            id = true;
        else if(sosanh(i,i-1))
            id = true;
            
        if(id)
            printf("%2d.",i);
        else
            printf("   ");
            
        printf("%16s%4d%4d%4d%4d%4d",f[i].name,f[i].score,f[i].play,f[i].win,f[i].lose,f[i].dif);
        if(f[i].play)
            printf("%7.2lf",f[i].tile);
        else
            printf("    N/A");
        printf("\n");
    }
}
/**/
void solve()
{
    int i,j;

    for(i=1;i<=n;i++)
    {
        f[i].dif = f[i].win - f[i].lose;
        f[i].tile = (double)f[i].score / (f[i].play * 3.0) * 100.0;
    }
    
    for(i=1;i<n;i++)
        for(j=i+1;j<=n;j++)
            if(f[i].score < f[j].score)
                swapfb(i,j);
            else if(f[i].score == f[j].score)
            {
                if(f[i].dif < f[j].dif)
                    swapfb(i,j);
                else if(f[i].dif == f[j].dif)
                {
                    if(f[i].win < f[j].win)
                        swapfb(i,j);
                    else if(f[i].win == f[j].win)
                        if(strcmp(f[i].cs,f[j].cs) > 0)
                            swapfb(i,j);
                }
            }
    output();
}
/**/
void xuly(int x,char s[])
{
    int i;
    i = 0;
    while(s[i])
    {
        if(s[i] < 90)
            f[x].cs[i] = s[i] + 32;
        else
            f[x].cs[i] = s[i];
        i++;
    }
    f[x].cs[i] = 0;
}
/**/
void input()
{
    int i,j;
    int id;
    char s1[100],s2[100],s[10];
    int p1,p2,id1,id2;
    id = 0;
    while(scanf("%d %d",&n,&m))
    {
        if(!n && !m)
            break;
        if(id++)
            printf("\n");
        mmap.clear();
        for(i=1;i<=n;i++)
        {
            scanf("%s",f[i].name);
            xuly(i,f[i].name);
            mmap[f[i].name] = i;
            f[i].score = 0;
            f[i].play = 0;
            f[i].win = 0;
            f[i].lose = 0;
            f[i].dif = 0;
            f[i].tile = 0;
        }
        for(i=0;i<m;i++)
        {
            scanf("%s %d %s %d %s",&s1,&p1,&s,&p2,&s2);
            id1 = mmap[s1];
            id2 = mmap[s2];
            if(p1 > p2)
                f[id1].score += 3;
            else if(p2 > p1)
                f[id2].score += 3;
            else
            {
                f[id1].score++;
                f[id2].score++;
            }
            f[id1].play++;
            f[id2].play++;
            f[id1].win += p1;
            f[id1].lose += p2;
            f[id2].win += p2;
            f[id2].lose += p1;
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
