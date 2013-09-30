/*
                                                    Hoang Linh
                                                    
                                        Problem: HAPPY NUMBER - 10591 (10591.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10591.inp"
#define fo "10591.out"
/**/
using namespace std;
/**/
long luu[1000000];
/**/
void input()
{
    int i,j,ntest;
    long n,temp,value;
    int id;
    id = 1;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%ld",&n);
        temp = n;
        i = 0;
        while(true)
        {
            value = 0;
            while(temp != 0)
            {
                value += (temp % 10) * (temp % 10);
                temp /= 10;
            }
            for(j=0;j<i;j++)
                if(value == luu[j])
                {
                    value = n;
                    break;
                }
            luu[i] = value;
            temp = value;
            if(temp == 1)
                break;
            if(temp == n)
                break;
            i++;
        }
        if(temp == 1)
            printf("Case #%d: %ld is a Happy number.\n",id,n);
        else
            printf("Case #%d: %ld is an Unhappy number.\n",id,n);
        id++;
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
