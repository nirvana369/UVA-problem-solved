/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
//#include <queue>
//#include <vector>
//#include <map>

#define fi "12578.inp"
#define fo "12578.out"
/**/
using namespace std;
/**/
void input()
{
    int n;
    double sgreen,sred,l,w,r,pi;
    
    pi = acos(-1);
    scanf("%d",&n);
    while(n--)
    {
        scanf("%lf",&l);
        w = l / 10 * 6;
        r = l / 5;
        sgreen = l * w;
        sred = r * r * pi;
        sgreen -= sred;
        printf("%0.2lf %0.2lf\n",sred,sgreen);
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
