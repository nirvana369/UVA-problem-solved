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

#define fi "1089.inp"
#define fo "1089.out"
/**/
using namespace std;
/**/
vector<int > a[1000];
bool d[1000];
int kc[1000],q[1000];
map<string, int > mmap;
int n,xp,kt;
/**/
void loang()
{
    int x;
    int dau,cuoi;
    int i;
    
    if(xp == kt)
    {
        printf("0\n");
        return;
    }
    for(i=1;i<n;i++)
        d[i] = true;
    dau = -1;
    cuoi = 0;
    q[0] = xp;
    kc[0] = 0;
    d[xp] = false;
    
    while(dau != cuoi)
    {
        dau++;
        x = q[dau];
        for(i=0;i<a[x].size();i++)
            if(d[a[x][i]])
            {
                cuoi++;
                d[a[x][i]] = false;
                kc[cuoi] = kc[dau] + 1;
                q[cuoi] = a[x][i];
                if(a[x][i] == kt)
                {
                    printf("%d\n",kc[cuoi]);
                    return;
                }
            }
    }
    printf("No solution\n");
}
/**/
void input()
{
    int i;
    int m,id;
    char s[1000];
    int id1,id2;
    id = 1;
    while(scanf("%s",&s) == 1)
    {
        if(s[0] == '.') 
            break;
        mmap.clear();
        n = 1;
        xp = mmap[s];
        if(!xp)
        {
            mmap[s] = n;
            a[n].clear();
            xp = n;
            n++;
        }
            
        scanf("%s %d",&s,&m);
        kt = mmap[s];
        
        if(!kt)
        {
            mmap[s] = n;
            kt = n;
            a[n].clear();
            n++;
        }
        
        for(i=0;i<m;i++)
        {
            scanf("%s",&s);
            
            id1 = mmap[s];
            if(!id1)
            {
                mmap[s] = n;
                a[n].clear();
                id1 = n;
                n++;
            }
            
            scanf("%s",&s);
            id2 = mmap[s];
            if(!id2)
            {
                mmap[s] = n;
                a[n].clear();
                id2 = n;
                n++;
            }
            a[id1].push_back(id2);
        }
        printf("Case %d: ",id++);
        loang();
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
