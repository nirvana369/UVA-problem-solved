/*
                                                Hoang Linh

                                Problem: MACHINED SURFACES - 414 (414.*)
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define fi "msurface.inp"
#define fo "msurface.out"
/**/
using namespace std;
/**/
int n;
int a[30];
int minvalue;
/**/
int xuly(char s[])
{
    int i,l;
    int dem;
    l = strlen(s);
    dem = 0;
    for(i=0;i<l;i++)
        if(s[i] == ' ')
            dem++;
    if(dem < minvalue)
        minvalue = dem;
    return dem;
}
/**/
void input()
{
    int i;
    int tong;
    char temp[30];
    while(true)
    {
        scanf("%d",&n);
        if(n == 0)
            break;
        gets(temp);
        minvalue = 9999;
        for(i=0;i<n;i++)
        {
            gets(temp);
            a[i] = xuly(temp);
        }
        tong = 0;
        for(i=0;i<n;i++)
            tong = tong + a[i] - minvalue;
        printf("%d\n",tong);
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
