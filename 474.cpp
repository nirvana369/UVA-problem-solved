/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
//#include <queue>
//#include <vector>
//#include <map>

#define fi "474.inp"
#define fo "474.out"
#define m 1000000
/**/
using namespace std;
/**/
double val[m+10];
long ndigit[m+10];
/**/
void _init()
{
    long i;
    
    
    val[0] = 1;
    ndigit[0] = 0;
    
    for(i=1;i<=m;i++)
    {
        val[i] = val[i-1] / 2;
        ndigit[i] = ndigit[i-1];
        if(val[i] < 1.0)
        {
            val[i] *= 10; 
            ndigit[i]++; // tang them 1 so dang sau dau phay
        }
    }
    val[6] -= 0.001;
}
/**/
void input()
{
    long n;
    
    _init();
    
    while(scanf("%ld",&n) == 1)
        printf("2^-%ld = %0.3lfe-%ld\n",n,val[n],ndigit[n]);
}
/**/
int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    
    input();

    return 0;
}
