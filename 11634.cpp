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

#define fi "11634.inp"
#define fo "11634.out"
/**/
using namespace std;
/**/
long long n;
int d[10001];
/**/
void khoitao()
{
    int i;
    for(i=0;i<10000;i++)
        d[i] = 0;
}
/**/
void xuly()
{
    int i;
    long long temp;
    int arr[100];
    int dem,dau,cuoi;
    
    dem = 7;
    temp = n;
    while(temp != 0)
    {
        arr[dem--] = temp % 10;
        temp /= 10;
    }
    for(i=dem;i>=0;i--)
        arr[i] = 0;
    n = 0;
    for(i=2;i<6;i++)
    {
        n *= 10;
        n += arr[i];
    }
}
/**/
void solve()
{
    int dem;
    khoitao();
    dem = 0;
    while(true)
    {
        if(d[n] == 0)
            d[n] = 1;
        else
            break;
        n *= n;
        xuly();
        dem++;
    }
    printf("%d\n",dem);
}
/**/
void input()
{
    char s[1000];
    while(true)
    {
        gets(s);
        sscanf(s,"%lld",&n);
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
