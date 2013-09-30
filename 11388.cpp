/*
                                                            Hoang Linh                        
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "11388.inp"
#define fo "11388.out"
/**/
using namespace std;
/**/
void input()
{
    int ntest;
    long ucln,bcnn;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%ld %ld",&ucln,&bcnn);
        if(bcnn % ucln != 0)
            printf("-1\n");
        else
            printf("%ld %ld\n",ucln,bcnn);
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
