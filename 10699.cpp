/*
                                                Hoang Linh
                                                
                                    Problem: COUNT THE FACTORS - 10699 (10699.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10699.inp"
#define fo "10699.out"
/**/
using namespace std;
/**/
long nt[1000000];
long maxnt;
/**/
bool isnt(long value)
{
    int i;
    int add,temp;
    
    if(value == 3 || value == 2)
        return true;
    if(value <= 1 || value % 2 == 0 || value % 3 == 0)
        return false;
    add = 2;
    temp = (int)sqrt(value);
    for(i=5;i<=temp;i+=add,add=6-add)
        if(value % i == 0)
            return false;
    return true;
}
/**/
void precal()
{
    long i;
    maxnt = 0;
    for(i=1;i<1000001;i++)
        if(isnt(i))
            nt[maxnt++] = i;
}
/**/
void input()
{
    long i;
    precal();
    long n;
    int dem;
    while(true)
    {
        scanf("%ld",&n);
        if(!n)
            break;
        dem = 0;
        for(i=0;i<maxnt;i++)
            if(n % nt[i] == 0)
                dem++;
        printf("%ld : %d\n",n,dem);
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
