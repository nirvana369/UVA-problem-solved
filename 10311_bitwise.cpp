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
    long tmp;
    
    for(i=3;i<=n;i+=2)
        d[i] = true;
    dnt = 1;
    nt[dnt++] = 2;
    d[0] = d[1] = false;
    d[2] = true;
    
    for(i=3;i<=50000000; i+=2) 
        if(d[i])
        {
            nt[dnt++] = i;
            tmp = i + i;
            if(i <= 10000)
                for(j=i*i;j<=n;j+=tmp) 
                    d[j] = false;
        }
    dnt--;
}
/**/
long binsearch(long dau, long cuoi, long val)
{
    long mid;
    
    if(dau == cuoi)
        return cuoi;

    mid = (dau + cuoi) / 2;
    
    if(val > nt[mid])    
        return binsearch(mid+1,cuoi,val);
    else
        return binsearch(dau,mid,val);
}
/**/
long _abs(long val)
{
    return val > 0 ? val : -val;
}
/**/
bool solve(long val)
{
    long i,j;
    long id,mid;
    long tmp;
    
    id = binsearch(1,dnt,val);
    
    n1 = -1;
    
    mid = (id + 1) / 2;
    i = mid;
    j = mid-1;
    while(i <= id || j > 0)
    {
        if(i <= id)
        {
            tmp = val - nt[i];
            if(tmp % 2 != 0 || tmp == 2)
                if(d[tmp] && nt[i] != tmp)
                {
                    if(n1 == -1)
                    {
                        n1 = nt[i];
                        n2 = tmp;
                    }
                    if(_abs(tmp-nt[i]) < _abs(n1-n2))
                    {
                        n1 = nt[i];
                        n2 = tmp;
                    }
                }
        }
        
        if(j > 0)
        {
            tmp = val - nt[j];
            if(tmp % 2 != 0 || tmp == 2)
                if(d[tmp] && nt[j] != tmp)
                {
                    if(n1 == -1)
                    {
                        n1 = nt[j];
                        n2 = tmp;
                    }
                    if(_abs(tmp-nt[j]) < _abs(n1-n2))
                    {
                        n1 = nt[j];
                        n2 = tmp;
                    }
                }
        }
        i++;
        j--;
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
            {
                if(n1 > n2)
                    printf("%ld is the sum of %ld and %ld.\n",val,n2,n1);
                else
                    printf("%ld is the sum of %ld and %ld.\n",val,n1,n2);
            }
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
