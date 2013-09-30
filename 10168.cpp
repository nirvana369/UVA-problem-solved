/*
                                                    Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10168.inp"
#define fo "10168.out"
/**/
using namespace std;
/**/
int d[10000010];
long a[6];
long n;
/**/
void precal()
{
    long i,j;
    d[2] = 0;
    d[1] = 0;
    d[0] = 0;
    for(i=2;i<10000000;i++)
        d[i] = 1;
    for(i=2;i<10000000;i++)
    {
        if(d[i] == 1)
        {
            if(i < 3162)
                for(j=i*i;j<=10000000;j+=i)
                    d[j] = 0;
        }
    }
}
/**/
void input()
{
    long i;
    int j;
    bool find;
    precal();
    while(true)
    {
        n = 0;
        scanf("%ld",&n);
        if(!n)
            break;
        find = false;
        if(n % 2 == 0)
        {
            a[1] = 2;
            a[2] = 2;
            n -=4;
        }
        else
        {
            a[1] = 2;
            a[2] = 3;
            n -= 5;
        }
        for(i=n/2;i>1;i--)
        {
            if(d[i] == 1 && d[n-i] == 1)
            {
                find = true;
                a[3] = i;
                a[4] = n-i;
                for(j=1;j<5;j++)
                {
                    if(j != 1)
                        printf(" ");
                    printf("%ld",a[j]);
                }
                printf("\n");
                break;
            }
        }
        if(!find)
            printf("Impossible.\n");
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
