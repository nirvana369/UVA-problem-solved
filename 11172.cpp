/*
                                                    Hoang Linh
                                                
                                    Problem: RELATIONAL OPERATOR - 11172 (11172.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "11172.inp"
#define fo "11172.out"
/**/
using namespace std;
/**/
void input()
{
    long a,b;
    int itest;
    int ntest;
    scanf("%d",&ntest);
    for(itest=0;itest<ntest;itest++)
    {
        scanf("%ld %ld",&a,&b);
        if(a < b)
            printf("<\n");
        else if(a == b)
            printf("=\n");
        else
            printf(">\n");
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
