/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10394.inp"
#define fo "10394.out"
/**/
using namespace std;
/**/
long maxnt;
long nt[100010];
int d[20000010];
/**/
void precal()
{
    long i,j;
    
    for(i=2;i<=20000000;i++)
        d[i] = 1;
    d[1] = 0;
    d[0] = 0;
    i = 2;
    maxnt = 1;
    while(i <= 20000000)
    {
        if(d[i] == 1)
        {
            if(d[i - 2] == 1)
                nt[maxnt++] = i - 2;
            if(i < 4473)
                for(j=i*i;j<=20000000;j+=i)
                    d[j] = 0;
        }
        if(i == 2)
            i++;
        else 
            i += 2;
    }
}
/**/
void input()
{
    long n;
    precal();
    while(true)
    {
        n = 0;
        scanf("%ld",&n);
        if(!n)
            break;
        printf("(%ld, %ld)\n",nt[n],nt[n]+2);
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
