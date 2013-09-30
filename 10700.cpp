/*
                                                    Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10700.inp"
#define fo "10700.out"
/**/
using namespace std;
/**/
long long n[30],n1[30];
int id,id1;
/**/
void xuly(char s[])
{
    char temp[10000];
    int i;
    int l,dem;
    
    l = strlen(s);
    s[l] = ' ';
    dem = 0;
    id = 0;
    for(i=0;i<=l;i++)
    {
        if(s[i] == '+' || s[i] == '*')
        {
            if(dem != 0)
            {
                temp[dem] = 0;
                sscanf(temp,"%lld",&n[id]);
                id++;
                dem = 0;
            }
            if(s[i] == '+')
            {
                n[id] = -1;
                id++;
            }
            else
            {
                n[id] = 0;
                id++;
            }
        }
        else if(s[i] >= '0' && s[i] <= '9')
        {
            temp[dem] = s[i];
            dem++;   
        }
        else if(s[i] == ' ' && dem != 0)
        {
            temp[dem] = 0;
            sscanf(temp,"%lld",&n[id]);
            id++;
            dem = 0;
        }
    }
    id1 = id;
    for(i=0;i<id;i++)
        n1[i] = n[i];
}
/**/
void solve()
{
    int i,j;
    
    for(i=1;i<id;i=i+2)
        if(n[i] == -1)
        {
            n[i-1] = n[i-1] + n[i+1];
            for(j=i+2;j<id;j++)
                n[j-2] = n[j];
            id = id - 2;
            i=i-2;
        }
        
    for(i=1;i<id;i=i+2)
        if(n[i] == 0)
        {
            n[i-1] = n[i-1] * n[i+1];
            for(j=i+2;j<id;j++)
                n[j-2] = n[j];
            id = id - 2;
            i=i-2;
        }
        
    for(i=1;i<id1;i=i+2)
        if(n1[i] == 0)
        {
            n1[i-1] = n1[i-1] * n1[i+1];
            for(j=i+2;j<id1;j++)
                n1[j-2] = n1[j];
            id1 = id1 - 2;
            i=i-2;
        }
        
    for(i=1;i<id1;i=i+2)
        if(n1[i] == -1)
        {
            n1[i-1] = n1[i-1] + n1[i+1];
            for(j=i+2;j<id1;j++)
                n1[j-2] = n1[j];
            id1 = id1 - 2;
            i=i-2;
        }
    printf("The maximum and minimum are %lld and %lld.\n",n[0],n1[0]);
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
