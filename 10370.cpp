/*
                                                    Hoang Linh
                                                    
                                            
                                        Problem: ABOVE AVERAGE - 10370 (10370.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10370.inp"
#define fo "10370.out"
/**/
using namespace std;
/**/
void input()
{
    double tb,sum;
    double s[1100];
    int dem;
    int i;
    int ntest,n;
    scanf("%d",&ntest);
    
    while(ntest--)
    {
        scanf("%d",&n);
        sum = 0;
        for(i=0;i<n;i++)
        {
            scanf("%lf",&s[i]);
            sum = sum + s[i];
        }
        tb = sum / n;
        dem = 0;
        for(i=0;i<n;i++)
            if(s[i] > tb)
                dem++;
        tb = (double)dem * 100 / n;
        printf("%2.3lf%%\n",tb);
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
