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

#define fi "630.inp"
#define fo "630.out"
/**/
using namespace std;
/**/
char a[3000][100],s[100];
int len[3000],d[100];
int n;
/**/
void solve()
{
    int i,j,k,id;
    int l,temp;
    bool tontai;
    
    printf("Anagrams for: %s\n",s);
    tontai = false;
    id = 1;
    l = strlen(s);
    for(i=0;i<n;i++)
    {
        if(l == len[i])
        {
            for(j=0;j<l;j++)
                d[j] = 0;
            temp = l;
            for(j=0;j<l;j++)
                for(k=0;k<l;k++)
                    if(s[j] == a[i][k] && d[k] == 0)
                    {
                        d[k] = 1;
                        temp--;
                        break;
                    }
            if(temp == 0)
            {
                printf("  %d) %s\n",id++,a[i]);
                tontai = true;
            }
        }
    }
    if(!tontai)
        printf("No anagrams for: %s\n",s);
}
/**/
void input()
{
    int i;
    int ntest;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%s",&a[i]);
            len[i] = strlen(a[i]);
        }
        while(true)
        {
            scanf("%s",&s);
            if(strcmp(s,"END") == 0)
                break;
            solve();
        }
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
