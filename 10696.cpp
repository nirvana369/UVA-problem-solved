/*
                                            Hoang Linh
                                            
                                    Problem: F91 - 10696 (10696.*)
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define fi "10696.inp"
#define fo "10696.out"
/**/
using namespace std;
/**/
long f91(long value)
{
    if(value <= 100)
        return f91(f91(value+11));
    return value - 10;
}
/**/
void input()
{
    long n,kq;
    scanf("%ld",&n);
    while(n != 0)
    {
        kq = f91(n);
        printf("f91(%ld) = %ld\n",n,kq);
        scanf("%ld",&n);
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
