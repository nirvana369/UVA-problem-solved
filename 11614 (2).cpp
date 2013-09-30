#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "11614.inp"
#define fo "11614.out"
/**/
using namespace std;
/**/
long long a[200500001];
long da;
/**/
void precal()
{
    long long maxvalue;
    maxvalue = 1000000000000000000ll;
    a[1] = 1;
    da = 2;
    while(a[da-1] < maxvalue)
    {
        if(maxvalue - da < a[da-1] || da == 200500000)
            break;
        a[da] = da + a[da-1];
        da++;
    }
}
/**/
void input()
{
    precal();
}
/**/
int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    input();
    return 0;
}
