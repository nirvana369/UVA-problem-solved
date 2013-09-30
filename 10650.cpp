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

#define fi "10650.inp"
#define fo "10650.out"
/**/
using namespace std;
/**/
int nt[20000],p[200][10],l[200];
int dnt,id;
int dau,cuoi;
/**/
bool isnt(int val)
{
    int i;
    int add,temp;
    
    if(val == 2 || val == 3)
        return true;
    if(val % 2 == 0 || val % 3 == 0)
        return false;
    temp = (int)sqrt(val);
    add = 2;
    for(i=5;i<=temp;i+=add,add=6-add)
        if(val % i == 0)
            return false;
    return true;
}
/**/
void capnhap(int s,int e)
{
    int i,j;
    
    for(i=s,j=0;i<=e;i++,j++)
        p[id][j] = nt[i];
    l[id] = j;
}
/**/
void precal()
{
    int i;
    int congsai;
    
    dnt = 0;
    congsai = 0;
    dau = 0;
    id = 0;
    for(i=2;i<32000;i++)
        if(isnt(i))
        {
            nt[dnt] = i;
            if(dnt)
            {
                if(nt[dnt]-nt[dnt-1] != congsai)
                {
                    cuoi = dnt-1;
                    if(cuoi - dau > 1)
                    {
                        capnhap(dau,cuoi);
                        id++;
                    }
                    congsai = nt[dnt]-nt[dnt-1];
                    dau = dnt-1;
                }
            }
            dnt++;
        }
}
/**/
void output(int m)
{
    int i;
    for(i=0;i<l[m];i++)
    {
        if(i)
            printf(" ");
        printf("%d",p[m][i]);
    }
    printf("\n");
}
/**/
void solve()
{
    int i;
    if(dau > cuoi)
    {
        i = dau;
        dau = cuoi;
        cuoi = i;
    }
    for(i=0;i<id;i++)
    {
        if(p[i][0] >= cuoi)
            break;
        if(p[i][0] >= dau && p[i][l[i]-1] <= cuoi)
            output(i);
    }
}
/**/
void input()
{
    precal();
    while(scanf("%d %d",&dau,&cuoi) == 2)
    {
        if(!dau && !cuoi)
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
