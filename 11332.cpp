/*
                                                    Hoang Linh
                                                    
                                        Problem: SUMMING DIGITS - 11332 (11332.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "11332.inp"
#define fo "11332.out"
/**/
using namespace std;
/**/
char number[100];
/**/
void solve()
{
    int i;
    int tong;
    int l;
    
    while(true)
    {
        l = strlen(number);
        tong = 0;
        for(i=0;i<l;i++)
            tong = tong + number[i] - 48;
        if(tong < 10)
            break;
        sprintf(number,"%d",tong);
    }
    printf("%d\n",tong);
}
/**/
void input()
{
    long temp;
    while(true)
    {
        scanf("%ld",&temp);
        if(!temp)
            break;
        sprintf(number,"%ld",temp);
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
