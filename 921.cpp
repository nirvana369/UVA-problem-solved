/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <iostream>

#define fi "921.inp"
#define fo "921.out"
/**/
using namespace std;
/**/
vector<int > pat[30];
int l[110],d[100];
char s[1000][20];
int len,n,m;
bool matching;
/**/
void khoitao()
{
    int i;
    
    for(i=1;i<=27;i++)
        d[i] = 0;
}
/**/
bool chk(int id,int ip)
{
    int i;

    for(i=0;i<l[id];i++)
        if(d[pat[ip][i]])
            if(d[pat[ip][i]] != s[id][i])
                return false;
    return true;
}
/**/
void match(int id)
{
    int i,j,k;
    int vt[30];
    
    if(id == n)
    {
        matching = true;
        return;
    }
    
    
    for(i=0;i<m;i++)
        if(l[i] == pat[id].size() && chk(i,id))
        {
            k = 0;
            for(j=0;j<pat[id].size();j++)
            {
                if(!d[pat[id][j]])
                    vt[k++] = j;
                d[pat[id][j]] = s[i][j];
            }
            match(id+1);
            if(matching)
                return;
            for(j=0;j<k;j++)
                d[pat[id][vt[j]]] = 0;
        }
}
/**/
void solve()
{
    int i;
    char s1[1000];
    
    khoitao();
    matching = false;
    match(0);
    
    for(i=0;i<len;i++)
        s1[i] = d[i+1];
    s1[len] = 0;
    printf("%s\n",s1);
}
/**/
void input()
{
    int i;
    int gt;
    int ntest;
    
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d %d",&len,&n);
        for(i=0;i<n;i++)
        {
            pat[i].clear();
            while(true)
            {
                scanf("%d",&gt);
                if(!gt)
                    break;
                pat[i].push_back(gt);
            }
        }
        m = 0;
        while(true)
        {
            scanf("%s",&s[m]);
            if(s[m][0] == '*')
                break;
            l[m] = strlen(s[m]);
            m++;
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
