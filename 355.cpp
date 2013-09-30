/*
                                                    Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "355.inp"
#define fo "355.out"
/**/
using namespace std;
/**/
char s[10000];
int b,nb;
/**/
long long laybac(int giatri,int bac)
{
    long long value;
    int i;
    value = 1;
    for(i=0;i<bac;i++)
        value *= giatri;
    return value;
}
/**/
long long laygt(char kt)
{
    if(kt >= '0' && kt <= '9')
        return kt - 48;
    return kt - 55;
}
/**/
char laykytu(int value)
{
    if(value >= 0 && value < 10)
        return value + 48;
    return value + 55;
}
/**/
void dao(char s1[],int len)
{
    int i;
    char temp;
    i = 0;
    while(i < len)
    {
        temp = s1[i];
        s1[i] = s1[len];
        s1[len] = temp;
        i++;
        len--;
    }
}
/**/
void solve()
{
    char s1[10000];
    int i;
    long long value,temp;
    int len,bac,dem;
    
    value = 0;
    len = strlen(s);
    bac = len - 1;
    
    for(i=0;i<len;i++)
    {
        temp = laygt(s[i]);
        if(temp >= b)
        {
            printf("%s is an illegal base %d number\n",s,b);
            return;
        }
        value = value + temp * laybac(b,bac);  
        bac--;      
    }
    sprintf(s1,"%lld",value);
    if(nb != 10 && value != 0)
    {
        dem = 0;
        while(value != 0)
        {
            s1[dem] = laykytu(value % nb);
            value /= nb;
            dem++;
        }
        s1[dem] = 0;
        dao(s1,dem-1);
    }
    printf("%s base %d = %s base %d\n",s,b,s1,nb);
}
/**/
void input()
{
    while(!feof(stdin))
    {
        scanf("%d %d %s\n",&b,&nb,&s);
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
