/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "142.inp"
#define fo "142.out"
/**/
using namespace std;
/**/
struct toado{
                int x,y,x1,y1;
            };
toado icon[32000],rec[32000];
int ci,cr;
bool vsb[32000];
/**/
void chk_vsb()
{
    int i,j;
    
    for(i=1;i<ci;i++)
        for(j=1;j<cr;j++)
            if(icon[i].x >= rec[j].x && icon[i].x <= rec[j].x1 && icon[i].y >= rec[j].y && icon[i].y <= rec[j].y1)
            {
                vsb[i] = false;
                break;
            }
}
/**/
double dist(int x_1,int y_1,int x_2,int y_2)
{
    return sqrt((x_1-x_2)*(x_1-x_2)+(y_1-y_2)*(y_1-y_2));
}
/**/
void clicknow()
{
    int i;
    int dem;
    int x,y;
    int luu[32000];
    double kc,tmp;
    
    scanf("%d %d",&x,&y);
    
    for(i=cr-1;i>0;i--)
        if(x >= rec[i].x && x <= rec[i].x1 && y >= rec[i].y && y <= rec[i].y1)
        {
            printf("%c\n",i+64);
            return;
        }
        
    kc = 30000;
    for(i=1;i<ci;i++)
    {
        if(vsb[i])
        {
            tmp = dist(x,y,icon[i].x,icon[i].y);
            if(tmp < kc)
            {
                kc = tmp;
                dem = 0;
                luu[dem++] = i;
            }
            else if(tmp == kc)
                luu[dem++] = i;
        }
    }
    
    for(i=0;i<dem;i++)
        printf("%3d",luu[i]);
    printf("\n");
}
/**/
void input()
{
    char s[100];
    ci = cr = 1;
    while(true)
    {
        scanf("%s",&s);
        if(s[0] == 'I')
        {
            scanf("%d %d",&icon[ci].x,&icon[ci].y);
            vsb[ci] = true;
            ci++;
        }
        else if(s[0] == 'R')
        {
            scanf("%d %d %d %d",&rec[cr].x,&rec[cr].y,&rec[cr].x1,&rec[cr].y1);
            cr++;
        }
        else if(s[0] == 'M')
        {
            chk_vsb();
            clicknow();
        }
        else
            break;
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
