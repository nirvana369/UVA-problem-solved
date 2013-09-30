/*
                                                    Hoang Linh
                                                    
                                                    
                                    Problem: CARMICHAEL NUMBERS - 10006 (10006.*)
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define fi "10006.inp"
#define fo "10006.out"
//
using namespace std;
//
long a,n;
//
long long dequy(long mu)
{
    long long gt;
    if(mu == 0)
        return 1;
    if(mu == 1)
        return a % n;
    gt = dequy(mu/2) % n ;
    return (gt * gt *  dequy(mu%2) % n) % n;
}
//
bool solve()
{
    long i;
    long kq;
    for(i=2;i<n;i++)
    {
        a = i;
        kq = dequy(n);
        if(kq != i)
            return false;
    }
    return true;
}
//
bool isnt(long value)
{
    int i;
    int temp,add;
    
    if(value == 2 || value == 3)
        return true;
    if(value == 1 || value % 2 == 0 || value % 3 == 0)
        return false;
    add = 2;
    temp = (int)sqrt(value);
    
    for(i=5;i<=temp;i=i+add,add=6-add)
        if(value % i == 0)
            return false;
    return true;
}
//
void input()
{
    while(true)
    {
        scanf("%ld",&n);
        if(!n)
            break;
        if(isnt(n))
            printf("%ld is normal.\n",n);
        else
        {
            if(solve())
                printf("The number %ld is a Carmichael number.\n",n);
            else
                printf("%ld is normal.\n",n);
        }
    }
}
//
int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    input();
    return 0;
}
