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

#define fi "11040.inp"
#define fo "11040.out"
/**/
using namespace std;
/**/
int a[100][100];
/**/
void brick(int hang,int cot)
{
    int gt;
    gt = a[hang][cot] - (a[hang+2][cot] + a[hang+2][cot + 2]);
    a[hang+2][cot+1] = gt / 2;
        
    a[hang+1][cot] = a[hang+2][cot] + a[hang+2][cot+1];
    a[hang+1][cot+1] = a[hang+2][cot+1] + a[hang+2][cot+2];
}
void solve(int hang,int cot)
{
    int i,j;
    for(i=1;i<10;i+=2)
        for(j=1;j<=i;j+=2)
            brick(i,j);
}
/**/
void output()
{
    int i,j;
    for(i=1;i<10;i++)
    {
        for(j=1;j<=i;j++)
        {
            if(j-1)
                printf(" ");
            printf("%d",a[i][j]);
        }
        printf("\n");
    }
}
/**/
void input()
{
    int i;
    int ntest;
    int hang;
    scanf("%d",&ntest);
    while(ntest--)
    {
        hang = 1;
        while(hang != 10)
        {
            for(i=1;i<=hang;i++)
                a[hang][i] = 0;
            if(hang % 2 != 0)
                for(i=1;i<=hang;i+=2)
                    scanf("%d",&a[hang][i]);
            hang++;
        }
        solve(1,1);
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
