/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <iostream>

#define fi "10923.inp"
#define fo "10923.out"
#define nhang 9
#define ncot 8
/**/
using namespace std;
/**/
struct toado{
                int x,y;
            };
            
toado h[8] = {-1,0,
                -1,1,
                0,1,
                1,1,
                1,0,
                1,-1,
                0,-1,
                -1,-1};
                
vector<pair<int, int> > vt,e,en[1000];
bool d[10][10][100],rock[10][10];
int kc[1000];
char a[10][10];
toado q[1000];
toado p;
bool batduoc;
/**/
void xuly(int hang,char s[])
{
    int i;
    
    for(i=0;i<ncot;i++)
    {
        //d[hang][i] = true;
        if(s[i] == '#')
            rock[hang][i] = true;
        else
            rock[hang][i] = false;
        
        if(s[i] == 'E')
            e.push_back(make_pair(hang,i));
            
        if(s[i] == 'S')
        {
            p.x = hang;
            p.y = i;
        }
    }
}
/**/
int _abs(int val)
{
    if(val < 0)
        return -val;
    return val;
}
/**/
toado getnear(int hang,int cot)
{
    int i;
    toado pos,kq;
    int kc,tmp;
    kc = 100;
    
    if(hang == p.x && cot == p.y)
        return p;
        
    for(i=0;i<8;i++)
    {
        pos.x = hang + h[i].x;
        pos.y = cot + h[i].y;
        if(pos.x >= 0 && pos.x < nhang && pos.y >= 0 && pos.y < ncot)
        {
            tmp = _abs(pos.x - p.x) + _abs(pos.y - p.y);
            if(tmp < kc)
            {
                kc = tmp;
                kq = pos;
            }
        }
    }
    return kq;
}
/**/
bool e_move() // enemy move
{
    int i,j;
    int m[100];
    toado near;
    
    vt.clear();
    for(i=0;i<e.size();i++)
    {
        near = getnear(e[i].first,e[i].second); // move nearest
        if(near.x == p.x && near.y == p.y) //  check enemy attack my ship
        {
            batduoc = true;
            return true;
        }
        if(!rock[near.x][near.y])
            vt.push_back(make_pair(near.x,near.y));
    }
    
    for(i=0;i<vt.size();i++)        // check enemy attack enemy
        m[i] = 0;
        
    for(i=0;i<vt.size();i++)
        for(j=i+1;j<vt.size();j++)
            if(vt[i].first == vt[j].first && vt[i].second == vt[j].second)
                m[i] = m[j] = 1;
    e.clear();
    for(i=0;i<vt.size();i++)
    {
        if(!m[i])
            e.push_back(vt[i]);
    }
    return false;
}
/**/
bool solve()
{
    int i;
    int dau,cuoi;
    bool gap;
    
    dau = -1;
    cuoi = 0;
    
    q[0] = p;
    en[0] = e;
    d[p.x][p.y][e.size()] = false;
    kc[0] = 0;
    while(dau != cuoi)
    {
        dau++;
        if(kc[dau] < 9)
            for(i=0;i<8;i++)
            {
                p.x = q[dau].x + h[i].x;
                p.y = q[dau].y + h[i].y;
                if(p.x >= 0 && p.x < nhang && p.y >= 0 && p.y < ncot)        
                {
                    if(!rock[p.x][p.y])
                    {
                        e = en[dau];
                        gap = e_move();

                        if(e.size() == 0) //  het enemy
                            return true;

                        if(!gap && d[p.x][p.y][e.size()])
                        {
                            cuoi++;
                            kc[cuoi] = kc[dau] + 1;
                            d[p.x][p.y][e.size()] = false; // tai vi tri x y so enemy con lai
                            q[cuoi] = p;
                            en[cuoi] = e;
                        }
                    }
                }
            }
    }
    return false;
}
/**/
void khoitao()
{
    int i,j,k;
    for(i=0;i<nhang;i++)
        for(j=0;j<ncot;j++)
            for(k=0;k<=e.size();k++)
                d[i][j][k] = true;
}
/**/
void input()
{
    int i;
    int ntest;
    bool flg;
    scanf("%d",&ntest);
    while(ntest--)
    {
        e.clear();
        batduoc = false;
        for(i=0;i<nhang;i++)
        {
            scanf("%s",&a[i]);
            xuly(i,a[i]);
        }
        khoitao();
        flg = solve();
        
        if(flg || !batduoc)
            printf("I'm the king of the Seven Seas!\n");
        else
            printf("Oh no! I'm a dead man!\n");
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
