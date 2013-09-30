/*
                                                    Hoang Linh
                                                    
                                        Problem: JOLLY JUMPERS - 10038 (10038.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10038.inp"
#define fo "10038.out"
/**/
using namespace std;
/**/
int jolly[5000],a[5000],d[40000];
int n;
/**/
int absj(int value)
{
    if(value < 0)
        return value * (-1);
    return value;
}
/**/
void input()
{
    int i;
    bool jjump;
    
    while(true)
    {
        n = 0;
        scanf("%d",&n);
        if(!n)
            break;
        scanf("%d",&a[0]);
        for(i=1;i<n;i++)
        {
            scanf("%d",&a[i]);
            jolly[i] = absj(a[i] - a[i-1]);
            d[jolly[i]] = 0;
        }
        jjump = true;
        for(i=1;i<n;i++)
        {
            d[jolly[i]]++;
            if(jolly[i] > n-1 || jolly[i] == 0 || d[jolly[i]] > 1)
            {
                jjump = false;
                break;
            }
        }
        if(jjump)
            printf("Jolly\n");
        else
            printf("Not jolly\n");
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
