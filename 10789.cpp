/*
                                                    Hoang Linh
                                                    
                                        Problem: PRIME FREQUENCY - 10789 (10789.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10789.inp"
#define fo "10789.out"
/**/
using namespace std;
/**/
int nt[2100],d[200];
/**/
bool isnt(int value)
{
    int i;
    int add,temp;
    
    if(value == 3 || value == 2)
        return true;
    if(value <= 1 || value % 2 == 0 || value % 3 == 0)
        return false;
    add = 2;
    temp = (int)sqrt(value);
    for(i=5;i<=temp;i+=add,add=6-add)
        if(value % i == 0)
            return false;
    return true;
}
/**/
void precal()
{
    int i;
    for(i=1;i<2002;i++)
        if(isnt(i))
            nt[i] = 1;
        else
            nt[i] = 0;
}
/**/
void khoitao()
{
    int i;
    for(i='0';i<='9';i++)
        d[i] = 0;
    for(i=65;i<91;i++)
        d[i] = 0;
    for(i=97;i<123;i++)
        d[i] = 0;
}
/**/
void output(int id)
{
    int i;
    bool tontai;
    tontai = false;
    printf("Case %d: ",id);

    for(i='0';i<='9';i++)
        if(nt[d[i]] == 1)
        {
            tontai = true;
            printf("%c",i);
        }
        
    for(i=65;i<91;i++)
        if(nt[d[i]] == 1)
        {
            tontai = true;
            printf("%c",i);
        }

    for(i=97;i<123;i++)
        if(nt[d[i]] == 1)
        {
            tontai = true;
            printf("%c",i);
        }
    if(!tontai)
        printf("empty");
    printf("\n");
}
/**/
void input()
{
    char s[2100];
    int id,l;
    int i;
    int ntest;
    precal();
    id = 1;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%s",&s);
        khoitao();
        l = strlen(s);
        for(i=0;i<l;i++)
            d[s[i]]++;
        output(id);
        id++;
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
