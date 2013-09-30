/*
                                                    Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "612.inp"
#define fo "612.out"
/**/
using namespace std;
/**/
int nhang,ncot;
int d[200],bac[200],tt[200];
char a[200][200];
/**/
int xuly(char s[])
{
    int i,j;
    int l,dem;
    dem = 0;
    l = strlen(s);
    for(i=0;i<l-1;i++)
        for(j=i+1;j<l;j++)
            if(d[s[i]] < d[s[j]])
                dem++;
    return dem;
}
/**/
void sapxep()
{
    int i,j;
    char temp[200];
    int tg;
    for(i=0;i<nhang-1;i++)
        for(j=i+1;j<nhang;j++)
            if(bac[i] > bac[j])
            {
                strcpy(temp,a[i]);
                strcpy(a[i],a[j]);
                strcpy(a[j],temp);
                tg = bac[i];
                bac[i] = bac[j];
                bac[j] = tg;
                tg = tt[i];
                tt[i] = tt[j];
                tt[j] = tg;
            }
            else if(bac[i] == bac[j])
                if(tt[i] > tt[j])
                {
                    strcpy(temp,a[i]);
                    strcpy(a[i],a[j]);
                    strcpy(a[j],temp);
                    tg = bac[i];
                    bac[i] = bac[j];
                    bac[j] = tg;    
                    tg = tt[i];
                    tt[i] = tt[j];
                    tt[j] = tg;
                }
}
/**/
void output()
{
    int i;
    for(i=0;i<nhang;i++)
        printf("%s\n",a[i]);
}
/**/
void input()
{
    int i;
    int ntest;
    scanf("%d",&ntest);
    d['A'] = 4;
    d['C'] = 3;
    d['G'] = 2;
    d['T'] = 1;
    while(ntest--)
    {
        scanf("%d %d",&ncot,&nhang);    
        for(i=0;i<nhang;i++)
        {
            scanf("%s",a[i]);
            bac[i] = xuly(a[i]);
            tt[i] = i;
        }
        sapxep();
        output();
        if(ntest != 0)
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
