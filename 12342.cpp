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

#define fi "12342.inp"
#define fo "12342.out"
/**/
using namespace std;
/**/
long tax,price;
/**/
void solve()
{
    if(tax <= 180000)
        return;
    if(tax > 1180000)
    {
        price += (long)ceil((tax - 1180000) * 0.25);
        tax = 1180000;
    }
    if(tax > 880000)
    {
        price += (long)ceil((tax - 880000) * 0.2);
        tax = 880000;
    }
    if(tax > 480000)
    {
        price += (long)ceil((tax - 480000) * 0.15);
        tax = 480000;
    }
    if(tax > 180000)
    {
        price += (long)ceil((tax - 180000) * 0.1);
        if(price == 0)
            price += 2000;
    }
    if(price != 0 && price < 2000)
        price = 2000;
}
/**/
void input()
{
    int ntest,id;
    scanf("%d",&ntest);
    id = 1;
    while(ntest--)
    {
        scanf("%ld",&tax);
        price = 0;
        solve();
        printf("Case %d: %ld\n",id++,price);
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
