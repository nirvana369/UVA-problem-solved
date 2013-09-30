/*
                                                Hoang Linh
                                                
                                    Problem: SIMPLY EMIRP - 10235 (10235.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10235.inp"
#define fo "10235.out"
/**/
using namespace std;
/**/
long n;
int d[1000100];
/**/
void khoitao()
{
    long i;
    for(i=2;i<1000000;i++)
        d[i] = 0;
}
/**/
long rev(long value)
{
    char temp[10];
    long gt;
    int dem;
    dem = 0;
    
    while(value != 0)
    {
        temp[dem] = value % 10 + 48;
        value = value / 10;
        dem++;
    }
    temp[dem] = 0;
    sscanf(temp,"%ld",&gt);
    return gt;
}
/**/
int isnt(long value)
{
    int i;
    int add,temp;
    
    if(value == 2 || value == 3)
        return 1;
    if(value % 2 == 0 || value % 3 == 0)
        return 0;
    add = 2;
    temp = (int)sqrt(value);
    for(i=5;i<=temp;i++)
        if(value % i == 0)
            return 0;
    return 1;
}
/**/
void precal()
{
    long i;
    int n1,n2;
    long r;
    
    khoitao();
    
    for(i=2;i<1000000;i++)
    {
        if(d[i] == 0)
        {
            r = rev(i);
            if(i != r && d[r] == 0)
            {
                n1 = isnt(i);
                n2 = isnt(r);
                if(n1 == 1 && n2 == 1)
                {
                    d[i] = 3;
                    d[r] = 3;
                }
                if(n1 == 0 || n2 == 0)
                {
                    if(n1 == 1)
                    {
                        d[i] = 2;
                        d[r] = 1;
                    }
                    else if(n2 == 1)
                    {
                        d[i] = 1;
                        d[r] = 2;
                    }
                    else
                    {
                        d[i] = 1;
                        d[r] = 1;
                    }
                }
                
            }
            else
            {
                if(isnt(i))
                    d[i] = 2;
                else
                    d[i] = 1;
            }
        }
    }
}
/**/
void input()
{
    precal();
    while(true)
    {
        n = 0;
        scanf("%ld",&n);
        if(!n)
            break;
        if(d[n] == 1)
            printf("%ld is not prime.\n",n);
        else if(d[n] == 2)
            printf("%ld is prime.\n",n);
        else if(d[n] == 3)
            printf("%ld is emirp.\n",n);
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
