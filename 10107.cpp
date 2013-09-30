/*
                                            Hoang Linh
                                            
                                Problem: WHAT IS THE MEDIAN? - 10107 (10107.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10107.inp"
#define fo "10107.out"
/**/
using namespace std;
/**/
long long a[10100];
/**/
void sapxep(int maxa)
{
    int i,j;
    long long temp;
    for(i=0;i<maxa-1;i++)
        if(a[maxa-1] < a[i])
        {
            temp = a[maxa-1];
            for(j=maxa-1;j>i;j--)    
                a[j] = a[j-1];
            a[i] = temp;
            break;
        }
    if(maxa % 2 == 0)
        printf("%lld\n",(a[maxa/2] + a[maxa/2-1])/ 2);
    else
        printf("%lld\n",a[maxa/2]);
}
/**/
void input()
{
    int i;
    i = 0;
    while(scanf("%lld",&a[i]) == 1)
    {
        i++;
        sapxep(i);
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
