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

#define fi "117.inp"
#define fo "117.out"
/**/
using namespace std;
/**/
int a[30][30],nhan[30],huong[30],d[30];
long ketqua;
/**/
void khoitao()
{
    int i,j;
    for(i=0;i<28;i++)
    {
        for(j=0;j<28;j++)
            a[i][j] = 30000;
        d[i] = 0;
        nhan[i] = 30000;
        huong[i] = 0;
    }
    ketqua = 0;
}
/**/
int timmin()
{
    int i;
    int gt,vt;
    
    vt = -1;
    gt = 29000;
    for(i=0;i<28;i++)
        if(d[i] == 0 && nhan[i] < gt)
        {
            gt = nhan[i];
            vt = i;
        }
    return vt;
}
/**/
void gannhan(int xp)
{
    int i;
    for(i=0;i<28;i++)
        if(d[i] == 0 && nhan[xp] + a[xp][i] < nhan[i])
            nhan[i] = nhan[xp] + a[xp][i];
}
/**/
void solve()
{
    int i;
    int dau,cuoi;
    int tong;
    int start;
    d[-1] = 0;
    dau = cuoi = -1;
    start = -1;
    
    for(i=0;i<28;i++)
    {
        if(huong[i] % 2 != 0)
        {
            start = i;
            if(dau == -1)
                dau = i;
            else
                cuoi = i;
        }
    }
    
    if(dau != -1 && cuoi == -1)    
    {
        printf("%ld\n",ketqua);
        return;
    }
    
    nhan[dau] = 0;
    do
    {
        i = timmin();
        d[i] = 1;
        gannhan(i);
    }while(d[cuoi] == 0);
    
    printf("%ld\n",ketqua+nhan[cuoi]);
}
/**/
void input()
{
    char temp[1000];
    int len;
    bool test;
    while(true)
    {
        khoitao();
        test = false;
        while(scanf("%s",&temp) == 1)
        {
            if(strcmp(temp,"deadend") == 0)
            {
                solve();
                break;
            }
            test = true;
            len = strlen(temp);
            ketqua += len;
            a[temp[0] - 'a'][temp[len-1] - 'a'] = a[temp[len-1] - 'a'][temp[0] - 'a'] = len;
            huong[temp[0] - 'a']++;
            huong[temp[len-1] - 'a']++;
        }
        if(!test)
            break;
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
