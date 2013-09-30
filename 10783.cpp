/*
                                                Hoang Linh
                                                
                                                
                                    Problem: ODD SUM - 10783 (10783.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10783.inp"
#define fo "10783.out"
/**/
using namespace std;
/**/
void input()
{
    int itest,i,j;
    int ntest;
    int temp,a,b,tong;
    scanf("%d",&ntest);
    for(itest=0;itest<ntest;itest++)
    {
        scanf("%d %d",&a,&b);
        if(a > b)
        {
            temp = a;
            a = b;
            b = temp;
        }
        tong = 0;
        for(i=a;i<=b;i++)
            if(i % 2 != 0)
                tong = tong + i;
        printf("Case %d: %d\n",itest+1,tong);
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
