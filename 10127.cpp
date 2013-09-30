/*
                                                Hoang Linh
                                                
                                        Problem: ONES - 10137 (10127.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10127.inp"
#define fo "10127.out"
/**/
using namespace std;
/**/
int n;
/**/
/*int solve()
{
    int dem,temp;
    int value;
    
    if(n > 9999)
        dem = 5;
    else if(n > 999)
        dem = 4;
    else if(n > 99)
        dem = 3;
    else
        dem = 2;
        
    while(true)
    {
        temp = dem;
        value = 1;
        while(true)
        {
            while(value < n && temp > 1)
            {
                value = value * 10 + 1;
                temp--;
            }
            value = value % n;
            if(temp == 1)
            {
                if(value == 0)
                    break;
                if(value < n)
                    break;
            }
            
        }
        if(value == 0)
            break;
        dem++;
    }
    printf("%d\n",dem);
}*/
/**/
void solve()
{
    int dem;
    long value;
    
    dem = 1;
    value = 1;
    
    while(true)
    {
        if(value >= n)
            value = value % n;
        if(value == 0)
            break;
        dem++;
        value = value * 10 + 1;
    }
    printf("%d\n",dem);
}
/**/
void input()
{
    int dem;
    long long kq;
    while(true)
    {
        n = -1;
        scanf("%d",&n);
        if(n == -1)
            return;
        if(n == 0)
            printf("1\n");
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
