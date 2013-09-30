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

#define fi "10763.inp"
#define fo "10763.out"
/**/
using namespace std;
/**/
long n;
map <string, long> mmap;
map <string, string> rmap;
/**/
void xuly(int x,int y)
{
    int i,j;
    char s1[100],s2[100];
    int l1,l2;
    
    sprintf(s1,"%d",x);
    sprintf(s2,"%d",y);
    l1 = strlen(s1);
    l2 = strlen(s2);
    s1[l1] = ' ';
    s2[l2] = ' ';
    for(i=0,j=l1+1;i<l2;i++,j++)
        s1[j] = s2[i];
    s1[j] = 0;
    
    for(i=0,j=l2+1;i<l1;i++,j++)
        s2[j] = s1[i];
    s2[j] = 0;
    
    if(mmap[s1] == 0)
        rmap[s1] = s2;
    mmap[s1]++;
}
/**/
void solve()
{
    map <string, long>::iterator i;
    string a;
    bool exc;
    exc = true;
    for(i=mmap.begin();i!=mmap.end();i++)
    {
        if(i->second != mmap[rmap[i->first]])
        {
            exc = false;
            break;
        }
    }
    if(exc)
        printf("YES\n");
    else
        printf("NO\n");
}
/**/
void input()
{
    long i;
    int x,y;
    while(scanf("%ld",&n) == 1)
    {
        if(!n)
            break;
        mmap.clear();
        rmap.clear();
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&x,&y);
            xuly(x,y);
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
