/*
                                                    Hoang Linh
                                                
                                        Problem: ERROR CORRECTION - 541 (541.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "541.inp"
#define fo "541.out"
/**/
using namespace std;
/**/
int n,dhang;
int a[110][110],hang[110],cot[110],luu[110];
/**/
void khoitao()
{
    int i;
    for(i=0;i<n;i++)
    {
        hang[i] = 0;
        cot[i] = 0;
    }
    dhang = 0;
}
/**/
void solve()
{
    int i,j;
    int h,c,dem;
    
    dem = 0;
    
    for(i=0;i<n;i++)
        if(cot[i] % 2 != 0)
            dem++;
            
    if(dhang > 1 || dem > 1)
    {
        printf("Corrupt\n");
        return;
    }
    
    for(i=0;i<dhang;i++)
    {
        for(j=0;j<n;j++)
            if(cot[j] % 2 != 0)
            {
                printf("Change bit (%d,%d)\n",luu[i]+1,j+1);
                return;
            } 
    }
    printf("OK\n");
}
/**/
void input()
{
    int i,j;
    while(true)
    {
        scanf("%d",&n);
        if(!n)
            break;
        khoitao();
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&a[i][j]);
                hang[i] = hang[i] + a[i][j];
                cot[j] = cot[j] + a[i][j];
            }
            if(hang[i] % 2 != 0)
            {
                luu[dhang] = i;
                dhang++;
            }
        }
        solve();
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
