/*
                                            Hoang Linh
                                        
                                    Problem: SIMPLY SUBSETS - 496 (496.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "496.inp"
#define fo "496.out"
/**/
using namespace std;
/**/
int a[10000],b[10000],d[10000];
int maxa,maxb;
/**/
void xuly(char s[])
{
    int i;
    int l,dem;
    char temp[10000];
    
    l = strlen(s);
    s[l] = ' ';
    dem = 0;
    maxa = 0;
    for(i=0;i<=l;i++)
        if(s[i] == ' ' && dem != 0)
        {
            temp[dem] = 0;
            sscanf(temp,"%d",&a[maxa]);
            d[maxa] = 0;
            maxa++;
            dem = 0;
        }
        else if(s[i] != ' ')
        {
            temp[dem] = s[i];
            dem++;
        }
}
/**/
void solve(char s[])
{
    int i,j;
    int l,dem;
    int same,value;
    char temp[10000];
    
    l = strlen(s);
    s[l] = ' ';
    dem = 0;
    maxb = 0;
    same = 0;
    
    for(i=0;i<=l;i++)
        if(s[i] == ' ' && dem != 0)
        {
            temp[dem] = 0;
            sscanf(temp,"%d",&value);
            
            for(j=0;j<maxa;j++)
                if(value == a[j] && d[j] == 0)
                {
                    d[j] = 1;
                    same++;
                }
            maxb++;
            dem = 0;
        }
        else if(s[i] != ' ')
        {
            temp[dem] = s[i];
            dem++;
        }
        
    if(same == maxa && same == maxb)
        printf("A equals B\n");
    else if(same == 0)
        printf("A and B are disjoint\n");
    else if(same < maxa && same < maxb)
        printf("I'm confused!\n");
    else if(same == maxa || same == maxb)
    {
        if(maxa > maxb)
            printf("B is a proper subset of A\n");
        else
            printf("A is a proper subset of B\n");
    }
}
/**/
void input()
{
    char temp[20000];
    while(true)
    {
        temp[0] = 0;
        gets(temp);
        if(temp[0] == 0)
            break;
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
