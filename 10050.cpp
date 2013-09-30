/*
                                                Hoang Linh

                                    Problem: HARTALS - 10050 (10050.*)                                    
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10050.inp"
#define fo "10050.out"
/**/
using namespace std;
/**/
int d[5000];
int nday;
/**/
void khoitao()
{
    int i;
    for(i=1;i<=nday;i++)
        if(d[i] == 1)
            d[i] = 0;
}
/**/
void output()
{
    int i;
    int dem;
    dem = 0;
    for(i=1;i<=nday;i++)
        if(d[i] == 1)
            dem++;
    printf("%d\n",dem);
}
/**/
void ktweek()
{
    int i,j;
    
    for(i=1;i<=3650;i++)
        d[i] = 0;
    
    i = 6;
    j = 7;
    while(i <= 3650 || j <= 3650)
    {
        if(i <= 3650)
        {
            d[i] = 2;
            i = i + 7;
        }
        if(j <= 3650)
        {
            d[j] = 2;
            j = j + 7;
        }
    }
}
/**/
void input()
{
    int itest,i,j;
    int ntest;
    int day,np;
    
    ktweek();
    scanf("%d",&ntest);
    for(itest=0;itest<ntest;itest++)
    {
        scanf("%d %d",&nday,&np);
        for(i=0;i<np;i++)
        {
            scanf("%d",&day);
            j = day;
            while(j <= nday)
            {
                if(d[j] == 0)
                    d[j] = 1;
                j = j + day;
            }
        }
        output();
        if(itest < ntest-1)
            khoitao();
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
