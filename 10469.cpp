/*
                                                    Hoang Linh
                                                    
                                     Problem: TO CARRY OR NOT TO CARRY - 10469 (10469.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10469.inp"
#define fo "10469.out"
/**/
using namespace std;
/**/
long long a,b;
char n1[50],n2[50];
/**/
void chuyen(char s[],long long value)
{
    int i;
    int dem;
    dem = 0;
    while(value != 0)
    {
        s[dem] = value % 2 + 48;
        value = value / 2;
        dem++;
    }
    for(i=dem;i<32;i++)
        s[i] = '0';
}
/**/
long long bp(int bac)
{
    int i;
    long long value;
    value = 1;
    for(i=0;i<bac;i++)
        value = value * 2;
    return value;
}
/**/
void solve()
{
    int i,j;
    long long value;
    
    for(i=0;i<32;i++)
    {
        if(n1[i] == '1' && n2[i] == '1')
            n1[i] = '0';
        else if(n1[i] == '1' || n2[i] == '1')
            n1[i] = '1';
        else
            n1[i] = '0';
    }
    
    value = 0;
    for(i=31;i>=0;i--)
        if(n1[i] == '1')
        {
            for(j=i;j>=0;j--)
                if(n1[j] == '1')            
                    value = value + bp(j);
            break;
        }
    printf("%lld\n",value);
}
/**/
void input()
{
    while(scanf("%lld %lld",&a,&b) == 2)
    {
        chuyen(n1,a);
        chuyen(n2,b);
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
