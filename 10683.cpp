/*
                                                            Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10683.inp"
#define fo "10683.out"
/**/
using namespace std;
/**/
char s[100];
/**/
void solve()
{
    long temp,h,m,se,tictac;
    char gio[3],phut[3],giay[3],tt[3];
    
    gio[0] = s[0];
    gio[1] = s[1];
    gio[2] = 0;
    phut[0] = s[2];
    phut[1] = s[3];
    phut[2] = 0;
    giay[0] = s[4];
    giay[1] = s[5];
    giay[2] = 0;
    tt[0] = s[6];
    tt[1] = s[7];
    tt[2] = 0;
    sscanf(gio,"%ld",&h);
    sscanf(phut,"%ld",&m);
    sscanf(giay,"%ld",&se);
    sscanf(tt,"%ld",&tictac);
    temp = (h * 3600 + m * 60 + se) * 100 + tictac;
    printf("%07.lf\n",(double)((temp*125)/108));
}
/**/
void input()
{
    while(true)
    {
        s[0] = 0;
        scanf("%s",&s);
        
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
