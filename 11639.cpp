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

#define fi "11639.inp"
#define fo "11639.out"
/**/
using namespace std;
/**/
struct hcn{
                int x1,y1,x2,y2;
          };
hcn nt[10];
int r1,r2,r3;
int x[5],y[5],xtmp[5],ytmp[5];
/**/
bool xet(int xtrai,int ytrai,int xphai,int yphai)
{
    int i;
    int dem;
    dem = 0;
    if(xtrai == xphai && ytrai == yphai)
        return false;
    for(i=0;i<4;i+=2)
        if(xtrai >= xtmp[i] && xphai <= xtmp[i+1] && ytrai >= ytmp[i] && yphai <= ytmp[i+1])
            dem++;
    if(dem == 2)
        return true;
    return false;
}
/**/
void solve(int id)
{
    r1 = (nt[id].x2 - nt[id].x1) * (nt[id].y2 - nt[id].y1);
    r2 -= r1 * 2;
}
/**/
void kiemtra()
{
    int i,j;
    int d;
    d = 0;
    if(xtmp[0] == xtmp[2] && ytmp[0] == ytmp[2] && xtmp[1] == xtmp[3] && ytmp[1] == ytmp[3])
    {
        r2 /= 2;
        r1 = r2;
        r2 = 0;
        return ;
    }
    for(i=0;i<3;i++)                    // chia thanh 9 hinh nho
        for(j=0;j<3;j++)
        {
            nt[d].x1 = x[i];
            nt[d].x2 = x[i+1];
            nt[d].y1 = y[i];
            nt[d].y2 = y[i+1];
            d++;
        }
    for(i=0;i<d;i++)
        if(xet(nt[i].x1,nt[i].y1,nt[i].x2,nt[i].y2))
        {
            solve(i);
            return;
        }
}
/**/
void sapxep()
{
    int i,j;
    int temp;
        
    for(i=0;i<3;i++)
        for(j=i+1;j<4;j++)
            if(x[i] > x[j])
            {
                temp = x[i];
                x[i] = x[j];
                x[j] = temp;
            }
    for(i=0;i<3;i++)
        for(j=i+1;j<4;j++)
            if(y[i] > y[j])
            {
                temp = y[i];
                y[i] = y[j];
                y[j] = temp;
            }
}
/**/
void input()
{
    int i;
    int ntest,id;
    scanf("%d",&ntest);
    id = 1;
    while(ntest--)
    {
        for(i=0;i<4;i++)
        {
            scanf("%d %d",&x[i],&y[i]);
            xtmp[i] = x[i];
            ytmp[i] = y[i];
        }
        r2 = (x[1]-x[0]) * (y[1]-y[0]) + (x[3]-x[2]) * (y[3]-y[2]);
        r1 = 0;
        r3 = 10000;
        sapxep();
        kiemtra();
        r3 -= (r2 + r1);
        printf("Night %d: %d %d %d\n",id++,r1,r2,r3);
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
