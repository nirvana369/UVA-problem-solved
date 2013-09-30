/*
                                                Hoang Linh
                                                
                                    Problem: POWER CRISIS - 151 (power.*) 
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define fi "151.inp"
#define fo "151.out"
/**/
using namespace std;
/**/
int temp1[110],temp2[110];
int n;
/**/
void khoitao()
{
    int i,j;
    j = 1;
    for(i=2;i<=n;i++)
    {
        temp1[j] = i;
        j++;
    }
}
/**/
int solve()
{
    if(n == 13)
        return 1;
    int i,j;
    int maxd,dem,flag,lim;
    bool sai;
    for(i=1;i<250;i++)
    {
        khoitao();
        lim = n;
        maxd = n;
        dem = 1;
        flag = 1;
        sai = false;
        while(maxd != 1)
        {
            maxd = 1;
            if(flag == 1)
            {
                for(j=1;j<lim;j++)
                    if(dem != i)
                    {
                        temp2[maxd] = temp1[j];
                        dem++;
                        maxd++;
                    }
                    else
                    {
                        if(temp1[j] == 13)
                        {
                            sai = true;
                            break;
                        }
                        dem = 1;
                    }
                flag = 0;
            }
            else if(flag == 0)
            {
                for(j=1;j<lim;j++)
                    if(dem != i)
                    {
                        temp1[maxd] = temp2[j];
                        dem++;
                        maxd++;
                    }
                    else
                    {
                        if(temp2[j] == 13)
                        {
                            sai = true;
                            break;
                        }
                        dem = 1;
                    }
                flag = 1;
            }
            if(sai)
                break;
            if(maxd == 2)
                return i;
            lim = maxd;
        }
    }
}
/**/
void input()
{
    int kq;
    while(true)
    {
        scanf("%d",&n);
        if(n == 0)
            break;
        kq = solve();
        printf("%d\n",kq);
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
