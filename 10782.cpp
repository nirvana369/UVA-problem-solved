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

#define fi "10782.inp"
#define fo "10782.out"
/**/
using namespace std;
/**/
int l[10],d[100],val[100],dn[11];
char a[10][30],str[30];
int n,ds;
bool done;
/**/
void xuly(int id,char s[])
{
    int i;
    l[id] = strlen(s);
    for(i=l[id]-1;i>=0;i--)
        if(!d[s[i]])
        {
            d[s[i]] = 1;
            str[ds++] = s[i];
        }
}
/**/
void khoitao()
{
    int i;
    for(i='A';i<='Z';i++)
        d[i] = 0;
    for(i=0;i<10;i++)
        dn[i] = 0;
    ds = 0;
    done = false;
}
/**/
long long getval(int id)
{
    int i;
    long long val1;
    val1 = 0;
    for(i=0;i<l[id];i++)
    {
        val1 *= 10;
        val1 += val[a[id][i]];
    }
    return val1;
}
/**/
bool kiemtra()
{
    int i;
    long long val1,val2;
    if(l[n-1] != 1 && val[a[n-1][0]] == 0)
        return false;
    val1 = getval(n-1);
    val2 = 0;
    for(i=0;i<n-1;i++)
    {
        if(l[i] != 1 && val[a[i][0]] == 0)
            return false;
        val2 += getval(i);
        if(val2 > val1)
            return false;
    }
    if(val2 == val1)
        return true;
    return false;
}
/**/
void solve(int id)
{
    int i;
    if(id == ds)
    {
        done = kiemtra();
        return;
    }
    
    i = 0;
    while(i < 10)
    {
        if(!dn[i])
        {
            val[str[id]] = i;
            dn[i] = 1;
            
            solve(id+1);
            
            dn[i] = 0;
        }
        
        if(done)
            return;
        i++;
    }
}
/**/
void output()
{
    int i,tf;
    tf = 0;
    for(i='A';i<='Z';i++)
        if(d[i])
        {
            if(tf)
                printf(" ");
            printf("%c=%d",i,val[i]);
            tf++;
        }
    printf("\n");
}
/**/
void input()
{
    int i;
    int ntest;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d",&n);
        khoitao();
        for(i=0;i<n;i++)
        {
            scanf("%s",&a[i]);
            xuly(i,a[i]);
        }
        solve(0);
        output();
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
