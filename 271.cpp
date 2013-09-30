/*
                                            Hoang Linh
                                        
                                    Problem: SIMPLY SYNTAX - 271 (271.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "271.inp"
#define fo "271.out"
/**/
using namespace std;
/**/
void solve(char s[])
{
    int l;
    int dem;
    dem = 0;
    l = strlen(s)-1;
    while(l >= 0)
    {
        if(s[l] >= 'p' && s[l] <= 'z')
            dem++;
        if(s[l] == 'N')
            if(dem < 1)
            {
                dem = 10;
                break;
            }
        if(s[l] == 'C' || s[l] == 'D' || s[l] == 'E' || s[l] == 'I')
            if(dem >= 2)
                dem--;
            else
            {
                dem = 10;
                break;
            }
        l--;
    }
    if(dem == 1)
        printf("YES\n");
    else
        printf("NO\n");
}
/**/
void input()
{
    char temp[300];
    while(!feof(stdin))
    {
        gets(temp);
        if(feof(stdin))
            break;
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
