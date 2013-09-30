/*
                                                            Hoang Linh
                                                            
                                                    Problem: GCD - 11417 (11417.*)                                             
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "11417.inp"
#define fo "11417.out"
/**/
using namespace std;
/**/
long ucln(int a,int b)
{
    int r;
    while(b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}
/**/
void input()
{
    int n;
    int i,j;
    long sum;
    while(true)
    {
        scanf("%d",&n);
        if(!n)
            break;
        sum = 0;
        for(i=1;i<n;i++)
            for(j=i+1;j<=n;j++)
                sum += ucln(i,j);
        printf("%ld\n",sum);
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
