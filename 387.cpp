/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
//#include <queue>
#include <vector>
//#include <map>

#define fi "387.inp"
#define fo "387.out"
/**/
using namespace std;
/**/
struct toado{
                int x,y;
            };
struct data{
                int h[5][5];
                int r,c;
            };
data p[10];
int m[10],kq[5][5];
char s[5][5];
int n;
bool perfect;
/**/
bool chk(int a[5][5],int id,int hang,int cot)
{
    int i,j,i1,j1;
    
    for(i=0,i1=hang;i<p[id].r;i++,i1++)
        for(j=0,j1=cot;j<p[id].c;j++,j1++)
            if(p[id].h[i][j] && a[i1][j1])
                return false;
    
    return true;
}
/**/
void xephinh(int d[5][5],int id,int hang,int cot,vector<toado> &pos)
{
    int i,j,i1,j1;
    toado t;
    
    for(i=0,i1=hang;i<p[id].r;i++,i1++)
        for(j=0,j1=cot;j<p[id].c;j++,j1++)
            if(p[id].h[i][j])
            {
                d[i1][j1] = id;
                t.x = i1;
                t.y = j1;
                pos.push_back(t);
            }
}
/**/
void lego(int id,int a[5][5])
{
    int i,j,k,t;
    int d[5][5];
    vector<toado > pos;
    
    if(id == n)
    {
        for(i=0;i<4;i++)
            for(j=0;j<4;j++)
            {
                if(!a[i][j])
                    return;
                kq[i][j] = a[i][j];
            }
        perfect = true;
        return;
    }
    
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            d[i][j] = a[i][j];
            
    for(i=1;i<=n;i++)
    {
        if(m[i])
        {
            m[i] = false;
            
            for(j=0;j<=4-p[i].r;j++)
                for(k=0;k<=4-p[i].c;k++)
                    if(!a[j][k] && chk(a,i,j,k))
                    {
                        pos.clear();
                        xephinh(d,i,j,k,pos);
                        
                        lego(id+1,d);
                        
                        if(perfect)
                            return;
                        
                        for(t=0;t<pos.size();t++)
                                d[pos[t].x][pos[t].y] = 0;
                    }
            
            m[i] = true;
        }
    }
}
/**/
void op()
{
    int i,j;
    
    if(!perfect)
    {
        printf("No solution possible\n");
        return;
    }
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
            printf("%d",kq[i][j]);
        printf("\n");
    }
}
/**/
void xuly(int id)
{
    int i,j;
    
    for(i=0;i<p[id].r;i++)
        for(j=0;j<p[id].c;j++)
            p[id].h[i][j] = (s[i][j] - 48);
}
/**/
void input()
{
    int a[5][5];
    int i,j,k;
    int id;
    
    id = 0;
    while(scanf("%d",&n) && n)
    {
        for(i=1;i<=n;i++)
        {
            m[i] = true;
            scanf("%d %d",&p[i].r,&p[i].c);
            for(j=0;j<p[i].r;j++)
                scanf("%s",&s[j]);
            xuly(i);
        }
        for(i=0;i<4;i++)
            for(j=0;j<4;j++)
                a[i][j] = 0;
        perfect = false;
        lego(0,a);
        if(id++)
            printf("\n");
        op();
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
