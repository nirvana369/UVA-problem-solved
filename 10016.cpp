/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "10016.inp"
#define fo "10016.out"
/**/
using namespace std;
/**/
long a[500][500];
int n;
/**/
void swapcell(long &a,long &b)
{
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}
/**/
void flip_1(int r) // upside-down
{
    int i,j;
    int r1;
    r1 = n - r + 1;
    
    i = r;
    j = r1;
    while(i < j)
    {
        swapcell(a[i][r],a[j][r]);
        swapcell(a[i][r1],a[j][r1]);
        i++;
        j--;
    }
            
    for(i=r+1;i<r1;i++)
        swapcell(a[r][i],a[r1][i]);
}
/**/
void flip_2(int r) // left-right
{
    int i,j;
    int r1;
    r1 = n - r + 1;
    
    i = r;
    j = r1;
    while(i < j)
    {
        swapcell(a[r][i],a[r][j]);
        swapcell(a[r1][i],a[r1][j]);
        i++;
        j--;
    }
            
    for(i=r+1;i<r1;i++)
        swapcell(a[i][r],a[i][r1]);
}
/**/
void flip_4(int r) // main diagonal flip
{
    int i,j;
    int r1;
    r1 = n - r + 1;
    swapcell(a[r][r],a[r1][r1]);
    for(i=r+1,j=r1-1;i<r1;i++,j--)
    {
        swapcell(a[r][i],a[j][r1]);
        swapcell(a[r1][j],a[i][r]);
    }
}
/**/
void flip_3(int r) // main inverse diagonal flip
{
    int i,j;
    int r1;
    r1 = n - r + 1;
    swapcell(a[r][r1],a[r1][r]);
    for(i=r+1;i<r1;i++)
    {
        swapcell(a[r][i],a[i][r]);
        swapcell(a[r1][i],a[i][r1]);
    }
}
/**/
void output()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if((j-1))
                printf(" ");
            printf("%ld",a[i][j]);
        }
        printf("\n");
    }
}
/**/
void input()
{
    int i,j;
    int lenh,m,r;
    int ntest;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                scanf("%ld",&a[i][j]);
        r = n/2+n%2;
        for(i=1;i<=r;i++)
        {
            scanf("%d",&m);
            for(j=0;j<m;j++)
            {
                scanf("%d",&lenh);
                
                if(lenh == 1)
                    flip_1(i);
                else if(lenh == 2)
                    flip_2(i);
                else if(lenh == 3)
                    flip_3(i);
                else if(lenh == 4)
                    flip_4(i);
            }
        }
        output();
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
