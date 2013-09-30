/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <queue>
#include <vector>
#include <iostream>

#define fi "11089.inp"
#define fo "11089.out"
#define maxgt 1000000000l
/**/
using namespace std;
/**/
long trc[maxgt+10];
bool fib[maxgt + 100];
char kq[50];
/**/
void precal()
{
    long i,j;
    fib[1] = true;    
    i = 0;
    j = 1;
    trc[1] = 1;
    while(j < maxgt)
    {
        i++;
        if(fib[i])
        {
            j++;
            fib[j] = false;
            trc[j] = i;
        }
        else
        {
            j++;
            fib[j] = false;
            trc[j] = i;
            
            j++;
            fib[j] = true;
            trc[j] = i;
        }
    }
}
/**/

void input()
{
    int ntest;
    long n;
    int dem,i;
    precal();
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%ld",&n);
        dem = 0;
        while(n != trc[n])
        {
            if(fib[n])
                kq[dem++] = '1';
            else
                kq[dem++] = '0';
            n = trc[n];
        }  
        kq[dem] = '1'; 
        for(i=dem;i>=0;i--)
            printf("%c",kq[i]);
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
