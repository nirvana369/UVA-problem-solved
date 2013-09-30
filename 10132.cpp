/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
//#include <queue>
//#include <vector>
//#include <map>

#define fi "10132.inp"
#define fo "10132.out"
/**/
using namespace std;
/**/
int f[2][32000];
char a[1000][32000];
int l[1000];
int nf,maxlen,minlen;
/**/
void solve()
{
    int i,j,k;
    int len;
    
    len = maxlen + minlen;
    
    for(i=0;i<len;i++)
        f[0][i] = f[1][i] = 0;
    
    for(i=0;i<nf;i++)
    {
        for(j=0;j<l[i];j++)
            f[a[i][j] - 48][j]++;
            
        for(j=len-l[i],k=0;j<len;j++,k++)
            f[a[i][k] - 48][j]++;
    }
    
    for(i=0;i<len;i++)
        if(f[0][i] > f[1][i])
            printf("0");
        else
            printf("1");
    printf("\n");
}
/**/
void input()
{
    int ntest;
    int tmp;
    
    scanf("%d",&ntest);
    gets(a[0]);
    gets(a[0]);
    while(ntest--)
    {
        nf = 0;
        maxlen = 0;
        minlen = 32000;
        while(1)
        {
            a[nf][0] = 0;
            gets(a[nf]);
            if(!a[nf][0])
                break;
            tmp = strlen(a[nf]);
            l[nf] = tmp;
            maxlen = tmp > maxlen ? tmp : maxlen;
            minlen = tmp < minlen ? tmp : minlen;
            nf++;
        }
        solve();
        if(ntest)
            printf("\n");
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
