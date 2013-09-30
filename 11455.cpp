/*
                                                                Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "11455.inp"
#define fo "11455.out"
/**/
using namespace std;
/**/
long a[5];
/**/
void solve()
{
    int i,j;
    long temp;
    for(i=0;i<3;i++)
        for(j=i+1;j<4;j++)
            if(a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
    if(a[0] == a[1] && a[0] == a[2] && a[0] == a[3])
        printf("square\n");
    else if(a[0] == a[1] && a[2] == a[3])
        printf("rectangle\n");
    else if(a[0] + a[1] + a[2] >= a[3])
        printf("quadrangle\n");
    else
        printf("banana\n");
}
/**/
void input()
{
    int i;
    int ntest;
    scanf("%d",&ntest);
    while(ntest--)
    {
        for(i=0;i<4;i++)
            scanf("%ld",&a[i]);
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
