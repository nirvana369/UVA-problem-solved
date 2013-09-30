/*
                                                        Hoang Linh
                                                
                                                
                                        Problem: ANT ON A CHESSBOARD - 10161 (10161.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10161.inp"
#define fo "10161.out"
/**/
using namespace std;
/**/
long long getmin(long long a,long long b)
{
    if(a > b)
        return b;
    return a;
}
/**/
void input()
{
    int i;
    long long n,x,y,nc,temp;
    while(true)
    {
        scanf("%lld",&n);
        if(!n)
            break;
        x = (long long)sqrt(n);
        nc = x;
        y = 1;
        n = n - x * x;
        if(n > 0)
        {
            x++;
            n--;
        }
        
        if(n > 0)
        {
            temp = getmin(n,nc);
            y += temp;
            n -= temp;
        }
        
        if(n > 0)
            x -= n;
        if(nc % 2 == 0)
        {
            temp = x;
            x = y;
            y = temp;
        }
        printf("%lld %lld\n",y,x);
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
