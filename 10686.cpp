/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10686.inp"
#define fo "10686.out"
/**/
using namespace std;
/**/
int d[35];
char name[35][101];
int m[35];
map<string, int > mmap[35];
int nc,n;
/**/
void solve()
{
    char s[1000],tmp[1000];
    int dem,i,j,fst;
    bool sqf;
    gets(s);
    while(true)
    {
        s[0] = 0;
        gets(s);
        if(!s[0])
            break;
        i = dem = 0;
        while(s[i])
        {
            if(s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z')
                tmp[dem++] = s[i];
            else if(dem != 0)
            {
                tmp[dem] = 0;
                for(j=1;j<=nc;j++)
                    if(mmap[j][tmp])
                    {
                        d[j]++;
                        mmap[j][tmp] = 0;
                    }
                dem = 0;
            }
            i++;
        }
        if(dem != 0)
        {
            tmp[dem] = 0;
            for(j=1;j<=nc;j++)
                if(mmap[j][tmp])
                {
                    d[j]++;
                    mmap[j][tmp] = 0;
                }
            dem = 0;
        }
    }
    sqf = true;
    fst = 0;
    for(i=1;i<=nc;i++)
        if(d[i] >= m[i])
        {
            sqf = false;
            if(fst)
                printf(",");
            printf("%s",name[i]);
            fst++;
        }
        
    if(sqf)
        printf("SQF Problem.");
    printf("\n");
}
/**/
void input()
{
    int i,j;
    char s[1000];
    int ntest;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d",&nc);
        for(i=1;i<=nc;i++)
        {
            mmap[i].clear();
            d[i] = 0;
            scanf("%s %d %d",name[i],&n,&m[i]);     
            for(j=0;j<n;j++)       
            {
                scanf("%s",&s);
                mmap[i][s] = i;
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

