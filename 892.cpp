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
#include <vector>

#define fi "892.inp"
#define fo "892.out"
/**/
using namespace std;
/**/
char s[100],temp[100];
int dem,len;
bool nextline;
/**/
void solve()
{
    int i,j;
    
    for(i=0;i<len;i++)
        if(s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z' || s[i] == '-')
            temp[dem++] = s[i];
        else
        {
            if(dem != 0)
            {
                for(j=0;j<dem;j++)
                    if(temp[j] != '-')
                        printf("%c",temp[j]);
                if(nextline)
                {
                    printf("\n");
                    nextline = false;
                }
                dem = 0;
            }
            if(s[i] == ' ')
                printf(" ");
        }
    if(dem != 0 && temp[dem-1] != '-')
    {
        temp[dem] = 0;
        dem = 0;
        printf("%s",temp);
    }
    printf("\n");
}
/**/
void input()
{
    dem = 0;
    nextline = false;
    while(true)
    {
        gets(s);
        len = strlen(s);
        if(len == 1 && s[0] == '#')
            break;
        solve();
        if(dem != 0)
            nextline = true;
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
