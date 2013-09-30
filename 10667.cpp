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
#include <vector>

#define fi "10667.inp"
#define fo "10667.out"
/**/
using namespace std;
/**/
int a[110][110];
int nhang,ncot;
/**/
int capnhap(int r1,int c1,int r2,int c2,int kc)
{
    int i,j;
    int temp,tg;
    
    temp = 0;
    for(i=r1;i<=r2;i++)
    {
        for(j=c1;j<=c2;j++)
            if(a[i][j] == 1)
                break;
        if(j > c2)
            temp += c2-c1+1;
        else
            break;
    }
    
    kc = (temp > kc) ? temp : kc;
    
    temp = 0;
    for(i=c1;i<=c2;i++)
    {
        for(j=r1;j<=r2;j++)
            if(a[j][i] == 1)
                break;
        if(j > r2)
            temp += r2-r1+1;
        else
            break;
    }
    kc = (temp > kc) ? temp : kc;
    return kc;
}
/**/
void solve()
{
    int i,j,k,hang,cot;
    int maxsq,temp;
    bool cont_c,cont_r;
    
    maxsq = 0;
    for(i=0;i<nhang;i++)
        for(j=0;j<ncot;j++)
            if(a[i][j] == 0)
            {
                maxsq = 1 < maxsq ? maxsq : 1;
                hang = i;
                cot = j;
                
                while(hang < nhang && cot < ncot)
                {
                    cont_r = cont_c = false;
                    if(hang +1 < nhang && a[hang+1][j] == 0)
                        cont_r = true;
                    if(cot + 1 < ncot && a[i][cot+1] == 0)
                        cont_c = true;
                        
                    if(cont_r && hang + 1 < nhang)
                        hang++;
                    else
                        cont_r = false;
                        
                    if(cont_c && cot + 1 < ncot)
                        cot++;
                    else
                        cont_c = false;
                        
                    if(!cont_r && !cont_c)
                        break;
                        
                    maxsq = capnhap(i,j,hang,cot,maxsq);
                        
                }
                
            }
    printf("%d\n",maxsq);
}
/**/
void khoitao()
{
    int i,j;
    ncot = nhang;
    for(i=0;i<nhang;i++)
        for(j=0;j<ncot;j++)
            a[i][j] = 0;
}
/**/
void input()
{
    int i,j,k;
    int r1,c1,r2,c2;
    int ntest,m;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d",&nhang);

        khoitao();
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
            r1--;
            r2--;
            c1--;
            c2--;
            for(j=r1;j<=r2;j++)
                for(k=c1;k<=c2;k++)
                    a[j][k] = 1;
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
