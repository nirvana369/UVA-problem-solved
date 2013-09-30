/*
                                                    Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10137.inp"
#define fo "10137.out"
/**/
using namespace std;
/**/
void input()
{
    double add,avr,add1;
    int nguyen,du;
    long sum;
    long m[1100];
    int n;
    int i;
    while(true)
    {
        scanf("%d",&n);
        if(!n)
            break;
        sum = nguyen = du = 0;
        for(i=0;i<n;i++)
        {
            scanf("%d.%d",&nguyen,&du);
            m[i] = nguyen * 100 + du;
            sum = sum + m[i];
        }
        avr = (double)sum / n;
        add = add1 = 0;
        for(i=0;i<n;i++)
            if(m[i] < avr)
                add += (int)(avr - m[i]);
            else if(m[i] > avr)
                add1 += (int)(m[i] - avr);

        if(add > add1)
            printf("$%0.2lf\n",add/100.00);
        else
            printf("$%0.2lf\n",add1/100.00);
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
