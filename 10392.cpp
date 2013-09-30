/*
                                                                Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10392.inp"
#define fo "10392.out"
/**/
using namespace std;
/**/
int d[1000010];
long nt[80000];
long dnt;
/**/
void precal()
{
    long i,j;
    dnt = 0;
    for(i=2;i<=1000000;i++)
        d[i] = 0;
    for(i=2;i<=1000000;i++)
    {
        if(d[i] == 0)
        {
            nt[dnt++] = i;
            if(i <= 1000)
                for(j=i*i;j<=1000000;j+=i)
                    d[j] = 1;
        }
    }
}
/**/
void input()
{
    long i;
    long long n;
    
    precal();
    while(true)
    {
        scanf("%lld",&n);
        if(n < 0)
            break;
        i = 0;
        while(true)
        {
            if(i == dnt || n == 1)
                break;
            while(n % nt[i] == 0)
            {
                printf("    %ld\n",nt[i]);
                n /= nt[i];
            }
            i++;
        }
        if(n != 1)
            printf("    %lld\n",n);
        printf("\n");
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
