/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "153.inp"
#define fo "153.out"
/**/
using namespace std;
/**/
int d[200];
char s[35];
/**/
int gcd(int x,int y)
{
    if(!y)
        return x;
    return gcd(y,x % y);
}
/**/
void resetd()
{
    int i;
    
    for(i='a';i<='z';i++)
        d[i] = 0;
}
/**/
long long cal(int len,char kt)
{
    int i,j,k;
    long long vala,valb,val;
    int da,db;
    int a[30000],b[30000];
    int tmp;
        
    val = 0;
    
    for(i='a';i<kt;i++)
        if(d[i])
        {
            d[i]--;
            da = db = 0;
            for(j=2;j<=len;j++)
                a[da++] = j;
                
            for(j='a';j<='z';j++)                    
                if(d[j] > 1)
                    for(k=2;k<=d[j];k++)
                        b[db++] = k;
                        
            vala = valb = 1;
            for(j=0;j<da;j++)
            {
                for(k=0;k<db;k++)
                {
                    tmp = gcd(a[j],b[k]);
                    a[j] /= tmp;
                    b[k] /= tmp;
                }
                vala *= a[j];
            }
            for(k=0;k<db;k++)
                valb *= b[k];
            vala /= valb;
            val += vala;
            d[i]++;
        }
    //printf("%lld\n",val);
    return val;
}
/**/
void solve()
{
    int i,j;
    long long perma;
    int len;
    
    i = 0;
    perma = 0;
    while(s[i])
    {
        resetd();
        for(j=i;s[j];j++)
            d[s[j]]++;
        len = j - i - 1;
        perma += cal(len,s[i]);
        i++;
    }
    printf("%10lld\n",perma+1);
}
/**/
void input()
{
    while(true)
    {
        gets(s);
        if(s[0] == '#')
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
