/*
                                                    Hoang Linh
                                                    
                                        Problem: YOU CAN SAY 11 - 10929 (10929.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10929.inp"
#define fo "10929.out"
/**/
using namespace std;
/**/
char n[10000];
/**/
void solve()
{
    int i;
    int l,flag;
    int tong;
    
    printf("%s",n);
    l = strlen(n);
    tong = 0;
    flag = 0;
    tong = n[0] - 48;
    for(i=1;i<l;i++)
    {
        if(flag == 0)
        {
            tong = tong - (n[i] - 48);
            flag = 1;
        }
        else
        {
            tong = tong + (n[i] - 48);
            flag = 0;
        }
    }
    if(tong % 11 == 0)
        printf(" is a multiple of 11.\n");
    else
        printf(" is not a multiple of 11.\n");
}
/**/
void input()
{
    while(true)
    {
        gets(n);
        if(n[0] == '0' && strlen(n) == 1)
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
