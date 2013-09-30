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
#include <vector>

#define fi "11060.inp"
#define fo "11060.out"
/**/
using namespace std;
/**/
map <string, int> mmap;
map <int, string> name;
bool d1[110],a[110][110];
int d[110];
int n,m;
/**/
void khoitao()
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            a[i][j] = false;
}
/**/
void solve()
{
    int i,j,k;
    
    j = 1;
    while(j)
    {
        j = 0;
        for(i=0;i<n;i++)
            if(!d1[i] && !d[i])
            {
                cout << " " << name[i];
                j = 1;
                d1[i] = true;
                for(k=0;k<n;k++)
                    if(a[i][k] && d[k])
                        d[k]--;
                break;
            }
    } 
    cout << "." << endl << endl;
}
/**/
void input()
{
    int i;
    char s1[100],s2[100];
    int id1,id2,id;
    id = 1;
    while(scanf("%d",&n) == 1)
    {
        mmap.clear();
        name.clear();
        for(i=0;i<n;i++)
        {
            scanf("%s",&s1);
            mmap[s1] = i;
            name[i] = s1;
            d1[i] = false;
            d[i] = 0;
        }
        khoitao();
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%s %s",&s1,&s2);
            id1 = mmap[s1];
            id2 = mmap[s2];
            if(!a[id1][id2])
            {
                a[id1][id2] = true;
                d[id2]++;
            }
        }
        printf("Case #%d: Dilbert should drink beverages in this order:",id++);
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
