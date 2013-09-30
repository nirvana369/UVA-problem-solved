/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "10673.inp"
#define fo "10673.out"
/**/
using namespace std;
/**/
void input()
{
    long x,k,pxk,qxk,i,j,tmp;
    int ntest;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%ld %ld",&x,&k);
        pxk = (int)floor((double)x/k);
        qxk = (int)ceil((double)x/k);
        i = 0;
        while(i*pxk <= x)
        {
            tmp = i * pxk;
            if((x - tmp) % qxk == 0)
            {
                j = (x - tmp) / qxk;
                break;
            }
            i++;
        }
        printf("%ld %ld\n",i,j);
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
