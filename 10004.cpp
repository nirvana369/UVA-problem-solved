/*
                                                    Hoang Linh
                                                
                                        Problem: BICOLORING - 10004 (10004.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10004.inp"
#define fo "10004.out"
/**/
using namespace std;
/**/
int d[210],a[210][210],q[210];
int n;
/**/
void khoitao()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            a[i][j] = 0;
        d[i] = 0;
    }
}
/**/
bool loang(int dinh)
{
    int i;
    int dau,cuoi;
    
    dau = -1;
    cuoi = 0;
    
    d[dinh] = 1;
    q[0] = dinh;
    
    while(dau != cuoi)
    {
        dau++;
        for(i=0;i<n;i++)
            if(a[q[dau]][i] == 1)
            {
                if(d[i] == 0)
                {
                    cuoi++;
                    q[cuoi] = i;
                    d[i] = d[q[dau]] + 1;
                }
                else if(d[i] == d[q[dau]])
                    return false;
            }
    }
    return true;
}
/**/
void solve()
{
    int i;
    for(i=0;i<n;i++)
        if(d[i] == 0)
            if(!loang(i))
            {
                printf("NOT BICOLORABLE.\n");
                return;
            }
    printf("BICOLORABLE.\n");
}
/**/
void input()
{
    int i;
    int x,y;
    int nduong;
    while(true)
    {
        scanf("%d",&n);
        if(!n)
            break;
        khoitao();
        scanf("%d",&nduong);
        for(i=0;i<nduong;i++)
        {
            scanf("%d %d",&x,&y);
            a[x][y] = 1;
            a[y][x] = 1;
        }
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
