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

#define fi "10963.inp"
#define fo "10963.out"
/**/
using namespace std;
/**/
void input()
{
    int i;
    int minus,north,south;
    int ntest,n;
    bool yes;
    
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d",&n);
        yes = true;
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&north,&south);
            if(i)
            {
                if(minus != (north - south))
                    yes = false;                
            }
            else
                minus = north - south;
        }
        if(yes)
            printf("yes\n");
        else
            printf("no\n");
        if(ntest)
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
