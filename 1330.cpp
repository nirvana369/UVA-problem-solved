/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "1330.inp"
#define fo "1330.out"
/**/
using namespace std;
/**/
int a[1100],h[1100];
/**/
void input()
{
    int i,j,k;
    int ntest;
    long dem,kq;
    int nhang,ncot,tmp;
    char s[4];
    
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d %d",&nhang,&ncot);
        for(i=0;i<ncot;i++)
        {
            a[i] = 0;
            h[i] = 0;
        }
        kq = 0;
        for(i=0;i<nhang;i++)
        {
            for(j=0;j<ncot;j++)
            {
                scanf("%s",&s);
                if(s[0] == 'F')
                    a[j]++;
                else
                {
                    a[j] = 0;
                    h[j] = i+1;
                }
            }
            for(j=0;j<ncot;j++)
                if(a[j])
                {
                    dem = 1;
                    for(k=j+1;k<ncot;k++)
                        if(a[k] >= a[j])
                            dem++;
                        else
                            break;
                    for(k=j-1;k>=0;k--)
                        if(a[k] >= a[j])
                            dem++;
                        else
                            break;
                    tmp = (i+1) - h[j];
                    if(dem * tmp > kq)
                        kq = dem * tmp;
                }
        }
        printf("%ld\n",kq*3);
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
