/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "11935.inp"
#define fo "11935.out"
/**/
using namespace std;
/**/
int vt[1000],a[1000];
char c[1000];
int n;
/**/
bool solve(double fuel)
{
    int i;
    int lroad,xp,leek;
    double rs;
    
    lroad = xp = leek = 0;
    rs = fuel;    
    for(i=0;i<n;i++)
    {
        fuel = fuel - (vt[i]-xp) * leek - (vt[i]-xp) / 100.00 * lroad;
        if(fuel < 0)
            return false; // thieu xang
        if(c[i] == 'F')
            lroad = a[i];
        else if(c[i] == 'L')
                leek++;
        else if(c[i] == 'M')
                leek = 0;
        else if(c[i] == 'G' && fuel >= 0)
                fuel = rs;
        xp = vt[i];
    }
    return true; // thua xang
}
/**/
void input()
{
    char s[1000];
    double dau,giua,cuoi;
    n = 0;
    while(true)
    {
        scanf("%d %s",&vt[n],&s);
        if(strcmp(s,"Goal") == 0)
        {
            c[n] = s[0];
            cuoi = 0;
            dau = 10000;
            n++;
            while(dau - cuoi > 1e-9)  // binary search
            {
                giua = (dau + cuoi) / 2;
                if(solve(giua))
                    dau = giua;
                else
                    cuoi = giua;
            }
            printf("%.3lf\n",(dau+cuoi)/2);
            n = 0;
        }
        else if(s[0] == 'F')
        {
            c[n] = s[0];
            scanf("%s %d",&s,&a[n]);
           
            if(!a[n] && !vt[n]) // quit condition
                return;
            n++;
        }
        else if(s[0] == 'L' || s[0] == 'M')
        {
            c[n] = s[0];
            n++;
        }
        else
        {
            c[n] = s[0];
            n++;
            scanf("%s",&s);
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
