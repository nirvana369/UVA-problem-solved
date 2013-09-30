/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "11505.inp"
#define fo "11505.out"
/**/
using namespace std;
/**/
void input()
{
    char s[100];
    int ntest,n;
    double pi,goc,tmp,x,y,kc;
    
    pi = acos(-1) / 180.0;
    scanf("%d",&ntest);
    while(ntest--)
    {
        x = y = goc = 0;
        scanf("%d",&n);
        while(n--)
        {
            scanf("%s %lf",&s,&tmp);
            if(s[0] == 'l')
            {
                goc += tmp;
                if(goc > 360)
                    goc -= 360;
            }
            else if(s[0] == 'r')
            {
                goc -= tmp;
                if(goc < 360)
                    goc += 360;
            }
            else if(s[0] == 'f')
            {
                x += tmp * cos(goc * pi);
                y -= tmp * sin(goc * pi);
            }
            else
            {
                x -= tmp * cos(goc * pi);
                y += tmp * sin(goc * pi);
            }
        }
        kc = sqrt(x*x + y*y);
        printf("%.lf\n",kc);
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
