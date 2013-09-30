/*
                                                        Hoang Linh
                                                    
                                        Problem: ECOLOGICAL PREMIUM - 10300 (10300.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10300.inp"
#define fo "10300.out"
/**/
using namespace std;
/**/
void input()
{
    long x,y,z;
    long long sum;
    int i;
    int ntest,n;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d",&n);
        sum = 0;
        for(i=0;i<n;i++)
        {
            scanf("%ld %ld %ld",&x,&y,&z);
            sum = sum + x * z;
        }
        printf("%lld\n",sum);
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
