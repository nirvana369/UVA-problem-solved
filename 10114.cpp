/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "10114.inp"
#define fo "10114.out"
/**/
using namespace std;
/**/
void input()
{
    int m[200];
    double tl[200];
    double dpay,loan,emonth,price;
    int n,month,kq;
    int i;
    
    while(scanf("%d %lf %lf %d",&month,&dpay,&loan,&n) == 4)
    {
        if(month < 0)
            break;
        price = dpay + loan;
        emonth = loan / month;
        
        for(i=0;i<n;i++) 
            scanf("%d %lf",&m[i],&tl[i]);
        kq = 0;    
        m[n] = 32767;
        for(i=0;i<n;)
        {
            price *= (1.0 - tl[i]);
            if(loan < price) 
                break;
            loan -= emonth;
            if(m[i+1] <= ++kq)
                ++i;
        }
        printf("%d ",kq);
        if(kq == 1)
            printf("month\n");
        else
            printf("months\n");
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
