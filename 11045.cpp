/*
                                                Hoang Linh
                                                
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define fi "11045.inp"
#define fo "11045.out"
/**/
using namespace std;
/**/
int a[40][40],trai[40],phai[40],q[40],d[40],tr[40];
int nv,nt,lasts;
/**/
void khoitao()
{
    int i,j;
    for(i=1;i<=nv;i++)
    {
        for(j=i;j<=nt;j++)
        {
            a[i][j] = 0;
            a[j][i] = 0;
        }
        phai[i] = 0;
        trai[i] = 0;
    }
    
    for(i=nv;i<=nt;i++)
        trai[i] = 0;
}
/**/
int findsize(char s[])
{
    if(strcmp(s,"XXL") == 0)
        return 1;
    if(strcmp(s,"XL") == 0)
        return 2;
    if(strcmp(s,"L") == 0)
        return 3;
    if(strcmp(s,"M") == 0)
        return 4;
    if(strcmp(s,"S") == 0)
        return 5;
    if(strcmp(s,"XS") == 0)
        return 0;
}
/**/
void danhdau(int volun,int size)
{
    int temp;
    temp = 0;
    
    if(size == 0)
    {
        if(nt >= 6)
            a[volun][6] = 1;
    }    
    else if(size <= nt)
        a[volun][size] = 1;
    
    while(true)
    {
        temp = temp + 6;
        if(temp > nt || temp + size > nt)
            return;
        a[volun][temp+size] = 1;
    }    
}
/**/
bool timduong(int xp)
{
    int i;
    int dau,cuoi;
    
    dau = -1;
    cuoi = 0;
    
    for(i=1;i<=nt;i++)
        d[i] = 0;
        
    q[0] = xp;
    tr[0] = 0;
    
    while(dau != cuoi)
    {
        dau++;
        for(i=1;i<=nt;i++)
            if(a[q[dau]][i] == 1 && d[i] == 0)
            {
                if(trai[i] == 0)
                {
                    tr[i] = q[dau];
                    lasts = i;
                    return true;
                }
                cuoi++;
                q[cuoi] = trai[i];
                tr[i] = q[dau];
                d[i] = 1;
            }
    }
    return false;
}
/**/
void tomau(int xp)
{
    int i,j,temp;
    j = lasts;
    do
    {
        i = tr[j];
        temp = phai[i];
        phai[i] = j;
        trai[j] = i;
        j = temp;
    }while(i != xp);
}
/**/
void solve()
{
    int i;
    int dem;
    bool coduong;
    
    dem = 0;
    
    for(i=1;i<=nv;i++)
    {
        coduong = false;
        
        coduong = timduong(i);    
        if(coduong)
        {
            tomau(i);
            dem++;
        }
    }
    
    if(dem >= nv)
        printf("YES\n");
    else
        printf("NO\n");
}
/**/
void input()
{
    int itest,i;
    int ntest;
    char temp[100],size1[7],size2[7];
    int size;
    scanf("%d",&ntest);
    for(itest=0;itest<ntest;itest++)
    {
        scanf("%d %d",&nt,&nv);
        khoitao();
        gets(temp);
        for(i=1;i<=nv;i++)
        {
            gets(temp);
            sscanf(temp,"%s %s",&size1,&size2);
            size = findsize(size1);
            danhdau(i,size);
            size = findsize(size2);
            danhdau(i,size);
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

#define fi ".inp"
#define fo ".out"
/**/
using namespace std;
/**/
void input()
{

}
/**/
int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    input();
    return 0;
}
