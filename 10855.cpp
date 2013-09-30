/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "10855.inp"
#define fo "10855.out"
/**/
using namespace std;
/**/
int bign,n;
char a[1000][1000],b[1000][1000];
int d[4];
/**/
bool chk(int h,int c)
{
    int i,j,i1,j1;
    
    for(i=0,i1=h;i<n;i++,i1++)
        for(j=0,j1=c;j<n;j++,j1++)
            if(a[i][j] != b[i1][j1])
                return false;
    return true;
}
/**/
int countsq()
{
    int i,j;
    int dem;
    dem = 0;
    for(i=0;i<=bign-n;i++)
        for(j=0;j<=bign-n;j++)
            if(b[i][j] == a[0][0])
                if(chk(i,j))
                    dem++;
    return dem;
}
/**/
void rotation()
{
    int i,j;
    char tmp[1000][1000];
    
    for(i=0;i<bign;i++)
        for(j=0;j<bign;j++)
            tmp[i][j] = b[j][bign-i-1];
            
    for(i=0;i<bign;i++)
        for(j=0;j<bign;j++)
            b[i][j] = tmp[i][j];
}
/**/
void solve()
{
    int i;
    for(i=3;i>=0;i--)
    {
        d[i] = countsq();
        if(i)
            rotation();
    }
    for(i=3;i>=0;i--)
    {
        printf("%d",d[i]);
        if(i)
            printf(" ");
    }
    printf("\n");
}
/**/
void input()
{
    int i;
    while(scanf("%d %d",&bign,&n) && bign && n)
    {
        for(i=0;i<bign;i++)
            scanf("%s",&b[i]);
        for(i=0;i<n;i++)
            scanf("%s",&a[i]);
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
