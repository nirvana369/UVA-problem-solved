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

#define fi "12502.inp"
#define fo "12502.out"
/**/
using namespace std;
/**/
/**/
void input()
{
    int ntest;
    float temp,kq,z;
    int a,b;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d %d %f",&a,&b,&z);
        if(a / b >= 2)
            kq = z;
        else if(b / a >= 2)
            kq = 0;
        else
        {
            temp = z / (a+b);
            if(a > b)
                kq = temp * a + temp * (a-b);
            else
                kq = temp * a - temp * (b-a);
        }
        printf("%d\n",(int)kq);
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
