/*
                                                            Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "11364.inp"
#define fo "11364.out"
/**/
using namespace std;
/**/
void input()
{
    int ntest;
    int i;
    int n,minp,maxp,temp;
    
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d",&n);
        maxp = 0;
        minp = 2000;
        for(i=0;i<n;i++)
        {
            scanf("%d",&temp);
            if(temp > maxp)
                maxp = temp;
            if(temp < minp)
                minp = temp;
        }
        printf("%d\n",(maxp-minp)*2);
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
