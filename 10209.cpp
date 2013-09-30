#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <queue>
#include <iostream>

#define fi "10209.inp"
#define fo "10209.out"
/**/
using namespace std;
/**/
float a,pi;
/**/
void solve()
{
    float stron;
    stron = a*a*pi;
    stamgiac = a*a;
    temp = stron / 2;     // lay 1/2 s duong tron
    //temp = stamgiac - temp; // 1/2 hinh qua tram
    temp = stamgiac - temp / 2;
    hv1 = a/2 * a/2;
}
/**/
void input()
{
    pi = acos(-1);
    while(!fi.eof(stdin))
    {
        scanf("%f",&a);
        if(fi.eof(stdin))
            break;
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
