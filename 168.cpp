/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <iostream>

#define fi "168.inp"
#define fo "168.out"
/**/
using namespace std;
/**/
vector<int > a[28];
bool d[28];
int dau,cuoi;
long long k;
/**/
void khoitao()
{
    int i,j;
    
    for(i=0;i<=26;i++)
    {
        a[i].clear();
        d[i] = false;
    }
}
/**/
void xuly(char s[])
{
    int i,j;
    char temp[10];
    bool flag;
    
    khoitao();
    i = 0;
    flag = 0;
    while(s[i])
    {
        if(s[i] == ';')
            flag = 0;
        if(s[i] == '.')
            break;
        if(s[i] >= 'A' && s[i] <= 'Z')
        {
            if(!flag)
            {
                dau = s[i]-65;
                flag = 1;
            }
            else
                a[dau].push_back(s[i]-65);
        }
        i++;
    }
    
    while(s[i])
    {
        if(s[i] >= 'A' && s[i] <= 'Z')
        {
            dau = s[i] - 65;
            i++;
            break;
        }
        i++;
    }
    
    while(s[i])
    {
        if(s[i] >= 'A' && s[i] <= 'Z')
        {
            cuoi = s[i] - 65;
            i++;
            break;
        }
        i++;
    }
    j = 0;
    while(s[i])
    {
        if(s[i] >= '0' && s[i] <= '9')
            temp[j++] = s[i];
        i++;
    }
    temp[j] = 0;
    sscanf(temp,"%lld",&k);
}
/**/
void dq(int x,int y,long long step)
{
    int i;
    if((step+1) % k == 0)
        d[x] = true;
    for(i=0;i<a[x].size();i++)
        if(a[x][i] != y && !d[a[x][i]])
        {
            if(d[x])
                printf("%c ",x+65);
            int tmp = a[x][i];
            dq(tmp,x,step+1);
            return;
        }
    printf("/%c\n",x+65);
}
/**/
void input()
{
    char s[1000];
    while(true)
    {
        gets(s);
        if(s[0] == '#')
            break;
        xuly(s);
        dq(dau,cuoi,0);
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
