/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <iostream>

#define fi "10092.inp"
#define fo "10092.out"
/**/
using namespace std;
/**/
vector<int > _left[2100];
bool d[1100];
int a[2100][1100],q[2100],trc[2100],phai[1100],trai[2100],nt[1100];
int ntrai,nphai,nk,last;
/**/
void noi(int xp)
{
    int i;
    int dau,cuoi;
    
    for(i=1;i<=nphai;i++)
        d[i] = true;
    
    dau = -1;
    cuoi = 0;
    q[0] = xp;
    
    while(dau != cuoi)
    {
        dau++;
        for(i=1;i<=nphai;i++)
            if(d[i] && a[q[dau]][i])
            {
                d[i] = false;
                trc[i] = q[dau];
                if(!phai[i])
                {
                    last = i;
                    return;
                }
                cuoi++;
                q[cuoi] = phai[i];
            }
    }
}
/**/
void tomau(int xp)
{
    int i,j;
    i = 0;
    
    while(i != xp)
    {
        i = trc[last];
        j = trai[i];
        trai[i] = last;
        phai[last] = i;
        last = j;
    }
}
/**/
void solve()
{
    int i,j;
    
    for(i=1;i<=ntrai;i++)
    {
        last = 0;
        noi(i);
        if(last)
            tomau(i);
    }
    
    for(i=1;i<=ntrai;i++)
        if(!trai[i])
        {
            printf("0\n");
            return;
        }
    printf("1\n");
    for(i=1;i<=nk;i++)
    {
        for(j=0;j<_left[i].size();j++)
            cout << trai[_left[i][j]] << " ";
        cout << endl;
    }
}
/**/
void khoitao()
{
    int i,j;
    
    for(i=1;i<=ntrai;i++)
        for(j=1;j<=nphai;j++)
            a[i][j] = 0;
}
/**/
void input()
{
    int i,j,k;
    int m,t;
    while(scanf("%d %d",&ntrai,&nphai) && ntrai && nphai)
    {
        int id = 1;
        for(i=1;i<=ntrai;i++)
        {
            _left[i].clear();
            scanf("%d",&nt[i]);
            for(j=1;j<=nt[i];j++)
            {
                trai[id] = 0;
                _left[i].push_back(id);
                id++;
            }
        }
        nk = ntrai;
        ntrai = id-1;
        khoitao();
        for(i=1;i<=nphai;i++)
        {
            phai[i] = 0;
            scanf("%d",&m);
            for(j=0;j<m;j++)
            {
                scanf("%d",&t);
                for(k=0;k<_left[t].size();k++)
                    a[_left[t][k]][i] = 1;
            }
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
