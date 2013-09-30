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
#include <vector>

#define fi "10982.inp"
#define fo "10982.out"
/**/
using namespace std;
/**/
int a[100][100],d[100];
int n,m;
/**/
void solve()
{
    int ca[100],cb[100];
    int da,db,counta,countb;
    int i,j;
    
    counta = countb = 0;
    for(i=1;i<=n;i++)
    {
        da = db = 0;
        for(j=i-1;j>=1;j--)
            if(a[i][j])
            {
                if(d[j])
                    da++;
                else
                    db++;
            }
        if(da <= db)
        {
            ca[counta++] = i;
            d[i] = 1;
        }
        else
        {
            cb[countb++] = i;
            d[i] = 2;
        }
    }
    for(i=0;i<countb;i++)
        cout << cb[i] << " ";
    cout << endl;
}
/**/
void khoitao()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            a[i][j] = 0;
        d[i] = 0;
    }
}
void input()
{
    int i;
    int x,y;
    int ntest;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d %d",&n,&m);
        khoitao();
        for(i=0;i<m;i++)
        {
            scanf("%d %d",&x,&y);
            a[x][y] = a[y][x] = 1;
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
