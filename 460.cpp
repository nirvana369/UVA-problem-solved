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

#define fi "460.inp"
#define fo "460.out"
/**/
using namespace std;
/**/
struct hcn{
                int xl,yl,xr,yr;
          };
hcn td[10];
int x[5],y[5],x_1[5],y_1[5];
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
bool kiemtra(int xll,int xrr,int yll,int yrr)
{
    int dem;
    dem = 0;
    if(xll >= x_1[0] && xrr <= x_1[1] && yll >= y_1[0] && yrr <= y_1[1])
        dem++;
    if(xll >= x_1[2] && xrr <= x_1[3] && yll >= y_1[2] && yrr <= y_1[3])
        dem++;
    if(dem == 2)
    {
        if(xll != xrr && yll != yrr)
            return true;
        return false;
    }
    return false;
}
/**/
int solve()
{
    int i,id,j;
    sapxep();
    id = 0;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
        {
            td[id].xl = x[i];
            td[id].xr = x[i+1];
            td[id].yl = y[j];
            td[id].yr = y[j+1];
            id++;
        }
    for(i=0;i<id;i++)
        if(kiemtra(td[i].xl,td[i].xr,td[i].yl,td[i].yr))
            return i;
    return -1;
}
/**/
void input()
{
    int i,id;
    int ntest;
    scanf("%d",&ntest);
    while(ntest--)
    {
        for(i=0;i<4;i++)
        {
            scanf("%d %d",&x[i],&y[i]);
            x_1[i] = x[i];
            y_1[i] = y[i];
        }
        id = solve();
        if(id != -1)
            printf("%d %d %d %d\n",td[id].xl,td[id].yl,td[id].xr,td[id].yr);
        else
            printf("No Overlap\n");
        if(ntest != 0)
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
