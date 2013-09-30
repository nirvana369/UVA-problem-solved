/*
                                                    Hoang Linh
                                                    
                                        Problem: VITO'S FAMILY - 10041 (10041.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10041.inp"
#define fo "10041.out"
/**/
using namespace std;
/**/
int a[600];
int n;
/**/
int absn(int value)
{
    if(value < 0)
        return value * -1;
    return value;
}
/**/
void solve()
{
    int i,j;
    int temp;
    long tong;
    
    tong = 0;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
            if(a[i] < a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
    }
    for(i=0;i<n;i++)
        tong = tong + absn(a[n/2] - a[i]);
    printf("%ld\n",tong);
}
/**/
void input()
{
    int itest,i;
    int ntest;
    scanf("%d",&ntest);
    for(itest=0;itest<ntest;itest++)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
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
