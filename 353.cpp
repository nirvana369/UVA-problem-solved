/*
                                                                Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "353.inp"
#define fo "353.out"
/**/
using namespace std;
/**/
char s[100],dg[10000][80];
int d[300];
int demp;
/**/
bool palin(int dau,int cuoi)
{
    while(dau < cuoi)
    {
        if(s[dau] != s[cuoi])
            return false;
        dau++;
        cuoi--;
    }
    return true;
}
/**/
void solve()
{
    int i,j,k;
    int l,doiguong,dem;
    char temp[100];
    l = strlen(s);
    
    doiguong = 0;
    for(i=0;i<300;i++)
        d[i] = 0;
        
    for(i=0;i<l;i++)
        if(d[s[i]] == 0)
        {
            d[s[i]] = 1;
            doiguong++;
        }
        
    demp = 0;
    for(i=0;i<l-1;i++)
        for(j=l-1;j>i;j--)
        {
            if(s[i] == s[j])
                if(palin(i,j))
                {
                    dem = 0;
                    for(k=i;k<=j;k++)
                        temp[dem++] = s[k];
                    temp[dem] = 0;
                    for(k=0;k<demp;k++)
                        if(strcmp(temp,dg[k]) == 0)
                            break;
                    if(k == demp)
                    {
                        doiguong++;
                        strcpy(dg[demp],temp);
                        demp++;
                    }
                }
        }
    printf("The string '%s' contains %d palindromes.\n",s,doiguong);
}
/**/
void input()
{
    while(true)
    {
        s[0] = 0;
        gets(s);
        if(s[0] == 0)
            break;
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
