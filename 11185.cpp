/*
                                                        Hoang Linh
                                                        
                                            
                                            Problem: TERNARY - 11185 (11185.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "11185.inp"
#define fo "11185.out"
/**/
using namespace std;
/**/
long a;
/**/
void solve()
{
    char temp[10000];
    int dem;
    int i;
    dem = 0;
    while(a != 0)
    {
        temp[dem] = a % 3 + 48;
        a = a / 3;
        dem++;
    }
    for(i=dem-1;i>=0;i--)
        printf("%c",temp[i]);
    printf("\n");
}
/**/
void input()
{
    while(true)
    {
        scanf("%ld",&a);
        if(a < 0)
            break;
        if(a == 0)
            printf("0\n");
        else
            solve();
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
