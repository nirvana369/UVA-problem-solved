/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "1459.inp"
#define fo "1459.out"
/**/
using namespace std;
/**/
bool d[210],p[210][210];
int kq[210],luu[210],c[210],a[210][210];
int nhang,ncot,vitri,place;
/**/
void dfs(int id)
{
    int i;
    if(id == ncot + 1)
    {
        place++;
        if(place == vitri)
            for(i=1;i<id;i++)
                kq[i] = luu[i];
        return;
    }
    
    for(i=0;i<c[id];i++)
        if(d[a[id][i]])
        {
            d[a[id][i]] = false;
            luu[id] = a[id][i];
            
            dfs(id+1);
            
            if(place == vitri)
                return;
                
            d[a[id][i]] = true;
        }
}
/**/
void solve()
{
    int i,j;
    
    place = 0;
    
    for(i=1;i<=ncot;i++)
    {
        for(j=1;j<=ncot;j++)
            if(p[j][i])
                a[i][c[i]++] = j;
        if(c[i] == 0)
        {
            place = -1;
            break;
        }
    }           
    
    if(place == 0)
        dfs(1);
    
    if(place == vitri)
    {
        for(i=1;i<=ncot;i++)
        {
            if(i != 1)
                printf(" ");
            printf("%d",kq[i]);
        }
    }
    else
        printf("-1");
    printf("\n");
}
/**/
void khoitao()
{
    int i,j;
    for(i=1;i<=ncot;i++)
    {
        for(j=1;j<=ncot;j++)
            p[i][j] = true;
        d[i] = true;
        c[i] = 0;
    }
}
/**/
void input()
{
    int i,j;
    int ntest,id;
    int gt;
    
    id = 1;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d %d %d",&ncot,&nhang,&vitri);
        khoitao();
        for(i=1;i<=nhang;i++)
        {
            for(j=1;j<=ncot;j++)
            {
                scanf("%d",&gt);
                p[gt][j] = false;
            }
        }
        printf("Case #%d: ",id++);
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
