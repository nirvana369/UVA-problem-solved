/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "202.inp"
#define fo "202.out"
/**/
using namespace std;
/**/
int d[3010],nguyen[300000],du[300000];
/**/
void khoitao()
{
    int i;
    for(i=0;i<=3000;i++)
        d[i] = 0;
}
/**/
void input()
{
    int a,b;
    long dem,i,j,countn,countrp;
    while(scanf("%d %d",&a,&b) == 2)
    {
        printf("%d/%d = ",a,b);
        dem = 0;
        printf("%d.",a/b);
        if(a % b == 0)
        {
                printf("(0)");
                countrp = 2;
                j = 1;
        }
        else
        {
            khoitao();
            nguyen[0] = a/b;
            a = a % b;
            du[0] = a;
            dem = 1;
            while(true)
            {
                d[a] = 1;
                if(a < b)
                    a = a * 10;
                //printf("%d",a/b);
                nguyen[dem] = a / b;
                if(a % b == 0)
                {
                    for(i=1;i<=dem;i++)
                        printf("%d",nguyen[i]);
                    printf("(0)");
                    countrp = 2;
                    j = 1;
                    break;
                }
                a = a % b;
                du[dem] = a;
                dem++;
                if(d[a] == 1)
                {
                    countn = 0;
                    countrp = dem;
                    for(j=dem-2;j>=0;j--)
                    {
                        if(du[j] == a)
                        {
                            countrp -= j;
                            if(j > 51)
                                break;
                            for(i=1;i<=j;i++)
                            {
                                printf("%d",nguyen[i]);
                                countn++;
                                if(countn == 50)
                                    break;
                            }
                            if(countn == 50)
                                break;
                            printf("(");
                            for(i=j+1;i<dem;i++)
                            {
                                printf("%d",nguyen[i]);
                                countn++;
                                if(countn == 50)
                                    break;
                            }
                            if(countn == 50)
                                printf("...");
                            printf(")");
                            if(countn == 50)
                                break;
                        }
                    }
                    break;
                }
            }
        }
        if(j > 51)
        {
            for(i=1;i<=50;i++)
                printf("%d",nguyen[i]);
            printf("...");
        }
        printf("\n   %ld = number of digits in repeating cycle\n\n",countrp-1);
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
