/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "1368.inp"
#define fo "1368.out"
/**/
using namespace std;
/**/
char dna[55][1100];
int d[100];
int n,len;
/**/
int chk(char s1[],char s2[])
{
    int i;
    int dif;
    
    dif = 0;
    for(i=0;i<len;i++)
        if(s1[i] != s2[i])
            dif++;
    return dif;
}
/**/
char gmax(char x,char y)
{
    if(d[x] > d[y])
        return x;
    if(d[x] == d[y])
    {
        if(x > y)
            return y;
        return x;
    }
    return y;
}
/**/
void solve()
{
    int i,j;
    int tmp;
    int maxdif,kt;
    
    maxdif = 0;
    for(i=0;i<len;i++)
    {
        d['A'] = d['C'] = d['G'] = d['T'] = 0;
        for(j=0;j<n;j++)
            d[dna[j][i]]++;
        kt = gmax(gmax('A','C'),gmax('G','T'));
        maxdif += n-d[kt];
        printf("%c",kt);
    }
    printf("\n%d\n",maxdif);
}
/**/
void input()
{
    int i;
    int ntest;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d %d",&n,&len);
        for(i=0;i<n;i++)
            scanf("%s",dna[i]);
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
