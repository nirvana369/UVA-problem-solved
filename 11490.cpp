/*
                                                                Hoang Linh
10490                                                            
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "11490.inp"
#define fo "11490.out"
/**/
using namespace std;
/**/
long long d[33];
/**/
bool isnt(int value)
{
    int i;
    int add,temp;
    
    if(value == 2 || value == 3)
        return true;
    if(value == 1 || value % 2 == 0 || value % 3 == 0)
        return false;
    add = 2;
    temp = (int)sqrt(value);
    for(i=5;i<=temp;i+=add,add=6-add)
        if(value % i == 0)
            return false;
    return true;
}
/**/
long long mu(int bac)
{
    int i;
    long long value;
    value = 1;
    for(i=0;i<bac;i++)
        value = value * 2;
    return value;
}
/**/
void precal()
{
    int i;
    
    for(i=4;i<31;i++)
        if(isnt(i))
            d[i] = 1;
        else
            d[i] = 0;
    d[2] = mu(1) * (mu(2) - 1);
    d[3] = mu(2) * (mu(3) - 1);
    d[5] = mu(4) * (mu(5) - 1);
    d[7] = mu(6) * (mu(7) - 1);
    d[13] = mu(12) * (mu(13) - 1);
    d[19] = mu(18) * (mu(19) - 1);
    d[17] = mu(16) * (mu(17) - 1);
    d[31] = mu(30) * (mu(31) - 1);
}
/**/
void input()
{
    int n;
    precal();
    while(true)
    {
        scanf("%d",&n);
        if(!n)
            break;
        if(d[n] > 1)
            printf("Perfect: %lld!\n",d[n]);
        else if(d[n] == 1)
            printf("Given number is prime. But, NO perfect number is available.\n");
        else
            printf("Given number is NOT prime! NO perfect number is available.\n");
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
