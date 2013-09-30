/*
                                                    Hoang Linh
                                                    
                                            Problem: AUTOMATIC POETRY - 10361 (10361.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10361.inp"
#define fo "10361.out"
/**/
using namespace std;
/**/
char s1[1000],s2[1000],s3[1000],s4[1000];
/**/
void xuly(char s[])
{
    int i,j;
    int l,dem;
    l = strlen(s);
    for(i=0;i<l;i++)
    {
        if(s[i] == '<')
            break;
        printf("%c",s[i]);
    }
    dem = 0;
    for(j=i+1;j<l;j++)
    {
        if(s[j] == '>')
            break;
        s1[dem] = s[j];
        dem++;
    }
    s1[dem] = 0;
    
    dem = 0;
    for(i=j+1;i<l;i++)
    {
        if(s[i] == '<')
            break;
        s2[dem] = s[i];
        dem++;
    }
    s2[dem] = 0;
    
    dem = 0;
    for(j=i+1;j<l;j++)
    {
        if(s[j] == '>')
            break;
        s3[dem] = s[j];
        dem++;
    }
    s3[dem] = 0;
    
    dem = 0;
    for(i=j+1;i<l;i++,dem++)
        s4[dem] = s[i];
    s4[dem] = 0;
    printf("%s%s%s%s\n",s1,s2,s3,s4);
}
/**/
void solve(char s[])
{
    int i;
    int l;
    l = strlen(s);
    for(i=0;i<l;i++)
    {
        if(s[i] == '.')
            break;
        printf("%c",s[i]);
    }
    printf("%s%s%s%s\n",s3,s2,s1,s4);
}
/**/
void input()
{
    char temp[10000];
    int ntest;
    scanf("%d",&ntest);
    gets(temp);
    while(ntest--)
    {
        gets(temp);
        xuly(temp);
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
