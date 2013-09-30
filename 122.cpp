#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "122.inp"
#define fo "122.out"
/**/
using namespace std;
/**/
void resettree()
{
    int i;
    for(i=0;i<2000;i++)
        tree[i] = -1;
    istree = true;
}
/**/
void xly(char s[],int maxd,int value)
{
    int i;
    vt = 1;
    for(i=0;i<maxd;i++)
        if(s[i] == 'L')
            vt = vt * 2;
        else
            vt = vt * 2 + 1;
    if(tree[vt] == -1)
        tree[vt] = value;
    else
        istree = false;
}
/**/
void output()
{
    
}
/**/
void solve(char s[])
{
    int i;
    int l;
    char temp[10000];
    int d;
    int num;
    
    l = strlen(s);
    for(i=0;i<l;i++)
    {
        if(i == '(')
            d = 0;
        if(s[i] >= '0' && s[i] <= '9')
        {
            temp[d] = s[i];
            d++;
        }
        if(s[i] == ',')
        {
            temp[d] = 0;
            sscanf(temp,"%d",&num);
            d = 0;
        }
        if(s[i] == 'L' || s[i] == 'R')
        {
            temp[d] = s[i];
            d++;
        }
        if(s[i] == ')')
        {
            temp[d] = 0;
            if(s[i-1] != '(')
                xly(temp,d,num);
            else
            {
                output();
                resettree();
            }
        }
    }
}
/**/
void input()
{
    char temp[10000];
    resettree();
    while(true)
    {
        temp[0] = 0;
        gets(temp); 
        if(temp[0] == 0)
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
