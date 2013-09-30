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

#define fi "626.inp"
#define fo "626.out"
/**/
using namespace std;
/**/
int n;
int loai[110][110];
/**/
bool kiemtra(int a,int b,int c)
{
    if(a<b && b<c && loai[a][b]==1 && loai[b][c]==1 && loai[c][a]==1)
        return true;
    if(a>b && b>c && loai[a][b]==1 && loai[b][c]==1 && loai[c][a]==1)
        return true;
    return false;
}
/**/
void output(int a,int b,int c)
{
    printf("%d %d %d\n",a,b,c);
}
/**/
void solve()
{
    int i,j,k;
    int dem;
    
    dem=0;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            for(k=1;k<=n;k++)
                if(kiemtra(i,j,k))
                {
                    dem++;
                    output(i,j,k);
                }
    printf("total:%d\n",dem);
}
/**/
void input()
{
    int i,j;
    
    scanf("%d",&n);
    while(n!=0)
    {
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                scanf("%d",&loai[i][j]);
        solve();    
        n=0;
        scanf("%d",&n);
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
