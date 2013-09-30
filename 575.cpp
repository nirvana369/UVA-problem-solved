/*
                                                        Hoang Linh
                                                
                                            Problem: SKEW BINARY - 575 (575.*)
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define fi "575.inp"
#define fo "575.out"
/**/
using namespace std;
/**/
char text[1000];
long b[33];
/**/
void solve()
{
    int i;
    int l,mu;
    long value;
    l = strlen(text);

    value = 0;
    for(i=0,mu=l;i<l;i++,mu--)
        if(text[i] != '0')
            value = value + ((text[i] - 48) * b[mu]);
    printf("%ld\n",value);
}
/**/
void khoitao()
{
    int i;
    for(i=1;i<=31;i++)
        b[i] = (int)pow(2,i) - 1;
}
/**/
void input()
{
    khoitao();
    while(!feof(stdin))
    {
        gets(text);
        if(text[0] == '0' && strlen(text) == 1)
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
