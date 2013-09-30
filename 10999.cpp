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

#define fi "10999.inp"
#define fo "10999.out"
/**/
using namespace std;
/**/
struct game{
                char c;
                int val;
            };
game crabb[15];
long ndic;
char dic[100010][100];
int d[15],len[100010];
int p;
/**/
void sapxep()
{
    int i,j;
    game temp;
    for(i=0;i<p-1;i++)
        for(j=i+1;j<p;j++)
            if(crabb[i].val < crabb[j].val)
            {
                temp = crabb[i];
                crabb[i] = crabb[j];
                crabb[j] = temp;
            }
}
/**/
int timchucai(char kt)
{
    int i;
    for(i=0;i<p;i++)
        if(kt == crabb[i].c && d[i] == 0)
        {
            d[i] = 1;
            return crabb[i].val;
        }
    return -1;
}
/**/
void solve()
{
    long i;
    int j;
    int tong,temp,kq;
    
    kq = 0;
    for(i=0;i<ndic;i++)
    {
        for(j=0;j<p;j++)
            d[j] = 0;
        tong = 0;
        for(j=0;j<len[i];j++)
        {
            temp = timchucai(dic[i][j]);            
            if(temp == -1)
            {
                tong = 0;
                break;
            }
            tong += temp;
        }
        if(tong > kq)
            kq = tong;
    }
    printf("%d\n",kq);
}
/**/
void input()
{
    char temp[1000];
    char kt;
    long i;
    int j;
    int np,gt;
    
    scanf("%ld",&ndic);    
    for(i=0;i<ndic;i++)
    {
        scanf("%s",&dic[i]);
        len[i] = strlen(dic[i]);
    }
    scanf("%d",&np);
    for(i=0;i<np;i++)
    {
        scanf("%d",&p);
        gets(temp);
        for(j=0;j<p;j++)
        {
            gets(temp);
            sscanf(temp,"%c %d",&kt,&gt);
            crabb[j].c = kt;
            crabb[j].val = gt;
        }
        sapxep();
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
