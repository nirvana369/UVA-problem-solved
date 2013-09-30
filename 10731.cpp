/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "10731.inp"
#define fo "10731.out"
/**/
using namespace std;
/**/
bool d[100],a[100][100];
int n;
/**/
void khoitao()
{
    int i,j;
    for(i='A';i<='Z';i++)
    {
        d[i] = false;
        for(j='A';j<='Z';j++)
            a[i][j] = false;
    }
}
/**/
void solve()
{
    int i,j,k;
    
    for(k='A';k<='Z';k++)
        for(i='A';i<='Z';i++)
            for(j='A';j<='Z';j++)
                if(a[i][k] && a[k][j])
                    a[i][j] = true;
                    
    for(i='A';i<='Z';i++)
        if(d[i])
        {
            d[i] = false;
            printf("%c",i);
            for(j='A';j<='Z';j++)
                if(d[j] && a[i][j] && a[j][i])
                {
                    printf(" %c",j);
                    d[j] = false;
                }
            printf("\n");
        }
}
/**/
void input()
{
    char s[10][10];
    int i,j;
    int id;
    
    id = 0;
    while(scanf("%d",&n) && n)
    {
        khoitao();
        for(i=0;i<n;i++)
        {
            for(j=0;j<5;j++)
            {
                scanf("%s",s[j]);
                d[s[j][0]] = true;
            }
            scanf("%s",s[5]);
            d[s[5][0]] = true;
            for(j=0;j<5;j++)
                a[s[5][0]][s[j][0]] = true;
        }
        if(id++)
            printf("\n");
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
