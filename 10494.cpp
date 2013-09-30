/*
                                                            Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10494.inp"
#define fo "10494.out"
/**/
using namespace std;
/**/
char n1[30000],s[1000],n2[30000];
/**/
void cutn(char tg[],int len)
{
    int i;
    for(i=0;i<len;i++)
        tg[i] = n1[i];
}
/**/
bool sosanh(char tg[],int len,long value)
{
    long long gt;
    tg[len] = 0;
    sscanf(tg,"%lld",&gt);
    if(gt > value)
        return true;
    return false;
}
/**/
int mul(char s1[],int l1,char s2[],int l2)
{
    int i,j;
    int arr[30000];
    int l;
    l = l1 + l2;
    for(i=l;i>=0;i--)
        arr[i] = 0;
    for(i=0;i<l1;i++)
        for(j=0;j<l2;j++)
        {
            arr[i+j] = arr[i+j] + (s1[i] - 48) * (s2[j] - 48);
            if(arr[i+j] > 9)
            {
                arr[i+j+1] = arr[i+j+1] + arr[i+j] / 10;
                arr[i+j] = arr[i+j] % 10;
            }
        }
    
    for(i=l;i>=0;i--)
        if(arr[i] != 0)
        {
            for(j=0;j<=i;j++)
                s1[j] = arr[j] + 48;
            s1[i+1] = 0;
            return i+1;
        }
    s1[0] = '0';
    s1[1] = 0;
    return 1;
}
/**/
int sub(char s1[],int l1,char s2[],int l2)
{
    int i,j;
    int arr[30000];
    int l;
    l = l1 + l2;
    for(i=l;i>=0;i--)
        arr[i] = 0;
    
    for(i=0;i<l1;i++)
        if(i < l2)
        {
            arr[i] = arr[i] + (s1[i] - 48) - (s2[i] - 48);
            if(arr[i] < 0)
            {
                arr[i] = arr[i] + 10;
                arr[i+1]--;
            }
        }
        else
        {
            arr[i] = arr[i] + (s1[i] - 48);
            if(arr[i] < 0)
            {
                arr[i] = arr[i] + 10;
                arr[i+1]--;
            }
        }
    
    for(i=l;i>=0;i--)
        if(arr[i] != 0)
        {
            for(j=0;j<=i;j++)
                s2[j] = arr[j] + 48;
            s2[i+1] = 0;
            return i+1;
        }
    s2[0] = '0';
    s2[1] = 0;
    return 1;
}
/**/
void daochuoi(char tg[],int len)
{
    int i;
    char temp;
    i = 0;
    while(i < len)
    {
        temp = tg[i];
        tg[i] = tg[len];
        tg[len] = temp;
        i++;
        len--;
    }
}
/**/
void solve()
{
    int i;
    int l1,l2,l,dem;
    long long gt1,gt2;
    char temp[30000];
    int kq[30000];
    
    l1 = strlen(n1);
    l2 = strlen(n2);
    sscanf(n2,"%lld",&gt2);
    
    if(gt2 == 1)
    {
        if(s[0] == '/')
            printf("%s\n",n1);
        else
            printf("0\n");
        return;
    }
    if(l1 < 20)
    {
        sscanf(n1,"%lld",&gt1);
        if(s[0] == '/')
            printf("%lld\n",gt1/gt2);
        else
            printf("%lld\n",gt1%gt2);
        return;
    }
    
    cutn(temp,l2);
    if(sosanh(temp,l2,gt2))
        l = l2;
    else
    {
        temp[l2] = n1[l2];
        l = l2+1;
    }
    i = l - 1;
    dem = 0;
    while(i < l1)
    {
        temp[l] = 0;
        sscanf(temp,"%lld",&gt1);
        kq[dem] = gt1 / gt2;
        gt1 = gt1 % gt2;
        sprintf(temp,"%lld",gt1);
        l = strlen(temp);
        i++;
        temp[l] = n1[i];
        l++;
        dem++;
    }
    if(s[0] == '%')
    {
        l = 0;
        for(i=dem-1;i>=0;i--)
            temp[l++] = kq[i] + 48;
        daochuoi(n2,l2-1);
        l = mul(temp,l,n2,l2);
        daochuoi(n1,l1-1);
        l = sub(n1,l1,temp,l);
        for(i=l-1;i>=0;i--)
            printf("%c",temp[i]);
    }
    else
    {
        for(i=0;i<dem;i++)
            printf("%d",kq[i]);
    }
    printf("\n");
}
/**/
void input()
{
    while(true)
    {
        n1[0] = 0;
        scanf("%s",&n1);
        if(n1[0] == 0)
            break;
        scanf("%s %s",&s,&n2);
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
