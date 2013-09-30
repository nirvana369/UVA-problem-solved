/*
                                            Hoang Linh
                                        
                                    Problem: WHAT BASE IS THIS? - 343 (343.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "343.inp"
#define fo "343.out"
/**/
using namespace std;
/**/
int base[200],gt[200];
char s1[1000],s2[1000];
/**/
long mu(int cs,int bac)
{
    long value;
    int i;
    if(bac == 0)
        return 1;
    value = cs;
    for(i=0;i<bac-1;i++)
        value = value * cs;
    return value;
}
/**/
long long doigt(char s[],int len,int cs)
{
    int i;
    int bac;
    long long value;
    
    bac = len-1;
    value = 0;
    for(i=0;i<len;i++,bac--)
        value = value + (long long)gt[s[i]] * mu(cs,bac);
    return value;
}
/**/
void solve()
{
    int i,j;
    int l1,l2;
    int b1,b2;
    long long gt1,gt2;
    
    l1 = strlen(s1);
    l2 = strlen(s2);
    
    b1 = 2;
    b2 = 2;
    for(i=0;i<l1;i++)
    {
        if(base[s1[i]] > b1)    
            b1 = base[s1[i]];
    }
    
    for(i=0;i<l2;i++)
    {
        if(base[s2[i]] > b2)    
            b2 = base[s2[i]];
    }
    
    for(i=b1;i<=36;i++)
    {
        gt1 = doigt(s1,l1,i);
        for(j=b2;j<=36;j++)
        {
            gt2 = doigt(s2,l2,j);
            if(gt1 == gt2)
            {
                printf("%s (base %d) = %s (base %d)\n",s1,i,s2,j);
                return;
            }
        }
    }
    printf("%s is not equal to %s in any base 2..36\n",s1,s2);
}
/**/
void khoitao()
{
    int i;
    int dem;
    dem = 3;
    base['0'] = 2;
    base['1'] = 2;
    for(i='2';i<='9';i++,dem++)
        base[i] = dem;
    for(i='A';i<='Z';i++,dem++)
        base[i] = dem;
    dem = 0;
    for(i='0';i<='9';i++,dem++)
        gt[i] = dem;
    for(i='A';i<='Z';i++,dem++)
        gt[i] = dem;
}
/**/
void input()
{
    char temp[2000];
    khoitao();
    while(true)
    {
        temp[0] = 0;
        gets(temp);
        if(temp[0] == 0)
            break;
        sscanf(temp,"%s %s",&s1,&s2);
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
