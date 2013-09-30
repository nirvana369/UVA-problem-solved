/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "334.inp"
#define fo "334.out"
/**/
using namespace std;
/**/
struct khoang{
                int d,c;
             };
khoang v[500];
bool a[500][500];
char name[500][100];
int n,m;         
map<string, int> mmap;    
/**/
void khoitao()
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            a[i][j] = false;
            
    for(i=0;i<m;i++)
        for(j=v[i].d;j<=v[i].c-1;j++)
            a[j][j+1] = true;
}
/**/
void solve()
{
    int i,j,k;
    int dem;
    
    for(k=0;k<n;k++)
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(!a[i][j])
                    if(a[i][k] && a[k][j])
                        a[i][j] = true;
    dem = 0;
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
            if(!a[i][j] && !a[j][i])
            {
                if(dem < 2)
                {
                    v[dem].d = i;
                    v[dem].c = j;
                }
                dem++;
            }
    if(!dem)
        printf(" no concurrent events.");
    else
    {
        printf(" %d concurrent events:\n",dem);
        if(dem > 2)
            dem = 2;
        for(i=0;i<dem;i++)
            printf("(%s,%s) ",name[v[i].d],name[v[i].c]);
    }
    printf("\n");
}
/**/
void input()
{
    int i,j;
    char s1[100],s2[100];
    int id;
    id = 1;
    while(scanf("%d",&m) && m)
    {
        n = 0;
        for(i=0;i<m;i++)
        {
            v[i].d = n;
            scanf("%d",&v[i].c);
            for(j=0;j<v[i].c;j++)
            {
                scanf("%s",&name[n]);
                mmap[name[n]] = n;
                n++;
            }
            v[i].c = n-1;
        }
        khoitao();
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%s %s",&s1,&s2);
            a[mmap[s1]][mmap[s2]] = true;
        }
        printf("Case %d,",id++);
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
