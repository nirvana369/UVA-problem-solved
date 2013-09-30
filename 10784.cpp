/*
                                                    Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10784.inp"
#define fo "10784.out"
/**/
using namespace std;
/**/
void input()
{
    double n,kq;
    int id;
    id = 1;
    while(true)
    {
        scanf("%lf",&n);
        if(!(int)n)
            break;
        n = n * 8 + 9;
        n = sqrt(n);
        kq = (3 + n) / 2;
        if(kq - (int)kq > 0)
            printf("Case %d: %ld\n",id,(int)kq+1);
        else
            printf("Case %d: %ld\n",id,(int)kq);
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
