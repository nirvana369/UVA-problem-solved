/*
                                                    Hoang Linh

                                    Problem: COST CUTTING - 11727 (11727.*)
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define fi "11727.inp"
#define fo "11727.out"
/**/
using namespace std;
/**/
void input()
{
    int itest,i;
    int ntest;
    int max1,max2,temp;
    scanf("%d",&ntest);
    for(itest=0;itest<ntest;itest++)
    {
        max1 = 0;
        max2 = 0;
        for(i=0;i<3;i++)
        {
            scanf("%d",&temp);
            if(temp > max1)
            {
                max2 = max1;
                max1 = temp;
            }
            else if(temp > max2)
                max2 = temp;
        }
        printf("Case %d: %d\n",itest+1,max2);
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
