/*
                                                                    Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10905.inp"
#define fo "10905.out"
/**/
using namespace std;
/**/
char a[55][1000];
int len[55];
int n;
/**/
bool kt(char s1[],char s2[],int l)
{
    int i;
    for(i=0;i<l;i++)
    {
        if(s1[i] > s2[i])
            return true;
        if(s2[i] > s1[i])
            return false;
    }
    return false;
}
/**/
bool sosanh(int i,int j)
{
    char tempi[10000],tempj[10000];
    int k,si,sj;

    k = si = 0;
    sj = len[j];
    while(k < len[i])
    {
        tempi[si++] = a[i][k];
        tempj[sj++] = a[i][k];
        k++;
    }
    si = len[i];
    sj = k = 0;
    while(k < len[j])
    {
        tempi[si++] = a[j][k];
        tempj[sj++] = a[j][k];
        k++;
    }
    tempi[len[i]+len[j]] = 0;
    tempj[len[i]+len[j]] = 0;
    
    if(kt(tempj,tempi,len[i] + len[j]))
        return true;
    return false;
}
/**/
void swapa(int i,int j)
{
    char temp[1000];
    int tg;
    tg = len[i];
    len[i] = len[j];
    len[j] = tg;
    strcpy(temp,a[i]);
    strcpy(a[i],a[j]);
    strcpy(a[j],temp);
}
/**/
void sapxep()
{
    int i,j;
    
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(sosanh(i,j))
                swapa(i,j);
}
/**/
void solve()
{
    int i;
    sapxep();
    for(i=0;i<n;i++)
        printf("%s",a[i]);
    printf("\n");
}
/**/
void input()
{
    int i;
    while(true)
    {
        scanf("%d",&n);
        if(!n)
            break;
        for(i=0;i<n;i++)
        {
            scanf("%s",&a[i]);
            len[i] = strlen(a[i]);
        }
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
