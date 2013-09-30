/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <queue>
#include <iostream>

#define fi "12293.inp"
#define fo "12293.out"
/**/
using namespace std;
/**/
bool f[1000000010];
/**/
void input()
{
    long n;
    long long temp;
    
    while(scanf("%ld",&n) == 1)
    {
        if(!n)
            break;
        temp = 3;
        while(temp < n)
            temp = temp * 2 + 1;
        
        if(temp == n)
            printf("Bob\n");
        else
            printf("Alice\n");
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
