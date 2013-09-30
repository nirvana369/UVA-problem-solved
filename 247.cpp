/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>
#include <vector>

#define fi "247.inp"
#define fo "247.out"
/**/
using namespace std;
/**/
vector<int > dinh,kq[100];
map<string, int > mmap;
char name[30][100];
bool d[30],a[30][30];
int n,m,dkq;
/**/
void khoitao()
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            a[i][j] = false;
        d[i] = true;
    }
}
/**/
void solve()
{
    int i,j,k;
    
    // floyd
    for(k=1;k<=n;k++)
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
                if(a[i][k] && a[k][j])
                    a[i][j] = true;
                    
    for(i=1;i<=n;i++)
        if(d[i])
        {
            d[i] = false;
            printf("%s",name[i]);
            for(j=1;j<=n;j++)
                if(d[j] && a[i][j] && a[j][i])
                {
                    d[j] = false;
                    printf(", %s",name[j]);
                }
            printf("\n");
        }       
}
/**/
void input()
{
    int i,j;
    int id1,id2,id;
    char s[100];
    j = 0;
    while(scanf("%d %d",&n,&m))
    {
        if(!m && !n)
            break;
        mmap.clear();
        khoitao();
        id = 1;
        for(i=0;i<m;i++)
        {
            scanf("%s",&s);
            id1 = mmap[s];
            if(!id1)
            {
                id1 = id;
                strcpy(name[id],s);
                mmap[s] = id++; 
            }
            
            scanf("%s",&s);
            
            id2 = mmap[s];
            if(!id2)
            {
                id2 = id;
                strcpy(name[id],s);
                mmap[s] = id++;
            }
            a[id1][id2] = true;
        }
        if(j)
            printf("\n");
        printf("Calling circles for data set %d:\n",++j);
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
