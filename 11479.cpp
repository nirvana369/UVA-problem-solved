/*
                                                    Hoang Linh
                                                    
                                Problem: IS THIS THE EASIEST PROBLEM? - 11479 (11479.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "11479.inp"
#define fo "11479.out"
/**/
using namespace std;
/**/
void input()
{
    long a,b,c;
    int ntest;
    int itest;
    scanf("%d",&ntest);
    for(itest=0;itest<ntest;itest++)
    {
        scanf("%ld %ld %ld",&a,&b,&c);
        printf("Case %d: ",itest+1);
        if(!(a <= 0 || b <= 0 || c <= 0))
        {
            if(a + b > c && a + c > b && b + c > a)
            {
                if(a == b && a == c)
                    printf("Equilateral\n");
                else if(a == b || c == a || c == b)
                    printf("Isosceles\n");
                else
                    printf("Scalene\n");
            }
            else
                printf("Invalid\n");
        }
        else
            printf("Invalid\n");
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
