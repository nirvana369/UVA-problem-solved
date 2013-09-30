/*
                                                    Hoang Linh
                                                    
                                        Problem: DIGIT PRIMES - 10533 (10533.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10533.inp"
#define fo "10533.out"
/**/
using namespace std;
/**/
int d[1000010];
/**/
bool isnt(long value)
{
    int i;
    int add,temp;
    if(value == 2 || value == 3)
        return true;
    if(value == 1 || value % 2 == 0 || value % 3 == 0)
        return false;
    temp = (int)sqrt(value);
    add = 2;
    for(i=5;i<=temp;i+=add,add=6-add)
        if(value % i == 0)
            return false;
    return true;
}
/**/
bool checkprime(long value)
{
    int gt;
    gt = 0;
    while(value != 0)
    {
        gt += value % 10;
        value /= 10;
    }
    if(isnt(gt))
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
    for(i=1;i<1000001;i++)
    {
        if(i == 9)
        {
            i = 9;
        }
        if(isnt(i) && checkprime(i))
        {
            temp++;
            d[i] = temp;
        }
        else
            d[i] = temp;
    }
}
/**/
void input()
{
    long l,h,temp;
    int ntest;
    precal();
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%ld %ld",&l,&h);
        if(l > h)
        {
            temp = l;
            l = h;
            h = temp;
        }
        printf("%d\n",d[h]-d[l-1]);
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

