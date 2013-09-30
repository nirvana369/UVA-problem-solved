/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
//#include <queue>
//#include <vector>
//#include <map>

#define fi "211.inp"
#define fo "211.out"
#define nhang 7
#define ncot 8
/**/
using namespace std;
/**/
struct toado{
                int x,y;
            };
toado h[4] = {-1,0,0,1,1,0,0,-1};
int a[nhang+2][ncot+2],p[nhang+2][ncot+2],dmn[8][8];
bool used[30],d[nhang+2][ncot+2];
int n,ans;
/**/
void _init()
{
    int i,j;
    
    n = 1;
    for(i=0;i<7;i++)
        for(j=i;j<7;j++)
            dmn[i][j] = dmn[j][i] = n++;
}
/**/
void khoitao()
{
    int i;
    
    for(i=1;i<n;i++)
        used[i] = true;
    
    ans = 0;
}
/**/
void effect(int id,int hang,int cot)
{
    int i,j,dir;
    int v1,v2,px,py;
    
    if(id == n)
    {
        ans++;
        for(i=0;i<nhang;i++)
        {
            printf(" ");
            for(j=0;j<ncot;j++)
                printf("%4d",p[i][j]);
            printf("\n");
        }
        printf("\n");
        return;
    }
    
    if(cot == ncot)
        hang++;
        
    for(i=hang;i<nhang;i++)
        for(j=0;j<ncot;j++)
            if(d[i][j])
            {
                d[i][j] = false;
                v1 = a[i][j];
                for(dir=0;dir<4;dir++)
                {
                    px = i + h[dir].x;
                    py = j + h[dir].y;
                    if(px >= 0 && px < nhang && py >= 0 && py < ncot)
                        if(d[px][py])
                        {
                            v2 = a[px][py];
                            if(used[dmn[v1][v2]])
                            {
                                used[dmn[v1][v2]] = false;
                                used[dmn[v2][v1]] = false;
                                d[px][py] = false;
                                p[i][j] = p[px][py] = dmn[v1][v2];
                                
                                effect(id+1,px,py);
                                
                                d[px][py] = true;
                                used[dmn[v1][v2]] = true;
                                used[dmn[v2][v1]] = true;
                            }
                        }
                }
                d[i][j] = true;
                return;
            }
}
/**/
void op(int id)
{
    int i,j;
    
    printf("Layout #%d:\n\n",id);
    for(i=0;i<nhang;i++)
    {
        printf(" ");
        for(j=0;j<ncot;j++)
            printf("%4d",a[i][j]);
        printf("\n");    
    }
    printf("\nMaps resulting from layout #%d are:\n\n",id);
}
/**/
void input()
{
    int i,j;
    int id;
    
    _init();
    id = 0;
    while(true)
    {
        a[0][0] = -1;
        for(i=0;i<nhang;i++)
            for(j=0;j<ncot;j++)
            {
                scanf("%d",&a[i][j]);
                d[i][j] = true;
            }
        if(a[0][0] == -1)
            break;
            
        khoitao();
        
        if(id)
            printf("\n\n\n");
            
        op(++id);
        
        effect(1,0,0);
        
        printf("There are %d solution(s) for layout #%d.\n",ans,id);
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
