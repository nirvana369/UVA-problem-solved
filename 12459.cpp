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
#include <vector>

#define fi "12459.inp"
#define fo "12459.out"
/**/
using namespace std;
/**/
long long bee[85];
/**/
void input()
{
    int i;
    int n;
    
    bee[1] = 1;
    bee[2] = 2;
    for(i=3;i<81;i++)
        bee[i] = bee[i-1] + bee[i-2];
    
    while(scanf("%d",&n) == 1)
    {
        if(!n)
            break;
        printf("%lld\n",bee[n]);
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
