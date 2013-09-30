/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "11503.inp"
#define fo "11503.out"
/**/
using namespace std;
/**/
long d[300100],fr[300100];
map<string,long > mmap;
/**/
long findfr(long x)
{
    while(x != fr[x])
        x = fr[x];
    return x;
}
/**/
void input()
{
    long i,m,n;
    char s1[25],s2[25];
    long id1,id2,tmp2,tmp1;
    int ntest;
    
    scanf("%d",&ntest);
    while(ntest--)
    {
        n = 1;
        mmap.clear();
        scanf("%ld",&m);
        for(i=0;i<m;i++)
        {
            scanf("%s %s",&s1,&s2);
            
            if(!mmap[s1])
            {
                mmap[s1] = n;
                d[n] = 1;
                fr[n] = n;
                id1 = n;
                tmp1 = n;
                n++;
            }
            else
            {
                tmp1 = mmap[s1];
                id1 = findfr(tmp1);
            }
            
            if(!mmap[s2])
            {
                mmap[s2] = n;
                d[n] = 1;
                id2 = n;
                tmp2 = n;
                fr[n] = n;
                n++;
            }
            else
            {
                tmp2 = mmap[s2];
                id2 = findfr(tmp2);
            }
            fr[id2] = id1;
            fr[tmp1] = id1;
            fr[tmp2] = id1;
            if(tmp1 != tmp2 && id1 != id2)
                d[id1] += d[id2];
            printf("%ld\n",d[id1]);
        }
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
