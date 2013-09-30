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

#define fi "608.inp"
#define fo "608.out"
/**/
using namespace std;
/**/
char sleft[100],sright[100],st[100];
int eq[100],li[100],he[100];
/**/
void xuly()
{
    int i;
    int l;
    
    if(st[0] == 'e')
    {
        l = strlen(sleft);    
        for(i=0;i<l;i++)
            eq[sleft[i]] = eq[sright[i]] = 1;
            
        for(i='A';i<='L';i++)
            if(eq[i] == 1)
                li[i] = he[i] = 0;
    }
    else if(st[0] == 'u')
    {
        l = strlen(sleft);    
        for(i=0;i<l;i++)
        {
            he[sleft[i]]++;
            li[sright[i]]++;
        }
    }
    else
    {
        l = strlen(sleft);    
        for(i=0;i<l;i++)
        {
            li[sleft[i]]++;
            he[sright[i]]++;
        }
    }
}
/**/
void output()
{
    int i;
    int xh;
    char kt;
    bool light;
    
    for(i='A';i<='L';i++)
        if(eq[i] == 1)
            li[i] = he[i] = 0;
    xh = 0;
    for(i='A';i<='L';i++)
    {
        if(he[i] > xh)
        {
            xh = he[i];
            kt = i;
            light = false;
        }
        if(li[i] > xh)
        {
            xh = li[i];
            kt = i;
            light = true;
        }
    }
    if(light)
        printf("%c is the counterfeit coin and it is light.\n",kt);
    else
        printf("%c is the counterfeit coin and it is heavy.\n",kt);
}
/**/
void khoitao()
{
    int i;
    for(i='A';i<='L';i++)
    {
        eq[i] = 0;
        li[i] = 0;
        he[i] = 0;
    }
}
/**/
void input()
{
    int i;
    char temp[1000];
    int ntest;
    scanf("%d",&ntest);
    gets(temp);
    while(ntest--)
    {
        khoitao();
        for(i=0;i<3;i++)
        {
            gets(temp);
            sscanf(temp,"%s %s %s",&sleft,&sright,&st);
            xuly();
        }
        
        output();
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
