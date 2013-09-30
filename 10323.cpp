/*
                                                    Hoang Linh
                                                    
                                Problem: FACTORIAL! YOU MUST BE KIDDING!!! - 10323 (10323.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10323.inp"
#define fo "10323.out"
/**/
using namespace std;
/**/
long long f[16];
long n;
/**/
void precal()
{
    int i;
    long long value;
    
    value = 1;
    for(i=2;i<14;i++)
    {
        value = value * i;
        if(i > 7)
            f[i] = value;
    }
}
/**/
void input()
{
    precal();
    
    while(!feof(stdin))
    {
        scanf("%ld",&n);
        if(feof(stdin))
            break;
        if(n < 0)
        {
            n = n * -1;
            if(n % 2 == 0)
                printf("Underflow!\n");
            else
                printf("Overflow!\n");
        }
        else
        {
            if(n < 8)
                printf("Underflow!\n");
            else if(n > 13)
                printf("Overflow!\n");
            else
                printf("%lld\n",f[n]);
        }
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
