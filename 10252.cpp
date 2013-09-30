/*
                                                            Hoang Linh
                                                        
                                            Problem: COMMON PERMUTATION - 10252 (10252.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10252.inp"
#define fo "10252.out"
/**/
using namespace std;
/**/
char s1[1100],s2[1100];
int d1[200],d2[200];
/**/
void khoitao()
{
    int i;
    for(i=97;i<123;i++)
    {
        d1[i] = 0;
        d2[i] = 0;
    }
}
/**/
int mingt(int gt1,int gt2)
{
    if(gt1 > gt2)
        return gt2;
    return gt1;
}
/**/
void xuly()
{
    int i,j;
    int l1,l2,temp;
    
    l1 = strlen(s1);
    l2 = strlen(s2);
    i = 0;
    while(i < l1 || i < l2)
    {
        if(i < l1 && s1[i] >= 'a' && s1[i] <= 'z')
            d1[s1[i]]++;

        if(i < l2 && s2[i] >= 'a' && s2[i] <= 'z')
            d2[s2[i]]++;
        i++;
    }
    for(i=97;i<123;i++)
    {
        temp = mingt(d1[i],d2[i]);
        for(j=0;j<temp;j++)
            printf("%c",i);
    }
    printf("\n");
}
/**/
void input()
{
    while(!feof(stdin))
    {
        gets(s1);
        if(feof(stdin))
            break;
        gets(s2);
        khoitao();
        xuly();
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
