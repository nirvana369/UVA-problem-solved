#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "light.inp"
#define fo "light.out"
/**/
using namespace std;
/**/
long long light[27];
/**/
void precal()
{
    long long a[4],l[4];
    int i,j;
    a[1] = 1;
    a[2] = 1;
    a[3] = 1;
    l[1] = 3;
    l[2] = 2;
    l[3] = 1;
    light[0] = 1;
    light[1] = 3;
    for(i=1;i<=25;i++)
    {
        light[i+1] = 0;
        for(j=1;j<4;j++)
        {
            a[j] *= l[j];
            light[i+1] += a[j];
        }
    }
}
/**/
void input()
{
    int n;
    precal();
    while(true)
    {
        n = -1;
        scanf("%d",&n);
        if(n == -1)
            break;
        printf("%lld\n",light[n]);
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
