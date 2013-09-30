/*
                                                    Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10450.inp"
#define fo "10450.out"
/**/
using namespace std;
/**/
long long wc[60];
/**/
void precal()
{
    int i;
    wc[1] = 2;
    wc[2] = 3;
    for(i=3;i<52;i++)
        wc[i] = wc[i-1] + wc[i-2];
}
/**/
void input()
{
    int itest;
    int ntest,n;
    precal();
    scanf("%d",&ntest);
    for(itest=1;itest<=ntest;itest++)
    {
        scanf("%d",&n);
        printf("Scenario #%d:\n%lld\n\n",itest,wc[n]);
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
