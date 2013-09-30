/*
                                                                Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "11059.inp"
#define fo "11059.out"
/**/
using namespace std;
/**/
void input()
{
    int i,j,n,dem;
    int a[20];
    long long gt[20];
    long long kq,temp;
    int id,dle,maxle,tontai;
    bool mul;
    
    id = 1;
    while(true)
    {
        n = 0;
        scanf("%d",&n);
        if(!n)
            break;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            gt[i] = 0;
        }
        kq = 0;
        temp = 1;
        for(i=0;i<n;i++)
        {
            if(a[i] > gt[0])
                gt[0] = a[i];
            temp = a[i];
            dem = 1;
            for(j=i+1;j<n;j++,dem++)
            {
                temp = temp * a[j];
                if(temp > gt[dem])
                    gt[dem] = temp;
            }
        }
        for(i=0;i<n;i++)
            if(gt[i] > kq)
                kq = gt[i];
        printf("Case #%d: The maximum product is %lld.\n\n",id,kq);
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
