/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "11048.inp"
#define fo "11048.out"
#define maxn 10000
/**/
using namespace std;
/**/
int l[maxn+10];
char d[maxn+10][40],w[1000];
int n,m,len;
/**/
int missmuch(char s1[],int l1,char s2[],int l2)
{
    int i,j,k;
    
    i = 0;
    j = 0;
    k = 0;
    while(i < l1 && j < l2)
    {
        if(s1[i] != s2[j])
        {
            k++; // count diffirent
            j--;
        }
        i++;
        j++;
    }
    
    if(k <= 1)
        return 1;
    return 0;
}
/**/
bool same(char s1[],char s2[])
{
    int i;
    i = 0;
    
    while(s1[i])
    {
        if(s1[i] != s2[i])
            return false;
        i++;
    }
    return true;
}
/**/
int chk(char s1[],int l1)
{
    int dem;
    int i,j;
    int vt1,vt2;
        
    if(same(s1,w))
        return 2;
        
    vt1 = vt2 = -1;   
    dem = 0;
    for(i=0;i<l1;i++)
        if(s1[i] != w[i])
        {
            dem++;
            if(dem == 1)
                vt1 = i;
            if(dem == 2)    
                vt2 = i;
        }

    if(dem == 1)
        return 1;

    if(dem == 2)
        if(vt2 - vt1 == 1)
            if(s1[vt1] == w[vt2] && s1[vt2] == w[vt1])
                return 1;
    return 0;
}
/**/
void solve()
{
    int i;
    int flg;
    int vt;
    
    len = strlen(w);
    flg = 0;
    for(i=0;i<n;i++)
    {
        if(i == 6)
        {
            i = 6;
        }
        if(!flg)
        {
            if(l[i] == len + 1)
                flg = missmuch(d[i],l[i],w,len);
            else if(l[i] == len - 1)
                flg = missmuch(w,len,d[i],l[i]);
            else if(l[i] == len)
                flg = chk(d[i],l[i]);
            
            if(flg)
                vt = i;
                
            if(flg == 2)
                break;
        }
        else if(flg)
        {
            if(l[i] == len)
            {
                if(same(w,d[i]))                        
                {
                    flg = 2;
                    vt = i;
                }
                if(flg == 2)
                    break;
            }
        }
    }
    
    if(!flg)
        printf("%s is unknown\n",w);
    else if(flg == 1)
        printf("%s is a misspelling of %s\n",w,d[vt]);
    else
        printf("%s is correct\n",w);
}
/**/
void input()
{
    int i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",&d[i]);
        l[i] = strlen(d[i]);
    }
    scanf("%d",&m);
    while(m--)
    {
        scanf("%s",&w);
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
