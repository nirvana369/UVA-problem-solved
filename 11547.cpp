/*
                                                    Hoang Linh

                                    Problem: AUTOMATIC ANSWER - 11547 (11547.*)
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define fi "11547.inp"
#define fo "11547.out"
/**/
using namespace std;
/**/
void solve(int value)
{
    long gt;
    int kq;
    kq = 0;
    gt = value * 63;
    gt = gt + 7492;
    gt = gt * 5;
    gt = gt - 498;
    gt = gt / 10;
    kq = gt %10;
    if(kq < 0)
        kq = kq * (-1);
    printf("%d\n",kq);
}
/**/
void input()
{
    int itest;
    int ntest;
    int n;
    scanf("%d",&ntest);
    for(itest=0;itest<ntest;itest++)
    {
        scanf("%d",&n);
        solve(n);
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
