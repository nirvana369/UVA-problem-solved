/*
                                                Hoang Linh
                                                
                                    Problem: SELF NUMBERS - 640 (640.*)
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define fo "640.out"
/**/
using namespace std;
/**/
int d[1000010];
/**/
void pht(long value)
{
    long temp;
    
    if(value > 1000000)
        return;
    temp = value;
    while(value != 0)
    {
        temp = temp + value%10;
        if(value >= 10)
            value = value / 10;
        else
            break;
    }
    if(d[temp] == 1)
        return;
    d[temp] = 1;
    pht(temp);
}
/**/
void khoitao()
{
    long i;
    for(i=1;i<=1000000;i++)
        d[i] = 0;
}
/**/
void input()
{
    long i;
    khoitao();
    for(i=1;i<=1000000;i++)
        if(d[i] == 0)
        {
            pht(i);
            printf("%ld\n",i);
        }
}
/**/
int main()
{
    freopen(fo,"w",stdout);
    input();
    return 0;
}
