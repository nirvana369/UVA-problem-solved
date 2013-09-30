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

#define fi "497.inp"
#define fo "497.out"
/**/
using namespace std;
/**/
int a[10000],kq[10000],d[10000],truoc[10000];
int id;
/**/
void solve()
{
    int i,j,vt;
    int len;
    
    if(id == 1)
    {
        kq[0] = 0;
        i = 0;
        len = 1;
    }
    else
    {
        len = 0;
        for(i=1;i<id;i++)
            for(j=i-1;j>=0;j--)
                if(a[i] > a[j] && d[i] <= d[j])
                {
                    d[i] = d[j] + 1;
                    truoc[i] = j;
                    if(d[i] > len)
                    {
                        len = d[i];
                        vt = i;
                    }   
                }
        
        i = 0;
        while(vt != truoc[vt])
        {
            kq[i++] = vt;
            vt = truoc[vt];
        }
        kq[i] = vt;
    }
    printf("Max hits: %d\n",len);
    for(j=i;j>=0;j--)
        printf("%d\n",a[kq[j]]);
}
/**/
void input()
{
    int ntest;
    char s[1000];
    scanf("%d",&ntest);
    gets(s);
    gets(s);
    while(ntest--)
    {
        id = 0;
        while(true)
        {
            s[0] = 0;
            gets(s);
            if(s[0] == 0)
                break;
            sscanf(s,"%d",&a[id]);
            d[id] = 1;
            truoc[id] = id;
            id++;
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
