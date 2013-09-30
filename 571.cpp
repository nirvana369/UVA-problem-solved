/*
                                                                Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "571.inp"
#define fo "571.out"
/**/
using namespace std;
/**/
struct tt{
            int x,y;
         };
tt q[1000100];
long truoc[1000100],out[1000100];
int kq[1000000];
int ca,cb,n;
/**/
bool trangthai(int flag,long cuoi,long temp)
{
    long id,i;
    int rong;
    
    id = temp + 1;
    if(flag == 0) // fill A
    {
        q[id].x = ca;
        q[id].y = q[cuoi].y;
    }
    else if(flag == 1) // fill B
    {
        q[id].x = q[cuoi].x;
        q[id].y = cb;
    }
    else if(flag == 2) // emty A
    {
        q[id].x = 0;
        q[id].y = q[cuoi].y;
    }
    else if(flag == 3) // emty B
    {
        q[id].x = q[cuoi].x;
        q[id].y = 0;
    }
    else if(flag == 4) // poor A to B
    {
        if(q[cuoi].x == 0)
            return false;
        rong = cb - q[cuoi].y;
        if(rong > 0)
        {
            if(q[cuoi].x <= rong)
            {
                q[id].x = 0;
                q[id].y = q[cuoi].y + q[cuoi].x;
            }
            else
            {
                q[id].x = q[cuoi].x - rong;
                q[id].y = q[cuoi].y + rong;
            }
        }
        else
            return false;
    }
    else if(flag  == 5) //  poor B to A
    {
        if(q[cuoi].y == 0)
            return false;
        rong = ca - q[cuoi].x;
        if(rong > 0)
        {
            if(q[cuoi].y <= rong)
            {
                q[id].x = q[cuoi].x + q[cuoi].y;
                q[id].y = 0;
            }
            else
            {
                q[id].x = q[cuoi].x + rong;
                q[id].y = q[cuoi].y - rong;
            }
        }
        else
            return false;
    }
    for(i=temp;i>=0;i--)
        if(q[id].x == q[i].x && q[id].y == q[i].y)
            return false;
    return true;
}
/**/
void in(int flag)
{
    if(flag == 0)
        printf("fill A\n");
    else if(flag == 1)
        printf("fill B\n");
    else if(flag == 2)
        printf("empty A\n");
    else if(flag == 3)
        printf("empty B\n");
    else if(flag == 4)
        printf("pour A B\n");
    else
        printf("pour B A\n");
}
/**/
void output(long cuoi)
{
    long dem,i;
    dem = 0;
    while(cuoi != 0)
    {
        //printf("%d %d\n",q[cuoi].x,q[cuoi].y);
        kq[dem++] = out[cuoi];
        cuoi = truoc[cuoi];
    }
    for(i=dem-1;i>=0;i--)
        in(kq[i]);
    printf("success\n");
}
/**/
void solve()
{
    int i;
    long dau,cuoi;
    
    dau = -1;
    cuoi = 0;
    q[0].x = 0;
    q[0].y = 0;
    truoc[0] = 0;
    while(dau != cuoi)
    {
        dau++;
        for(i=0;i<6;i++)
        {
            if(trangthai(i,dau,cuoi))
            {
                cuoi++;
                out[cuoi] = i;
                truoc[cuoi] = dau;
                if(q[cuoi].y == n)
                {
                    output(cuoi);
                    return;
                }
            }
        }
    }
}
/**/
void input()
{
    while(scanf("%d %d %d",&ca,&cb,&n) == 3)
        solve();
}
/**/
int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    input();
    return 0;
}
