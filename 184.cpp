/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "184.inp"
#define fo "184.out"
/**/
using namespace std;
/**/
struct toado{
                int x,y;
            };
            
toado l[310];
int len[310],kq[310][310];
int dkq,idl;
/**/
void swapl(int i,int j)
{
    toado tmp;
    tmp = l[i];
    l[i] = l[j];
    l[j] = tmp;
}
/**/
void sapxep()
{
    int i,j;
    
    for(i=0;i<idl;i++)
        for(j=i+1;j<idl;j++)
            if(l[i].x > l[j].x)
                swapl(i,j);
            else if(l[i].x == l[j].x)
                if(l[i].y > l[j].y)
                    swapl(i,j);
}
/**/
void kttrung()
{
    int i,j,k;
    
    for(i=0;i<dkq;i++)
    {
        k = 0;
        for(j=0;j<len[i];j++)
            if(kq[i][j] == kq[dkq][k])
                k++;
        if(k == len[dkq])
        {
            len[dkq] = 0;
            return;
        }
    }
    dkq++;
    len[dkq] = 0;
}
/**/
void kiemtra(int p,int q)
{
    int i;
    int a,b,c;
    
    a = l[p].y - l[q].y;
    b = l[q].x - l[p].x;
    c = -(a * l[p].x + b * l[p].y);
    
    for(i=q+1;i<idl;i++)
        if(i != p && i != q)
            if((c + a * l[i].x + b * l[i].y) == 0)
                kq[dkq][len[dkq]++] = i;
    if(len[dkq] < 3)
    {
        len[dkq] = 0;
        return;
    }
    kttrung();
}
/**/
void solve()
{
    int i,j;
    sapxep();
    
    dkq = 0;
    len[dkq] = 0;
    for(i=0;i<idl;i++)
        for(j=i+1;j<idl;j++)
        {
            kq[dkq][len[dkq]++] = i;
            kq[dkq][len[dkq]++] = j;
            kiemtra(i,j);
        }
        
    if(dkq)
    {
        printf("The following lines were found:\n");
        for(i=0;i<dkq;i++)
        {
            for(j=0;j<len[i];j++)
                printf("(%4d,%4d)",l[kq[i][j]].x,l[kq[i][j]].y);
            printf("\n");
        }
    }
    else
        printf("No lines were found\n");
}
/**/
void input()
{
    while(true)
    {
        scanf("%d %d",&l[0].x,&l[0].y);
        if(!l[0].x && !l[0].y)
            break;
        idl = 0;
        while(l[idl].x || l[idl].y)
        {
            idl++;
            scanf("%d %d",&l[idl].x,&l[idl].y);
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
