/*
                                                    Hoang Linh
                                                    
                                        Problem: SQUARE NUMBERS - 11461 (11461.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "11461.inp"
#define fo "11461.out"
/**/
using namespace std;
/**/
int d[100010];
/**/
bool issquare(long value)
{
    int gt;
    gt = (int)sqrt(value);
    if(gt * gt == value)
        return true;
    return false;
}
/**/
void precal()
{
    long i;
    int temp;
    temp = 0;
    d[0] = 0;
    for(i=1;i<=100000;i++)
        if(issquare(i))
        {
            temp++;
            d[i] = temp;
        }
        else
            d[i] = temp;
}
/**/
void input()
{
    int i;
    long a,b;
    precal();
    while(true)
    {
        scanf("%ld %ld",&a,&b);
        if(!a && !b)
            break;
        printf("%d\n",d[b] - d[a-1]);
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
