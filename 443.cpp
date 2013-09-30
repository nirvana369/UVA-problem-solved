/*
                                                    Hoang Linh
                                                    
                                     Problem: HUMBLE NUMBERS - 443 (443.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "443.inp"
#define fo "443.out"
/**/
using namespace std;
/**/
int d[6];
long long h[6000];
/**/
void precal()
{
    int i;
    int dem,vt;
    int a[6];
    long long gt[6];
    long long maxgt;
    
    dem = 0;
    
    h[dem] = 1;
    for(i=1;i<5;i++)
        d[i] = 0;
    a[1] = 2;
    a[2] = 3;
    a[3] = 5;
    a[4] = 7;
    while(dem < 5842)
    {
        maxgt = 2000000001;
        for(i=1;i<5;i++)
        {
            gt[i] = a[i] * h[d[i]];
            if(gt[i] < maxgt)
                maxgt = gt[i];
        }
        for(i=1;i<5;i++)
            if(gt[i] == maxgt)
                d[i]++;
        dem++;
        h[dem] = maxgt;
    }
}
/**/
void input()
{
    int n;
    precal();
    while(true)
    {
        scanf("%d",&n);
        if(!n)
            break;
        printf("The %d",n);
        if (n%100>10 && n%100<20)
            printf("th humble number is %lld.\n",h[n-1]);
        else if(n % 10 == 1)
            printf("st humble number is %lld.\n",h[n-1]);
        else if(n % 10 == 2)
            printf("nd humble number is %lld.\n",h[n-1]);
        else if(n % 10 == 3)
            printf("rd humble number is %lld.\n",h[n-1]);
        else
            printf("th humble number is %lld.\n",h[n-1]);
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
