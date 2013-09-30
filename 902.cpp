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

#define fi "902.inp"
#define fo "902.out"
/**/
using namespace std;
/**/
map <string, int> mmap;
int n,freq;
char kq[15],s[1000000];
/**/
void mapping(long i)
{
    int j;
    char temp[15];
    for(j=0;j<n;j++,i++)
        temp[j] = s[i];
    temp[j] = 0;
    mmap[temp]++;
    if(mmap[temp] > freq)
    {
        freq = mmap[temp];
        strcpy(kq,temp);
    }
}
/**/
void solve()
{
    long i;
    long l;
    
    freq = 0;
    mmap.clear();
    l = strlen(s);
    for(i=0;i<l;i++)
        if(i+n <= l)
            mapping(i);
    printf("%s\n",kq);
}
/**/
void input()
{
    while(true)
    {
        n = 0;
        scanf("%d %s",&n,&s);
        if(!n)
            break;
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
