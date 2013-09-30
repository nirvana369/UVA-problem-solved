/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "11955.inp"
#define fo "11955.out"
/**/
using namespace std;
/**/
long long p[51][51];
char a[100],b[100];
int km;
/**/
void _init()
{
    int i,j,k;
    
    p[1][1] = 1;
    p[1][2] = 1;
    k = 2;
    while(k <= 50)
    {
        p[k][1] = p[k][k+1] = 1;
        for(i=2;i<=k;i++)
            p[k][i] = p[k-1][i-1] + p[k-1][i];
        k++;
    }
}
/**/
void solve()
{
    int i;
    int ma,mb;
    if(km != 1)
        printf("%s^%d",a,km);
    else
        printf("%s",a);
    ma = km - 1;
    mb = 1;
    for(i=2;i<=km;i++)
    {
        printf("+");
        if(p[km][i] != 1)
            printf("%lld*",p[km][i]);
        if(ma > 1)        
            printf("%s^%d",a,ma--);
        else
            printf("%s",a);
        
        if(mb > 1)
            printf("*%s^%d",b,mb++);
        else
        {
            printf("*%s",b);
            mb++;
        }
    }
    
    if(km != 1)
        printf("+%s^%d",b,km);
    else
        printf("+%s",b);
    printf("\n");
}
/**/
void xuly(char s[])
{
    int i,j;
    char tmp[100];
    
    i = j = 0;
    while(s[i])
    {
        if(s[i] == '+')
            break;
        if(s[i] >= 'a' && s[i] <= 'z')
            a[j++] = s[i];
        i++;
    }
    a[j] = 0;
    j = 0;
    while(s[i])
    {
        if(s[i] == '^')
            break;
        if(s[i] >= 'a' && s[i] <= 'z')
            b[j++] = s[i];
        i++;
    }
    b[j] = 0;
    j = 0;
    
    while(s[i])
    {
        if(s[i] >= '0' && s[i] <= '9')
            tmp[j++] = s[i];
        i++;
    }
    tmp[j] = 0;
    sscanf(tmp,"%d",&km);
}
/**/
void input()
{
    int ntest,id;
    char s[1000];
    
    _init();
    scanf("%d",&ntest);
    gets(s);
    id = 1;
    while(ntest--)
    {
        gets(s);
        xuly(s);
        printf("Case %d: ",id++);
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
