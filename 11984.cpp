/*
                                                    Hoang Linh

*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define fi "11984.inp"
#define fo "11984.out"
/**/
using namespace std;
/**/
float c,f;
/**/
void solve()
{
    float f1;
    if(c == 0)
        f1 = 32;
    else
        f1 = (9*c/5 + 32);
    f = f + f1;
    c = (f - 32)*5/9;
    printf(" %0.2f\n",c);
}
/**/
void input()
{
    int itest;
    int ntest;
    scanf("%d",&ntest);
    for(itest=0;itest<ntest;itest++)
    {
        scanf("%f %f",&c,&f);
        printf("Case %d:",itest+1);
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
