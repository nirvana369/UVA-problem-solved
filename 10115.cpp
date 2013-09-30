/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10115.inp"
#define fo "10115.out"
/**/
using namespace std;
/**/
struct data{
                char s1[1000];
                char s2[1000];
                int len,len2;
            };
data a[1000];
char s[1000];
int n;
/**/
bool kiemtra(char g[],int l,int dau)
{
    int i;
    for(i=0;i<l;i++,dau++)
        if(g[i] != s[dau])
            return false;
    return true;
}
/**/
void replaces(char g[],int l,int dau,int l1,int l2)
{
    int i,dem;
    char temp[1000];
    dem = 0;
    for(i=0;i<dau;i++)
        temp[dem++] = s[i];
    for(i=0;i<l;i++)
        temp[dem++] = g[i];
    for(i=l2;i<l1;i++)
        temp[dem++] = s[i];
    temp[dem] = 0;
    strcpy(s,temp);
}
/**/
void solve()
{
    int i,j;
    int l;
    l = strlen(s);
    i = 0;
    while(i < n)
    {
        for(j=0;j<l;j++)
            if(s[j] == a[i].s1[0] && (j+a[i].len-1) <= l)
            {
                if(kiemtra(a[i].s1,a[i].len,j))
                {
                    replaces(a[i].s2,a[i].len2,j,l,j+a[i].len);
                    l = strlen(s);
                    j = 0;
                }
            }
        i++;
    }
    printf("%s\n",s);
}
/**/
void input()
{
    int i;
    while(true)
    {
        scanf("%d",&n);
        if(!n)
            break;
        gets(s);
        for(i=0;i<n;i++)
        {
            gets(a[i].s1);
            a[i].len = strlen(a[i].s1);
            gets(a[i].s2);
            a[i].len2 = strlen(a[i].s2);
        }
        gets(s);
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
