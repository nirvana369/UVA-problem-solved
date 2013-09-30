/*
                                                            Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "1225.inp"
#define fo "1225.out"
/**/
using namespace std;
/**/
int a[10000][10];
/**/
void xuly(int id,int value)
{
    while(value != 0)
    {
        a[id][value%10]++;
        value /= 10;
    }
}
/**/
void precal()
{
    int i,j;

    for(i=0;i<10;i++)
        a[1][i] = 0;
    a[1][1]++;
    for(i=2;i<=10000;i++)
    {
        for(j=0;j<10;j++)
            a[i][j] = a[i-1][j];
        xuly(i,i);
    }
}
/**/
void input()
{
    int i;
    int n,ntest;
    precal();
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d",&n);
        for(i=0;i<10;i++)
        {
            if(i != 0)
                printf(" ");
            printf("%d",a[n][i]);
        }
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
