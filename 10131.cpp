/*
                                                Hoang Linh
                                                
                                    Problem: IS BIGGER SMARTER? - 10131 (10131.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10131.inp"
#define fo "10131.out"
/**/
using namespace std;
/**/
struct ele{
            int w,iq,vt;
            };
int n;
ele e[1100];
int d[1100],truoc[1100],kq[1100];
/**/
void sorte()
{
    int i,j;
    ele temp;
    
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(e[i].w > e[j].w)
            {
                temp = e[i];
                e[i] = e[j];
                e[j] = temp;
            }
            else if(e[i].w == e[j].w)
                if(e[i].iq < e[j].iq)
                {
                    temp = e[i];
                    e[i] = e[j];
                    e[j] = temp;
                }
}
/**/
void solve()
{
    int i,j;
    int maxlen,c,pos;
    maxlen = 0;
    for(i=1;i<n;i++)
        for(j=i-1;j>=0;j--)
            if(e[i].w > e[j].w && e[i].iq < e[j].iq && d[i] <= d[j])
            {
                d[i] = d[j] + 1;
                truoc[i] = j;
                if(d[i] > maxlen)
                {
                    maxlen = d[i];
                    pos = i;
                }
            }
    c = 0;
    while(truoc[pos] != 0)
    {
        kq[c] = pos;
        pos = truoc[pos];
        c++;
    }
    kq[c] = pos;
    printf("%d\n",maxlen+1);
    for(i=c;i>=0;i--)
        printf("%d\n",e[kq[i]].vt);
}
/**/
void input()
{
    n = 0;
    while(scanf("%d %d",&e[n].w,&e[n].iq) == 2)
    {
        truoc[n] = 0;
        d[n] = 0;
        e[n].vt = n + 1;
        n++;
    }
    sorte();
    solve();
}
/**/
int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    input();
    return 0;
}
