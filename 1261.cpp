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

#define fi "1261.inp"
#define fo "1261.out"
/**/
using namespace std;
/**/
int d[30];
int len;
bool het;
/**/
void solve(char s[])
{
    int i,j,dem,k,l;
    char temp[100];
    l = strlen(s);
    if(s[0] == 0)
    {
        het = true;
        return;
    }
    strcpy(temp,s);
    for(i=0;i<l;i++)
    {
        dem = 0;
        for(j=i;j<l;j++)
            if(temp[j] == temp[i])
                dem++;
            else
                break;
                
        if(dem > 1)
        {
            k=0;
            for(j=0;j<i;j++)
                s[k++] = temp[j];
            for(j=i+dem;j<l;j++)
                s[k++] = temp[j];
            s[k] = 0;
            solve(s);
            if(het)
                return;
            i = i+dem-1;
        }
    }
        
}
/**/
void input()
{
    char s[100];
    int ntest;  
    scanf("%d",&ntest);
    gets(s);
    while(ntest--)
    {
        gets(s);
        het = false;
        solve(s);
        if(het)
            printf("1\n");
        else
            printf("0\n");
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
