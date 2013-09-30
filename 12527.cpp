/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "12527.inp"
#define fo "12527.out"
/**/
using namespace std;
/**/
bool solve(char s[])
{
    int i,j;
    i = 0;
    while(s[i])
    {
        j = i+1;
        while(s[j])
        {
            if(s[i] == s[j])
                return false;
            j++;
        }
        i++;
    }
    return true;
}
/**/
void input()
{
    char s[10];
    int i;
    int dau,cuoi;
    int dem,tg;
    
    while(scanf("%d %d",&dau,&cuoi) == 2)
    {
        dem = 0;
        if(dau > cuoi)
        {
            tg = dau;
            dau = cuoi;
            cuoi = tg;
        }
        for(i=dau;i<=cuoi;i++)
        {
            sprintf(s,"%d",i);
            if(solve(s))
                dem++;
        }
        cout << dem << endl;
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
