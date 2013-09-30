/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "890.inp"
#define fo "890.out"
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
toado p[320000];
bool a[45][45][5],d[45][45];
int nhang,ncot;
long id;
/**/
void khoitao()
{
    int i,j,k;
    for(i=0;i<nhang;i++)
        for(j=0;j<ncot;j++)
        {
            for(k=0;k<4;k++)
                a[i][j][k] = true;
            d[i][j] = true;
        }
}
/**/
int getdir(char huong)
{
    if(huong == 'U')
        return 0;
    if(huong == 'R')
        return 1;
    if(huong == 'L')
        return 3;
    return 2;
}
/**/
void dichuyen(int dir)
{
    toado pos;
    pos.x = p[id].x + h[dir].x;
    pos.y = p[id].y + h[dir].y;
    if(pos.x >= 0 && pos.y >= 0 && pos.x < nhang && pos.y < ncot)
    {
        a[p[id].x][p[id].y][dir] = false;
        a[pos.x][pos.y][(dir+2)%4] = false;
        p[++id] = pos;
    }
   // printf("%d %d\n",pos.x,pos.y);
}
/**/
void flipp(int vt)
{
    long i,j;
    toado tmp;
    i = vt;
    j = id;
    while(i < j)
    {
        tmp = p[i];
        p[i] = p[j];
        p[j] = tmp;
        i++;
        j--;
    }
}
/**/
void output()
{
    int i,j,k;
    for(i=0;i<ncot;i++)
        printf(" _");
    printf("\n");
    for(i=0;i<nhang;i++)
    {
        for(j=0;j<ncot;j++)
        {
            for(k=3;k>1;k--)
            {
                if(a[i][j][k])
                {
                    if(k == 2)
                        printf("_");
                    else
                        printf("|");
                }
                else
                    printf(" ");
            }
        }
        printf("|\n");
    }
    printf("\n");
}
/**/
void input()
{
    int ntest;
    int tmp;
    char s[1000];
    
    scanf("%d",&ntest);
    scanf("%d",&nhang);
    while(ntest--)
    {
        scanf("%d",&ncot);
        khoitao();
        scanf("%d %d",&p[1].x,&p[1].y);
        id = 1;
        p[1].x = nhang - p[1].x;
        p[1].y--;
        while(true)
        {
            s[0] = 0;
            scanf("%s",&s);
            if(s[0] == 'U')
                dichuyen(getdir(s[0]));
            else if(s[0] == 'R')
                dichuyen(getdir(s[0]));
            else if(s[0] == 'L')
                dichuyen(getdir(s[0]));
            else if(s[0] == 'D')
                dichuyen(getdir(s[0]));
            else if(s[0] == 'F')
            {
                scanf("%d",&tmp);
                flipp(tmp);
                while(!d[p[id].x][p[id].y])
                    id--;
                d[p[id].x][p[id].y] = false;
            }
            else
            {
                sscanf(s,"%d",&tmp);
                break;
            }
        }
        output();
        nhang = tmp;
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
