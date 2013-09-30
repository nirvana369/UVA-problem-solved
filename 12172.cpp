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

#define fi "12172.inp"
#define fo "12172.out"
#define maxgt 888888888888888ll // max 120 que diem =))
/**/
using namespace std;
/**/
int m[11],d[105];
long long gt[110];
int n;
/**/
void khoitao()
{
    m[0] = 6;
    m[1] = 2;
    m[2] = 5;
    m[3] = 5;
    m[4] = 4;
    m[5] = 5;
    m[6] = 6;
    m[7] = 3;
    m[8] = 7;
    m[9] = 6;
}
/**/
void dcow()
{
    int i,j;
    long long temp;
    d[0] = 1;
    gt[0] = 0; 
    for(i=1;i<101;i++)
        gt[i] = maxgt;
    for(i=0;i<=100;i++)    
        if(d[i] != 0)
            for(j=0;j<10;j++)
            {
                temp = gt[i] * 10 + j;
                if(temp != 0 && temp < gt[i + m[j]])
                {
                    gt[i + m[j]] = temp;
                    d[i + m[j]] = 1;
                }
            }
}
/**/
void output()
{
    int i;
    printf("%lld ",gt[n]);
    if(n % 2 == 0)
        for(i=0;i<n/2;i++)
            printf("1");
    else
    {
        printf("7");
        for(i=(n-3)/2;i>0;i--)
            printf("1");
    }
    printf("\n");
}
/**/
void input()
{
    int ntest;
    khoitao();
    dcow();
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d",&n);
        output();
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
