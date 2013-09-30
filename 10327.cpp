/*
                                                    Hoang Linh

                                        Problem: FLIP SORT - 10327 (10327.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10327.inp"
#define fo "10327.out"
/**/
using namespace std;
/**/
int n;
int a[1001];
/**/
void sapxep()
{
    int i;
    bool flip;
    int temp;
    long dem;
    dem = 0;
    
    while(true)
    {
        flip = false;
        for(i=0;i<n-1;i++)        
            if(a[i] > a[i+1])
            {
                flip = true;
                temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
                dem++;
            }
        n--;
        if(!flip)
            break;
    }
    
    printf("Minimum exchange operations : %ld\n",dem);
}
/**/
void input()
{
    int i;
    while(true)
    {
        n = 0;
        scanf("%d",&n);
        if(!n)
            break;
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        sapxep();
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
