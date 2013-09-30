/*
                                                Hoang Linh
                                        
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define fi "trip2.inp"
#define fo "trip2.out"
/**/
using namespace std;
/**/
struct toado{
                int x,y,z;
            };
toado p[2000];
int a[50][50],d[50];
int n,maxp,home;
/**/
int getmin(int gt1,int gt2)
{
    if(gt1 > gt2)
        return gt2;
    return gt1;
}
/**/
void khoitao()
{
    int i,j;
    int vt;
    for(i=1;i<=n;i++)
    {
        for(j=i;j<=n;j++)
        {
            a[i][j] = 0;
            a[j][i] = 0;
        }
        d[i] = 0;
    }
    
    for(i=1;i<=maxp;i++)
    {
        a[p[i].x][p[i].y]++;
        a[p[i].y][p[i].x]++;
        
        d[p[i].x]++;
        d[p[i].y]++;
    }
}
/**/
void output(int vtx,int vty)
{
    int i;
    int value;
    for(i=1;i<=maxp;i++)
        if((vtx == p[i].x && vty == p[i].y) || (vty == p[i].x && vtx == p[i].y))
        {
            printf("%d",i);
            p[i].x = -1;
            p[i].y = -1;
            return;
        }
}
/**/
void solve()
{
    int i;
    int dem,dems,bcount,demkq;
    int stack[5000],kq[5000];
    khoitao();
    
    for(i=1;i<=n;i++)
        if(d[i] % 2 != 0)
        {
            printf("Round trip does not exist.\n");
            return;
        }
    
    dem = 0;
    stack[0] = home;
    kq[0] = home;
    demkq = 0;
    dems = 0;
    while(dem <= maxp)
    {
        bcount = dems;
        for(i=1;i<=maxp;i++)
            if(p[i].z == 0 && (p[i].x == stack[dems] || p[i].y == stack[dems]))
            {
                dems++;
                if(stack[dems-1] == p[i].x)
                    stack[dems] = p[i].y;
                else
                    stack[dems] = p[i].x;
                p[i].z = 1;
                a[p[i].x][p[i].y]--;
                a[p[i].y][p[i].x]--;
                break;
            }
        if(bcount == dems)
        {
            demkq++;
            kq[demkq] = stack[dems];
            dems--; 
            dem++;
        }
    }
    for(i=demkq;i>0;i--)
    {
        if(i != demkq && i != 1)
            printf(" ");
        output(kq[i],kq[i-1]);
    }
    printf("\n");
}
/**/
void input()
{
    int x,y,z;
    int dkthoat;
    
    dkthoat = 0;
    n = 0;
    maxp = 0;    
    home = -1;
    while(true)
    {
        while(true)
        {
            scanf("%d %d",&x,&y);
            if(x == 0 && y == 0)
            {
                dkthoat++;
                if(dkthoat == 2)
                    return;
                solve();
                printf("\n");
                n = 0;
                home = -1;
                maxp = 0;
                break;
            }
            if(home == -1)
                home = getmin(x,y);
            if(x > n)
                n = x;
            if(y > n)
                n = y;
            scanf("%d",&z);
            if(z > maxp)
                maxp = z;
            p[z].x = x;
            p[z].y = y;
            p[z].z = 0;
            dkthoat = 0;
        }
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
