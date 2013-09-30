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

#define fi "10706.inp"
#define fo "10706.out"
/**/
using namespace std;
/**/
struct khoang{
                long dau,cuoi;
             };
khoang k[700000];
int vitri[1100000];
long kq,vt;
/**/
int layvitri(int id)
{
   int i,j; 
   long dem;
   char temp[1000000];
   i = 1;
   dem = 0;
   while(true)
   {
        sprintf(temp,"%d",i);
        j = 0;
        while(temp[j] != 0)
            vitri[dem++] = temp[j++] - 48;
        i++;
        if(dem > kq)
            break;
   }
   return vitri[kq];
}
/**/
void solve(long nut1,long nut2)
{
    long mid;
    mid = (nut1 + nut2) / 2;
    if(vt >= k[mid].dau && vt <= k[mid].cuoi)
    {
        kq = vt - k[mid].dau;
        kq = layvitri(mid);
        return;
    }
    
    if(vt > k[mid].cuoi)
        solve(mid+1,nut2);
    else
        solve(nut1,mid-1);
}
/**/
long xuly(int val)
{
    long tong;
    int bac;
    tong = 0;
    bac = 1;
    if(val > 9)
        tong = 9;
    else
        tong = val;
        
    if(val > 99)
        tong += 90 * 2;
    else if(val > 9)
        tong += (val-9)*2;
        
    if(val > 999) 
        tong += 900 * 3;
    else if(val > 99)
        tong += (val-99)*3;
        
    if(val > 9999) 
        tong += 9000 * 4;
    else if(val > 999)
        tong += (val-999)*4;
    
    if(val > 99999) 
        tong += 90000 * 5;
    else if(val > 9999)
        tong += (val-9999)*5;
        
    return tong;
}
/**/
void input()
{
    int ntest;
    long long i,j,xp,kt;
    int dem;
    long long tong;
    dem = 1;
    tong = 0;
    i = 2;
    i = i << 30;
    i--;
    j = 1;
    xp = 0;
    while(true)
    {
        kt = xuly(dem);
        tong+=kt;
        kt += xp;
        dem++;
        j++;
        if(tong > i)
            break;
        k[j].dau = xp + 1;
        k[j].cuoi = kt;
        xp = kt;
    }
    k[j].dau = k[j-1].cuoi+1;
    k[j].cuoi = i;
    
    
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%ld",&vt);
        solve(1,j);
        printf("%ld\n",kq);
    }
}
int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    input();
    return 0;
}
