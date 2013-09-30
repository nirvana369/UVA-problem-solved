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

#define fi "10813.inp"
#define fo "10813.out"
/**/
using namespace std;
/**/
int a[7][7],c[80];
/**/
void bingo()
{
    int i,j;
    for(i=1;i<6;i++)
        for(j=1;j<6;j++)
            if(!(i-3) && !(j-3))
                a[i][j] = 0;
            else
                scanf("%d",&a[i][j]);
}
/**/
void card()
{
    int i;
    for(i=1;i<76;i++)
        scanf("%d",&c[i]);
}
/**/
bool kiemtra()
{
    int i,j;
    int sum1,sum2,sum3,sum4;
    sum1 = sum2 = sum3 = sum4 =0;
    for(i=1;i<=5;i++)
    {
        for(j=1;j<=5;j++)
        {
            sum3 += a[i][j];
            sum4 += a[j][i];
        }
        sum1 += a[i][i];
        sum2 += a[i][6-i];
        if(!sum3 || !sum4)
            return true;
        sum3 = sum4 = 0;
    }
    if(!sum1 || !sum2)
        return true;
    return false;
}
/**/
void findbingo(int val)
{
    int i,j;
    for(i=1;i<=5;i++)
        for(j=1;j<=5;j++)
            if(val == a[i][j])
            {
                a[i][j] = 0;
                return;
            }
}
/**/
void solve()
{
    int i;
    for(i=1;i<76;i++)
    {
        findbingo(c[i]);
        if(kiemtra())
        {
            printf("BINGO after %d numbers announced\n",i);
            return;
        }
    }
}
/**/
void input()
{
    int ntest;
    scanf("%d",&ntest);
    while(ntest--)
    {
        bingo();
        card();
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
