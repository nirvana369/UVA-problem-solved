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

#define fi "1260.inp"
#define fo "1260.out"
/**/
using namespace std;
/**/
int a[1100];
int n;
/**/
void input()
{
    long tong;
    int i,j,dem;
    int ntest;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d",&n);
        scanf("%d",&a[0]);
        tong = 0;
        for(i=1;i<n;i++)
        {
            dem = 0;
            scanf("%d",&a[i]);
            for(j=i-1;j>=0;j--)
                if(a[i] >= a[j])
                    dem++;
            tong += dem;
        }
        printf("%ld\n",tong);
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
