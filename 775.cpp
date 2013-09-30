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

#define fi "775.inp"
#define fo "775.out"
/**/
using namespace std;
/**/
bool a[300][300],d[300];
int kq[300],q[300];
int n;
bool oreca;
/**/
void khoitao()
{
    int i,j;
    
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            a[i][j] = false;
        d[i] = false;
    }
    
    oreca = false;
}
/**/
void solve(int id)
{
    int i;
    if(id == n)
    {
        if(a[kq[id-1]][1])
        {
            kq[n] = 1;
            oreca = true;
        }
        return;
    }
    
    for(i=1;i<=n;i++)
        if(d[i] && a[kq[id-1]][i])
        {
            kq[id] = i;
            d[i] = false;
            
            solve(id+1);
            
            if(oreca)
                return;
            
            d[i] = true;
        }
}
/**/
void op()
{
    int i;
    
    if(oreca)
        for(i=0;i<=n;i++)
        {
            if(i)
                printf(" ");
            printf("%d",kq[i]);
        }
    else
        printf("N");
    printf("\n");
}
/**/
bool loang(int xp)
{
    int dau,cuoi;
    int i;
    
    dau = -1;
    cuoi = 0;
    d[xp] = true;
    
    q[0] = xp;
    
    while(dau != cuoi)
    {
        dau++;
        for(i=1;i<=n;i++)
            if(!d[i] && a[q[dau]][i])
            {
                cuoi++;
                d[i] = true;
                q[cuoi] = i;
            }
    }
    if(cuoi + 1 == n)
        return true;
    return false;
}
/**/
void input()
{
    char s[10];
    int x,y;
    
    while(scanf("%d",&n) == 1)
    {
        khoitao();
        while(scanf("%s",&s) == 1)
        {
            if(s[0] == '%')
                break;
            sscanf(s,"%d",&x);
            scanf("%s",&s);
            sscanf(s,"%d",&y);
            a[x][y] = a[y][x] = true;
        }
        kq[0] = 1;
        if(loang(1))
        {
            d[1] = false;
            solve(1);
        }
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
