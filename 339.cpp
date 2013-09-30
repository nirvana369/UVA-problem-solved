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

#define fi "339.inp"
#define fo "339.out"
/**/
using namespace std;
/**/
struct toado{
                int x,y;
            };
toado huong[4] = {-1,0,
                   0,1,
                   1,0,
                   0,-1};
toado queue[600];
int a[40][40];
int nhang,ncot;
/**/
void cpy(int cot1,int cot2)
{
    int ihang;
    for(ihang=1;ihang<=nhang;ihang++)
        a[ihang][cot1] = a[ihang][cot2];
}
/**/
void dropdown()
{
    int ihang,icot,id,jcot,jhang;

    for(icot=1;icot<=ncot;icot++)
    {
        for(ihang=1;ihang<nhang;ihang++)
        {
            if(a[ihang][icot] == -1)
            {
                for(jhang=ihang+1;jhang<=nhang;jhang++)
                    if(a[jhang][icot] != -1)
                    {
                        a[ihang][icot] = a[jhang][icot];
                        a[jhang][icot] = -1;
                        break;
                    }
            }
        }
    }
    
    for(icot=1;icot<=ncot;icot++)
    {
        if(a[1][icot] == -1)
        {
            for(jcot=icot;jcot<ncot;jcot++)
                cpy(jcot,jcot+1);
            
            for(ihang=1;ihang<=nhang;ihang++)
                a[ihang][ncot] = -1;
        }
    }
}
/**/
void loang(int hang,int cot)
{
    int dau,cuoi;
    int h;
    toado vitri;
    
    dau = -1;
    cuoi = 0;
    queue[0].x = hang;
    queue[0].y = cot;
    
    while(dau != cuoi)
    {
        dau++;
        for(h=0;h<4;h++)
        {
            vitri.x = queue[dau].x + huong[h].x;
            vitri.y = queue[dau].y + huong[h].y;
            if(vitri.x > 0 && vitri.x <= nhang && vitri.y > 0 && vitri.y <= ncot && (vitri.x != hang || vitri.y != cot))
                if(a[vitri.x][vitri.y] == a[hang][cot])
                {
                    cuoi++;
                    queue[cuoi].x = vitri.x;
                    queue[cuoi].y = vitri.y;
                    a[vitri.x][vitri.y] = -1;
                }
        }
    }
    
    if(cuoi != 0)
    {
        a[hang][cot] = -1;
        dropdown();
    }
}
/**/
void output(int chiso)
{
    int ihang,icot;
    printf("Grid %d.",chiso);
    if(a[1][1] != -1)
    {
        for(ihang=nhang;ihang>0;ihang--)
        {
            printf("\n");
            for(icot=1;icot<=ncot;icot++)
            {   
                if(icot == 1)
                    if(a[ihang][icot] != -1)
                        printf("%5d",a[ihang][icot]);
                    else
                        printf("     ");
                else
                    if(a[ihang][icot] != -1)
                        printf(" %d",a[ihang][icot]);
                    else
                        printf("  ");
            }
        }
    }
    else
        printf("\n    Game Won");
    printf("\n");
}
/**/
void input()
{
    int ihang,icot;
    int id;
    id = 1;
    scanf("%d %d",&nhang,&ncot);
    while(nhang != 0 && ncot != 0)
    {
        for(ihang=1;ihang<=nhang;ihang++)
            for(icot=1;icot<=ncot;icot++)
                scanf("%d",&a[ihang][icot]);
        scanf("%d %d",&ihang,&icot);
        while(ihang != 0 && icot != 0)
        {
            if(ihang > 0 && ihang <= nhang && icot > 0 && icot <= ncot && a[ihang][icot] != -1)
                loang(ihang,icot);
            scanf("%d %d",&ihang,&icot);
        }
        output(id);
        id++;
        scanf("%d %d",&nhang,&ncot);
        if(nhang != 0 && ncot != 0)
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
