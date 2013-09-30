/*
                                            Hoang Linh
                                            
                                Problem: DIVIDE, BUT NOT QUITE CONQUER! - 10190 (10190.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10190.inp"
#define fo "10190.out"
/**/
using namespace std;
/**/
long d[100000];
/**/
void input()
{
    int i,j;
    long a,b;
    while(scanf("%ld %ld",&a,&b) == 2)
    {
        gets(temp);
        if(a == 0 || b == 0 || b > a || a == 1)
        {
            printf("Boring!\n");
            continue;
        }
        d[0] = a;
        i = 1;
        while(a % b == 0)
        {
            a /= b;
            d[i] = a;
            if(d[i] == d[i-1])
                break;
            i++;
        }
        if(d[i-1] == 1)
            for(j=0;j<i;j++)
            {
                if(j != 0)
                    printf(" ");
                printf("%ld",d[j]);
            }
        else
            printf("Boring!");
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
