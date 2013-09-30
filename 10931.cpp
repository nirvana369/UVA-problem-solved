/*
                                                    Hoang Linh
                                                    
                                            Problem: PARITY - 10931 (10931.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10931.inp"
#define fo "10931.out"
/**/
using namespace std;
/**/
long n;
/**/
void solve()
{
    char temp[10000];
    int dem,p;
    int i;
    dem = 0;
    p = 0;
    while(n != 0)
    {
        temp[dem] = n % 2 + 48;
        if(temp[dem] == '1')
            p++;
        n = n / 2;
        dem++;
    }
    printf("The parity of ");
    for(i=dem-1;i>=0;i--)
        printf("%c",temp[i]);
    printf(" is %d (mod 2).\n",p);
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
