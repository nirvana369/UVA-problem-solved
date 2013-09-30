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

#define fi "12403.inp"
#define fo "12403.out"
/**/
using namespace std;
/**/
void input()
{
    long long tk;
    long val;
    char s[20];
    int n;
    
    scanf("%d",&n);
    tk = 0;
    while(n--)
    {
        scanf("%s",&s);
        if(s[0] == 'd')
        {
            scanf("%ld",&val);
            tk += val;
        }
        else
            printf("%lld\n",tk);
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
