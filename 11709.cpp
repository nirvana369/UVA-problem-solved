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

#define fi "11709.inp"
#define fo "11709.out"
/**/
using namespace std;
/**/
vector<int> t[1010],t1[1010],topo;
map<string, int> mmap;
int d[1010];
int n;
/**/
void xuly(char s[])
{
    int i,j;
    i = j = 0;
    while(s[j])
    {
        if(s[j] >= 'A' && s[j] <= 'Z' || s[j] >= 'a' && s[j] <= 'z')
            s[i++] = s[j];
        j++;
    }
    s[i] = 0;
}
/**/
void topo1(int xp)
{
    int i;
    if(d[xp])
        return;
    d[xp] = 1;
    for(i=0;i<t1[xp].size();i++)
        if(!d[t1[xp][i]])
            topo1(t1[xp][i]);
    topo.push_back(xp);
}
/**/
void topo2(int xp)
{
    int i;
    if(!d[xp])
        return;
    d[xp] = 0;
    for(i=0;i<t[xp].size();i++)
        if(d[t[xp][i]])
            topo2(t[xp][i]);
}
/**/
void solve()
{
    int i;
    int cn;
    
    topo.clear();
    for(i=1;i<=n;i++)
        if(!d[i])
            topo1(i);
            
    cn = 0;
    for(i=topo.size()-1;i>=0;i--)
    {
        if(d[topo[i]])
        {
            topo2(topo[i]);
            cn++;
        }
    }
    cout << cn << endl;
}
/**/
void input()
{
    long i,m;
    int id1,id2;
    char s[200];
    
    while(scanf("%d %ld",&n,&m))
    {
        if(!n && !m)
            break;
        mmap.clear();
        gets(s);
        for(i=1;i<=n;i++)
        {
            gets(s);
            xuly(s);
            mmap[s] = i;
            d[i] = 0;
            t[i].clear();
            t1[i].clear();
        }
        for(i=0;i<m;i++)
        {
            gets(s);
            xuly(s);
            id1 = mmap[s];
            gets(s);
            xuly(s);
            id2 = mmap[s];
            t1[id1].push_back(id2);
            t[id2].push_back(id1);
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
