/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "787.inp"
#define fo "787.out"
/**/
using namespace std;
/**/
struct numb{
                int len,sig;
                char s[700];
            };
numb gt[10000];
numb maxgt;
int n,m;
/**/
void xuly(long val)
{
    int i;
    
    if(val < 0)
    {
        gt[n].sig = 1;
        val *= -1;
    }
    else
        gt[n].sig = 0;
    
    i = 0;
    while(val != 0)
    {
        gt[n].s[i++] = (val % 10) + 48;
        val /= 10;
    }
    if(!i)
        gt[n].s[i++] = '0';

    gt[n].s[i] = 0;
    gt[n].len = i;
    n++;
}
/**/
void mul(char s1[],int l1,char s2[],int l2)
{
    int arr[1000];
    int l;
    int i,j;
    
    l = l1 + l2 + 10;
    for(i=l;i>=0;i--)
        arr[i] = 0;
        
    for(i=0;i<l1;i++)
        for(j=0;j<l2;j++)
        {
            arr[i+j] += (s1[i] - 48) * (s2[j] - 48);
            if(arr[i+j] > 9)
            {
                arr[i+j+1] += arr[i+j] / 10;
                arr[i+j] %= 10;
            }
        }
    
    for(i=l;i>=0;i--)
        if(arr[i] != 0)
        {
            for(j=0;j<=i;j++)
                gt[n].s[j] = (arr[j] + 48);
            gt[n].s[j] = 0;
            gt[n].len = j;
            return;
        }
        
    gt[n].s[0] = '0';
    gt[n].len = 1;
}
/**/
void getmax(int id)
{
    int i;
    if(gt[id].sig > maxgt.sig)
        return;
    if(maxgt.sig > gt[id].sig)
    {
        maxgt = gt[id];
        return;
    }
    
    if(maxgt.sig)
    {
        if(gt[id].len > maxgt.len)
            return;
        if(gt[id].len < maxgt.len)
        {
            maxgt = gt[id];
            return;
        }
        
        i = maxgt.len-1;
        while(maxgt.s[i])
        {
            if(gt[id].s[i] > maxgt.s[i])
                return;
            if(maxgt.s[i] > gt[id].s[i])
                break;
            i--;
        }
        maxgt = gt[id];
        return;
    }
    
    if(gt[id].len < maxgt.len)
        return;
    
    if(gt[id].len > maxgt.len)
    {
        maxgt = gt[id];
        return;
    }
        
    i = maxgt.len-1;
    while(maxgt.s[i])
    {
        if(gt[id].s[i] < maxgt.s[i])
            return;
        if(maxgt.s[i] < gt[id].s[i])
            break;
        i--;
    }
    maxgt = gt[id];
}
/**/
void solve()
{
    int i;
    int id;
    
    id = n-1;
    
    getmax(id);
    for(i=id-1;i>=m;i--)
    {
        mul(gt[id].s,gt[id].len,gt[i].s,gt[i].len);
        if(gt[id].sig == gt[i].sig)
            gt[n].sig = 0;
        else
            gt[n].sig = 1;
        getmax(n);
        n++;
    }
}
/**/
void input()
{
    int i;
    int flg,tmp;
    long val;
    
    while(true)
    {
        n = 0;
        m = 0;
        while(true)
        {
            flg = scanf("%ld",&val);
            if(flg < 1)
                return;
            if(val == -999999)
                break;
            xuly(val);
            tmp = n-1;
            if((n-1))
                solve();
            else
                maxgt = gt[0];
            m = tmp;
        }
        if(maxgt.sig)
            printf("-");
        for(i=maxgt.len-1;i>=0;i--)
            printf("%c",maxgt.s[i]);
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
