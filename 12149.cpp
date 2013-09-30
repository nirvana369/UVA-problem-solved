/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "12149.inp"
#define fo "12149.out"
/**/
using namespace std;
/**/
long s[110];
/**/
void input()
{
    int n;
    int i;
    s[1] = 1;
    for(i=2;i<=100;i++)
        s[i] = i*i + s[i-1];
    while(true)
    {
        scanf("%d",&n);
        if(!n)
            break;
        printf("%ld\n",s[n]);
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
