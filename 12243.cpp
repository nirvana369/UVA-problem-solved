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

#define fi "12243.inp"
#define fo "12243.out"
/**/
using namespace std;
/**/
void solve(char s[],int len)
{
    int i;
    int first,dem;
    char str[1000];
    
    first = 0;
    dem = 0;
    for(i=0;i<len;i++)
        if(s[i] == ' ')
            first = 0;
        else if(!first)
        {
            if(s[i] > 90)
                str[dem++] = s[i]-32;
            else
                str[dem++] = s[i];
            first = 1;
        }

    for(i=1;i<dem;i++)
        if(str[i] != str[0])
        {
            printf("N\n");
            return;
        }
    printf("Y\n");
}
/**/
void input()
{
    char temp[10000];
    int l;
    while(true)
    {
        gets(temp);
        l = strlen(temp);
        if(temp[0] == '*' && l == 1)
            break;
        solve(temp,l);
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
