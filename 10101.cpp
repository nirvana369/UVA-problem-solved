/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "10101.inp"
#define fo "10101.out"
/**/
using namespace std;
/**/
void solve(long long gt)
{
    bool space;
    int tmp;
    
    space = false;
        
    tmp = gt / 10000000;
    if(tmp)
    {
        printf("%d kuti",tmp);   
        gt %= 10000000;
        space = true;
    }
    
    tmp = gt / 100000;
    if(space && tmp)
    {
        printf(" ");
        space = false;
    }
    if(tmp)
    {
        printf("%d lakh",tmp);   
        gt %= 100000;
        space = true;
    }
    
    tmp = gt / 1000;
    if(space && tmp)
    {
        printf(" ");
        space = false;
    }
    if(tmp)
    {
        printf("%d hajar",tmp);   
        gt %= 1000;
        space = true;
    }
    
    tmp = gt / 100;
    if(space && tmp)
    {
        printf(" ");
        space = false;
    }
    if(tmp)
    {
        printf("%d shata",tmp);   
        gt %= 100;
        space = true;
    }
    
    if(gt)
    {
        if(space)
            printf(" ");
        printf("%d",gt);
    }
}
/**/
void input()
{
    int id;
    long long n;
    id = 1;
    while(scanf("%lld",&n) == 1)
    {
        printf("%4d. ",id++);
        if(!n)
        {
            printf("%d\n",n);
            continue;
        }
        while(n / 10000000)
        {
            solve(n / 10000000);
            n = n % 10000000;
            printf(" kuti");
            if(n)
                printf(" ");
        }
        solve(n);
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
