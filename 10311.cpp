/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "10311.inp"
#define fo "10311.out"
#define n 100000000
/**/
using namespace std;
/**/
bool d[n+3];
long nt[4000000];
long dnt;
long n1,n2;
/**/
void _init()
{
    long i,j;
    long tmp,k;
    
    k = (long) sqrt(n);

    d[0] = d[1] = true;
    
    for(i=3;i<=k; i+=2) 
        if(!d[i])
        {
            tmp = i + i;
            if(i <= 10000)
                for(j=i*i;j<=n;j+=tmp) 
                    d[j] = true;
        }
}
/**/
bool solve(long val)
{
    long i,j;
    long id,mid;
    long tmp;
    
    n1 = -1;
    n2 = 0;
    
    if(val % 2)
    {
        if(!d[val - 2] && (val - 2) % 2)
        {
            n1 = 2;
            n2 = val-2;
            return true;
        }
        printf("%ld is not the sum of two primes!\n",val);
        return false;
    }
    
    mid = val / 2 - 1;
    for(i=mid;i>=3;i-=2)
        if((val-i) % 2)
            if(!d[i] && !d[val-i] && i != (val - i))
            {
                n2 = val - i;
                n1 = i;
                break;
            }

    if(!n2 && !d[val - 2] && (val-2) % 2)
    {
        n1 = 2;
        n2 = val - 2;    
    }
    
    if(n1 != -1)
        return true;
    printf("%ld is not the sum of two primes!\n",val);
    return false;
}
/**/
void input()
{
    long val;
    
    _init();
    while(scanf("%ld",&val) == 1)
    {
        if(val < 5)
            printf("%ld is not the sum of two primes!\n",val);
        else
        {
            if(solve(val))
                printf("%ld is the sum of %ld and %ld.\n",val,n1,n2);
        }
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
