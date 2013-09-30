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

#define fi "10656.inp"
#define fo "10656.out"
/**/
using namespace std;
/**/
void input()
{
    int i;
    int n,val;
    bool space;
    while(scanf("%d",&n))
    {
        if(!n)
            break;
        space = false;
        for(i=0;i<n;i++)
        {
            scanf("%d",&val);
            if(val)
            {
                if(space)
                    printf(" ");
                else
                    space = true;
                printf("%d",val);
            }
        }
        if(!space)
            printf("0");
        printf("\n");
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
