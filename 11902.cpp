/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "11902.inp"
#define fo "11902.out"
/**/
using namespace std;
/**/
int a[110][110];
bool domina[110][110],d[110],d1[110];
int n;
/**/
void resetd()
{
    int i;
    for(i=0;i<n;i++)
        d[i] = false;
}
/**/
void dq(int x,int y)
{
    int i;
    if(x == y)
        return;
    d[x] = true;
    
    for(i=0;i<n;i++)
        if(a[x][i] && !d[i])
            dq(i,y);
}
/**/
void output()
{
    int i,j,k;
    
    for(i=0;i<n;i++)
    {
        printf("\n+");
        for(k=0;k<n*2-1;k++)
            printf("-");
        printf("+\n|");
        for(j=0;j<n;j++)
            if(domina[i][j])
                printf("Y|");
            else
                printf("N|");
    }
    printf("\n+");
    for(k=0;k<n*2-1;k++)
        printf("-");
    printf("+\n");
}
/**/
void solve()
{
    int i,j;
    // di tu dinh 0 den tat ca cac dinh co the
    dq(0,n+1);
    
    for(i=0;i<n;i++)
        d1[i] = d[i];
        
    for(i=0;i<n;i++)
    {
        resetd();
        // di tu dinh 0 den tat ca cac dinh cho den khi gap dinh i 
        dq(0,i);
        
        for(j=0;j<n;j++)
            if(d1[j] && !d[j])
                domina[i][j] = true;
            else
                domina[i][j] = false;
    }
    output();
}
/**/
void input()
{
    int i,j;
    int ntest,id;
    
    id = 1;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
                scanf("%d",&a[i][j]);
            d[i] = false;
        }
        printf("Case %d:",id++);
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
