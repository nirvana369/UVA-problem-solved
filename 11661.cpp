/*
                                                                Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "11661.inp"
#define fo "11661.out"
/**/
using namespace std;
/**/
long len;
/**/
void solve(char s[])
{
    long i;
    long dd,distance,dau;
    char kt;
    
    distance = 2000000;
    kt = 0;
    for(i=0;i<len;i++)
    {
        if(s[i] == 'Z')
        {
            distance = 0;
            break;
        }
        else if(s[i] == 'D' || s[i] == 'R')
        {
            if(s[i] != kt && kt != 0)
            {
                dd = i - dau;
                if(dd < distance)
                    distance = dd;
            }
            kt = s[i];
            dau = i;
        }
    }
    printf("%ld\n",distance);
}
/**/
void input()
{
    char temp[2000010];
    while(true)
    {
        scanf("%d",&len);
        if(!len)
            break;
        cin.ignore();
        gets(temp);
        solve(temp);
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
