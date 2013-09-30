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

#define fi "598.inp"
#define fo "598.out"
/**/
using namespace std;
/**/
char a[15][50];
int luu[15];
int n,dau,cuoi,da;
/**/
void xuly(char s[])
{
    int i;
    int l,dem;
    char temp[10];
    
    l = strlen(s);
    s[l] = ' ';
    dau = -1;
    cuoi = -1;
    dem = 0;
    for(i=0;i<=l;i++)
        if(s[i] != ' ')
        {
            if(s[i] == '*')
            {
                dau = 1;
                cuoi = da;
                return;
            }
            temp[dem++] = s[i];
        }
        else
        {
            temp[dem] = 0;
            if(dem != 0)
            {
                if(dau == -1)
                    sscanf(temp,"%d",&dau);
                else
                    sscanf(temp,"%d",&cuoi);
            }
            dem = 0;
        }
    if(cuoi == -1)
        cuoi = dau;
}
/**/
void dq(int id,int j)
{
    int i;
    if(id == n)
    {
        for(i=0;i<n;i++)
        {
            if(i)
                printf(", ");
            printf("%s",a[luu[i]]);
        }
        printf("\n");
        return;
    }
    for(i=j;i<da;i++)
    {
        luu[id] = i;
        dq(id+1,i+1);
    }        
}
/**/
void solve()
{
    int i;
    
    for(i=dau;i<=cuoi;i++)
    {
        printf("Size %d\n",i);
        n = i;
        dq(0,0);
        printf("\n");
    }
}
/**/
void input()
{
    char temp[100];
    int ntest;
    scanf("%d",&ntest);
    gets(temp);
    gets(temp);
    while(ntest--)
    {
        gets(temp);
        da = 0;
        while(true)
        {
            a[da][0] = 0;
            gets(a[da]);
            if(a[da][0] == 0)
                break;
            da++;
        }
        xuly(temp);
        solve();
        if(ntest)
            printf("\n");
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
