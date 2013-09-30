/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "12115.inp"
#define fo "12115.out"
/**/
using namespace std;
/**/
char s[55000],out[110000];
/**/
long ttd(long value)
{
    if(value < 0)
        return -value;
    return value;
}
/**/
void solve()
{
    long i,j;
    long h1,h2,c1,c2,l;
    l = strlen(s);
    
    i = 0;
    j = l * 2 - 2;
    while(i < l-1)    
    {
        out[i] = s[i];
        out[j] = s[i];
        i++;
        j--;
    }
    out[i] = s[i];
    
    scanf("%ld %ld %ld %ld",&h1,&c1,&h2,&c2);
    for(i=h1;i<=h2;i++)
    {
        for(j=c1;j<=c2;j++)
        {
            if(ttd(i-l) > ttd(j-l))
                printf("%c",out[i-1]);
            else
                printf("%c",out[j-1]);
        }   
        printf("\n");
    }
}
/**/
void input()
{
    int i,id;
    int ntest;
    int q;
    id = 1;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%s %d",&s,&q);
        printf("Square %d:\n",id);
        for(i=0;i<q;i++)
        {
            printf("Query %d:\n",i+1);
            solve();
        }
        printf("\n");
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
