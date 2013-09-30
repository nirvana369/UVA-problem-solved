/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <vector>
#include <iostream>

#define fi "753.inp"
#define fo "753.out"
/**/
using namespace std;
/**/
vector<int> a[500];
int trai[500],phai[500],q[500],trc[510],plg[500];
bool d[500];
map<string, int > lmap,rmap;
int ntrai,nphai,n,m,last;
/**/
void loang(int xp)
{
    int i;
    int dau,cuoi;
    int x;
    
    for(i=1;i<=nphai;i++)
        d[i] = true;
    
    dau = -1;
    cuoi = 0;
    q[0] = xp;
    
    while(dau != cuoi)
    {
        dau++;
        x = q[dau];
        for(i=0;i<a[x].size();i++)
            if(d[a[x][i]])
            {
                d[a[x][i]] = false;
                trc[a[x][i]] = q[dau];
                if(!phai[a[x][i]])
                {
                    last = a[x][i];
                    return;
                }
                cuoi++;
                q[cuoi] = phai[a[x][i]];
            }
    }
}
/**/
void plug(int xp)
{
    int i,j;
    
    while(i != xp)
    {
        i = trc[last];
        j = trai[i];
        phai[last] = i;
        trai[i] = last;
        last = j;
    }
}
/**/
void dfs(int x,int y) // noi lien tiep
{
    if(y == trc[y])
        return;
    y = trc[y];
    a[y].push_back(x);
    dfs(x,y);
}
/**/
void solve()
{
    int i;
    int dem;
    
    for(i=1;i<=nphai;i++)
        dfs(i,plg[i]);    
    
    dem = 0;
    for(i=1;i<=ntrai;i++)
    {
        last = 0;
        loang(i);
        if(last)
        {
            plug(i);
            dem++;
        }
    }
    printf("%d\n",nphai-dem);
}
/**/
void input()
{
    int ntest;
    int x,y;
    int i,j;
    char s[100];
    
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d",&ntrai);
        n = ntrai;
        lmap.clear();
        rmap.clear();
        for(i=1;i<=500;i++)
            trc[i] = i;
        for(i=1;i<=n;i++)
        {
            scanf("%s",&s);
            lmap[s] = i;
            trai[i] = 0;
            a[i].clear();
        }
        scanf("%d",&nphai);
        for(i=1;i<=nphai;i++)
        {
            scanf("%s",&s);
            phai[i] = 0;
            rmap[s] = i;
            scanf("%s",&s);

            x = lmap[s];
            if(!x)
            {
                n++;
                x = n;
                trai[x] = 0;
                a[x].clear();
                lmap[s] = n;
            }
            
            plg[i] = x;
            a[x].push_back(i);
        }
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%s",&s);
            x = lmap[s];
            if(!x)
            {
                n++;
                x = n;
                trai[x] = 0;
                a[x].clear();
                lmap[s] = n;
            }
            
            scanf("%s",&s);
            y = lmap[s];
            if(!y)
            {
                n++;
                y = n;
                trai[y] = 0;
                a[y].clear();
                lmap[s] = n;
            }
            trc[x] = y; // luu cac diem noi
            for(j=0;j<a[x].size();j++) // noi plug
                a[y].push_back(a[x][j]);
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
