/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "869.inp"
#define fo "869.out"
/**/
using namespace std;
/**/
int a[210][210],b[210][210],d[210];
int ida,idb;
int n;
/**/
void khoitao()
{
    int i;
    for(i=1;i<=200;i++)
        d[i] = 0;
}
/**/
void _init()
{
    int i,j;
    for(i=1;i<=200;i++)
        for(j=1;j<=200;j++)
            a[i][j] = b[i][j] = a[j][i] = b[j][i] = 0;
}
/**/
bool solve()
{
    int i,j,k;
    
    if(ida != idb)
        return false;
        
    for(k=1;k<ida;k++)
        for(i=1;i<ida;i++)
            for(j=1;j<ida;j++)
            {
                if(a[i][k] && a[k][j])
                    a[i][j] = 1;
                if(b[i][k] && b[k][j])
                    b[i][j] = 1;
            }
    for(i=1;i<ida;i++)
        for(j=1;j<ida;j++)
            if(a[i][j] && !b[i][j] || !a[i][j] && b[i][j])
                return false;
    return true;
}
/**/
void input()
{
    int ntest;
    int i;
    int id1,id2;
    char s1[5],s2[5];
    
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d",&n);
        _init();
        khoitao();
        ida = 1;
        for(i=0;i<n;i++)
        {
            scanf("%s %s",&s1,&s2);
            if(!d[s1[0]])
            {
                d[s1[0]] = ida;
                id1 = ida;
                ida++;
            }
            else
                id1 = d[s1[0]];
                
            if(!d[s2[0]])
            {
                d[s2[0]] = ida;
                id2 = ida;
                ida++;
            }
            else
                id2 = d[s2[0]];
                
            a[id1][id2] = a[id2][id1] = 1;
        }
        scanf("%d",&n);
        khoitao();
        idb = 1;
        
        for(i=0;i<n;i++)
        {
            scanf("%s %s",&s1,&s2);
            if(!d[s1[0]])
            {
                d[s1[0]] = idb;
                id1 = idb;
                idb++;
            }
            else
                id1 = d[s1[0]];
                
            if(!d[s2[0]])
            {
                d[s2[0]] = idb;
                id2 = idb;
                idb++;
            }
            else
                id2 = d[s2[0]];
                
            b[id1][id2] = b[id2][id1] = 1;
        }
        if(solve())
            printf("YES\n");
        else
            printf("NO\n");
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
