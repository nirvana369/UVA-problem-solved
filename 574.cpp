/*
                                                            Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "574.inp"
#define fo "574.out"
/**/
using namespace std;
/**/
int tong,n;
int a[20],luu[20];
bool nfind;
/**/
void dequy(int value,int id,int j)
{
    int i;
    int d[110];
    if(value == 0)
    {
        nfind = false;
        for(i=0;i<j;i++)
        {
            if(i != 0)
                printf("+");
            printf("%d",luu[i]);
        }
        printf("\n");
        return;
    }
    if(id == n)
        return;
    for(i=0;i<n;i++)
        d[a[i]] = 0;
    for(i=id;i<n;i++)
        if(value - a[i] >= 0 && d[a[i]] == 0)
        {
            d[a[i]] = 1;
            luu[j] = a[i];
            dequy(value-a[i],i+1,j+1);
        }
}
/**/
void input()
{
    int i;
    int temp;
    while(true)
    {
        scanf("%d %d",&tong,&n);
        if(!n)
            break;
        temp = 0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            temp = temp + a[i];
        }
        printf("Sums of %d:\n",tong);
        nfind = true;
        if(temp < tong)
            printf("NONE\n");
        else
        {
            dequy(tong,0,0);
            if(nfind)
                printf("NONE\n");
        }
        
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
