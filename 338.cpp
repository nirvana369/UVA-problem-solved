/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "338.inp"
#define fo "338.out"
/**/
using namespace std;
/**/
long long a,b;
int s[100],s1[100],s2[100];
int l1,l2,len;
/**/
void chuyen(long long x,long long y)
{
    int i;
    
    i = 0;
    while(x != 0)
    {
        s1[i++] = x % 10;
        x /= 10;
    }
    l1 = i;
    
    i = 0;
    while(y != 0)
    {
        s2[i++] = y % 10;
        y /= 10;
    }
    l2 = i;
    
    if(!l1)
        l1++;
    if(!l2)
        l2++;
}
/**/
void mul()
{
    int i,j;
    
    len = l1 + l2 + 5;
    for(i=len;i>=0;i--)
        s[i] = 0;
    
    for(i=0;i<l1;i++)
        for(j=0;j<l2;j++)
        {
            s[i+j] += s1[i] * s2[j];
            if(s[i+j] > 9)
            {
                s[i+j+1] += s[i+j] / 10;
                s[i+j] %= 10;
            }
        }
    
    for(i=len;i>=0;i--)
        if(s[i] != 0)
        {
            len = i+1;
            return;
        }
}
/**/
void spc(int l)
{
    int i;
    for(i=0;i<l;i++)
        printf(" ");
}
/**/
void gach(int l)
{
    int i;
    for(i=0;i<l;i++)
        printf("-");
}
/**/
void xuly(int l,long long val)
{
    int i;
    i = 0;
    while(val != 0)
    {
        val /= 10;
        i++;
    }
    if(!i)
        i++;
    spc(l-i);
}
/**/
void output()
{
    int i,j;
    int maxlen,bonus;
    long long val;
    
    bonus = 0;
    maxlen = l1 > l2 ? l1 : l2;

    if(len)
        bonus = len - maxlen;
    
    if(l1 < l2)
    {
        spc(l2-l1+bonus);
        printf("%lld\n",a);
        spc(bonus);
        printf("%lld\n",b);
        spc(bonus);
        gach(l2);
    }
    else
    {
        spc(bonus);
        printf("%lld\n",a);
        spc(l1-l2+bonus);
        printf("%lld\n",b);
        spc(bonus);
        gach(l1);
    }
    printf("\n");
    if(!len)
    {
        spc(maxlen-1);
        printf("0\n");        
    }
    else
    {
        j = 0;
        for(i=0;i<l2;i++)
        {
            val = a * s2[i];
            if(val)         // dem xem co bao nhieu phep nhan khac 0
                j++;
        }
        
        if(j == 1)
        {
            for(i=len-1;i>=0;i--)
                printf("%d",s[i]);
            printf("\n");
        }
        else
        {
            for(i=0;i<l2;i++)
            {
                val = a * s2[i];
                if(val)
                {
                    xuly(len-i,val);
                    printf("%lld\n",val);
                }
            }
            gach(len);
            printf("\n");
            for(i=len-1;i>=0;i--)
                printf("%d",s[i]);
            printf("\n");
        }
    }
    printf("\n");
}
/**/
void input()
{
    char tmp[10000];
    while(true)
    {
        a = -1;
        b = -1;
        gets(tmp);
        sscanf(tmp,"%lld %lld",&a,&b);
        if(!a && b == -1)
            break;
        chuyen(a,b);
        if(!a || !b)
            len = 0;
        else
            mul();
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
