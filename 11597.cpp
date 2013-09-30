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

#define fi "11597.inp"
#define fo "11597.out"
/**/
using namespace std;
/**/
void input()
{
    int id;
    int n;
    id = 1;
    while(scanf("%d",&n))
    {
        if(!n)
            break;
        printf("Case %d: %d\n",id++,n/2);
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
