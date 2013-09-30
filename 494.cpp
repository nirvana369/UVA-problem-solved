/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "494.inp"
#define fo "494.out"
/**/
using namespace std;
/**/
char s[1000000000];
/**/
void input()
{
    long counter;
    long i,dem;
    
    while(gets(s))
    {
        i = dem = counter = 0;
        while(s[i])
        {
            if(s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z')
                dem++;
            else if(dem != 0)
            {
                counter++;
                dem = 0;
            }
            i++;
        }
        if(dem != 0)
            counter++;
        printf("%ld\n",counter);
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
