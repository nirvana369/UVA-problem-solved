/*
                                                        Hoang Linh
                                                    
                                        Problem: WHAT'S CRYPTANALYSIS? - 10008 (10008.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10008.inp"
#define fo "10008.out"
/**/
using namespace std;
/**/
int d[100];
char kt[100];
/**/
void khoitao()
{
    int i;
    for(i=65;i<91;i++)
    {
        d[i] = 0;
        kt[i] = i;
    }
}
/**/
void sapxep()
{
    int i,j;
    char temp;
    
    for(i=65;i<90;i++)
        for(j=i+1;j<91;j++)
            if(d[kt[i]] < d[kt[j]])
            {
                temp = kt[i];
                kt[i] = kt[j];
                kt[j] = temp;
            }
            else if(d[kt[i]] == d[kt[j]])
                if(kt[i] > kt[j])
                {
                    temp = kt[i];
                    kt[i] = kt[j];
                    kt[j] = temp;
                }
}
/**/
void output()
{
    int i;
    sapxep();
    for(i=65;i<91;i++)
    {
        if(d[kt[i]] == 0)
            break;
        printf("%c %d\n",kt[i],d[kt[i]]);
    }
}
/**/
void xuly(char s[])
{
    int i;
    int l;
    l = strlen(s);
    for(i=0;i<l;i++)
        if(s[i] >= 'a' && s[i] <= 'z')
            d[s[i]-32]++;
        else if(s[i] >= 'A' && s[i] <= 'Z')
            d[s[i]]++;
}
/**/
void input()
{
    int i;
    int nline;
    char temp[10000];
    
    khoitao();
    scanf("%d",&nline);
    gets(temp);
    for(i=0;i<nline;i++)
    {
        gets(temp);
        xuly(temp);
    }
    output();
}
/**/
int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    input();
    return 0;
}
