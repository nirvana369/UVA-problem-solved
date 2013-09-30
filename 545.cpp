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

#define fi "545.inp"
#define fo "545.out"
#define m 9000
/**/
using namespace std;
/**/
double val[m+10];
int ndigit[m+10];
/**/
void _init()
{
    int i;
    
    
    val[0] = 1;
    ndigit[0] = 0;
    
    for(i=1;i<=m;i++)
    {
        val[i] = val[i-1] / 2;
        ndigit[i] = ndigit[i-1];
        if(val[i] < 1.0)
        {
            val[i] *= 10; 
            ndigit[i]++; 
        }
    }
}
/**/
void input()
{
    long n;
    int ntest;
    
    _init();
    
    scanf("%d",&ntest);
    while(scanf("%d",&n) == 1)
        printf("2^-%d = %0.3lfE-%d\n",n,val[n]+1e-9,ndigit[n]);
}
/**/
int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    
    input();

    return 0;
}
