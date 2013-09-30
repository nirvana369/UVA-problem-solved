/*
                                                        Hoang Linh
                                                        
                                        Problem: LIGHT, MORE LIGHT - 10110 (10110.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10110.inp"
#define fo "10110.out"
/**/
using namespace std;
/**/
long n;
/**/
void solve()
{
    long temp;
    temp = (long)sqrt(n);
    if(temp * temp == n)
        printf("yes\n");
    else
        printf("no\n");
}
/**/
void input()
{
    while(true)
    {
        scanf("%ld",&n);
        if(!n)
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
