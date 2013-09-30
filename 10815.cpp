/*
                                                    Hoang Linh
                                                    
                                    Problem: ANDY'S FIRST DICTIONARY - 10815 (10815.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10815.inp"
#define fo "10815.out"
/**/
using namespace std;
/**/
char dic[30000][300];
int maxdic;
/**/
void kiemtra(char s[])
{
    int i;
    for(i=0;i<maxdic;i++)
        if(strcmp(s,dic[i]) == 0)
            return;
    strcpy(dic[maxdic],s);
    maxdic++;
}
/**/
void xuly(char s[])
{
    int i;
    char temp[500];
    int l,dem;
    l = strlen(s);
    s[l] = ' ';
    dem = 0;
    for(i=0;i<=l;i++)
    {
        if(!((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')) && dem != 0)
        {
            temp[dem] = 0;
            kiemtra(temp);
            dem = 0;
        }
        else if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
        {
            if(s[i] < 97)
                s[i] +=32;
            temp[dem] = s[i];
            dem++;
        }
    }
}
/**/
void solve()
{
    int i,j;
    char temp[1000];
    for(i=0;i<maxdic-1;i++)
    {
        for(j=i+1;j<maxdic;j++)
            if(strcmp(dic[i],dic[j]) > 0)
            {
                strcpy(temp,dic[i]);
                strcpy(dic[i],dic[j]);
                strcpy(dic[j],temp);
            }
        printf("%s\n",dic[i]);
    }
    printf("%s\n",dic[maxdic-1]);
}
/**/
void input()
{
    char temp[1000];
    maxdic = 0;
    while(!feof(stdin))
    {
        gets(temp);
        if(feof(stdin))
            break;
        xuly(temp);
    }
    solve();
}
/**/
int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    input();
    return 0;
}
