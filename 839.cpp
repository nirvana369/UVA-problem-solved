/*
                                                                    Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "839.inp"
#define fo "839.out"
/**/
using namespace std;
/**/
int eq;
/**/
int solve()
{
    int wl,dl,wr,dr,tr,tl;

    scanf("%d %d %d %d",&wl,&dl,&wr,&dr);

    if(wl == 0)
        wl = solve();
    tl = wl * dl;
        
    if(wr == 0)
        wr = solve();
    tr = wr * dr;

    if(tr == tl)
        return wl + wr;
    return -1;
}
/**/
void input()
{
    int ntest;
    char temp[10000];
    scanf("%d",&ntest);

    while(ntest--)
    {
        eq = solve();
        if(eq == -1)
            printf("NO\n");
        else
            printf("YES\n");
        if(ntest != 0)
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
