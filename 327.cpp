/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "327.inp"
#define fo "327.out"
/**/
using namespace std;
/**/
int val[200],tt[200],gt[200],ts[200],gs[200];
char s[1000],a[1000],kt[100];
bool d[200];
int len;
/**/
void sapxep(int c) //  char sorting
{
    int i,j;
    char x;
    
    for(i=0;i<c;i++)
        for(j=i+1;j<c;j++)
            if(kt[i] > kt[j])
            {
                x = kt[i];
                kt[i] = kt[j];
                kt[j] = x;
            }
}
/**/
void khoitao()
{
    char dau;
    int dem;
    int i,j,k,c;
    
    for(i='a';i<='z';i++)
    {
        val[i] = i-96;
        tt[i] = 0;  // tang truoc
        gt[i] = 0; //  giam truoc
        ts[i] = 0; //  tang sau
        gs[i] = 0; //  giam sau
    }
    i = j = c = 0;
    dau = 0;
    dem = 0;
    while(s[i])     // 
    {
        if(isalpha(s[i]))
        {
            if(dem == 2)
            {
                if(dau == '-')
                    gt[s[i]]--;
                else
                    tt[s[i]]++;
                j -= 2;
            }
            kt[c++] = s[i];
            a[j++] = s[i];
            d[s[i]] = true;
            dem = 0;
            dau = 0;
        }
        else if(s[i] == '-' || s[i] == '+')
        {
            a[j++] = s[i];
            
            if(dau == s[i])
                dem++;
            else
            {
                dau = s[i];
                dem = 1;
            }
            
            if(dem == 2)
            {
                for(k=j-1;k>=0;k--)
                    if(a[k] != s[i])
                        break;
                if(j >= 0 && isalpha(a[k]))
                {
                    if(s[i] == '-')
                        gs[a[k]]--;
                    else
                        ts[a[k]]++;
                    dem = 0;
                    dau = 0;
                    j -= 2;
                }
            }
        }
        i++;
    }
    kt[c] = 0;
    len = j;
    sapxep(c);
}
/**/
void solve()
{
    int i;
    int kq;
    
    i = 0;
    while(kt[i]) //  tang giam truoc
    {
        if(tt[kt[i]])
            val[kt[i]] += tt[kt[i]];
        else if(gt[kt[i]])
            val[kt[i]] += gt[kt[i]];
        i++;
    }
    
    kq = val[a[0]];         // calculation
    for(i=1;i<len;i+=2)
        if(a[i] == '+')
            kq += val[a[i+1]];
        else
            kq -= val[a[i+1]];
    
    i = 0;
    while(kt[i]) // tang giam sau
    {
        if(ts[kt[i]])
            val[kt[i]] += ts[kt[i]];
        else if(gs[kt[i]])
            val[kt[i]] += gs[kt[i]];
        i++;
    }
    //////////          output
    printf("Expression: %s\n",s);
    printf("    value = %d\n",kq);
    i = 0;
    while(kt[i])
    {
        printf("    %c = %d\n",kt[i],val[kt[i]]);
        i++;
    }
}
/**/
void input()
{
    while(gets(s))
    {
        khoitao();
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
