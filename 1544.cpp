/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
//#include <queue>
//#include <vector>
//#include <map>

#define fi "1544.inp"
#define fo "1544.out"
/**/
using namespace std;
/**/
int cong(char s1[],char s2[],int l1,int l2,char s3[])
{
    int i,j;
    int arr[1500];
    int l;
    
    l = l1 + 2;
    
    for(i=l;i>=0;i--)
        arr[i] = 0;
    l1--;
    l2--;
    for(i=0;i<=l1;i++)
    {
        if(i <= l2)
            arr[i] += (s1[l1-i] - 48) + (s2[l2-i] - 48);
        else
            arr[i] += (s1[l1-i] - 48);
        if(arr[i] > 9)
        {
            arr[i] %= 10;
            arr[i+1]++;
        }
    }
    
    for(i=l;i>=0;i--)
        if(arr[i])
        {
            for(j=0;j<=i;j++)
                s3[j] = arr[i-j] + 48;
            s3[i+1] = 0;
            return i+1;
        }
    
    s3[0] = '0';
    s3[1] = 0;
    return 1;
}
/**/
int tru(char s1[],char s2[],int l1,int l2,char s3[])
{
    int i,j;
    int arr[1500];
    int l;
    
    l = l1 + 2;
    
    for(i=l;i>=0;i--)
        arr[i] = 0;
    l1--;
    l2--;
    for(i=0;i<=l1;i++)
    {
        if(i<=l2)
            arr[i] += (s1[l1-i] - 48) - (s2[l2-i] - 48);
        else
            arr[i] += (s1[l1-i] - 48);
        if(arr[i] < 0)
        {
            arr[i] += 10;
            arr[i+1]--;
        }
    }
    
    for(i=l;i>=0;i--)
        if(arr[i])
        {
            for(j=0;j<=i;j++)
                s3[j] = arr[i-j] + 48;
            s3[i+1] = 0;
            return i+1;
        }
        
    s3[0] = '0';
    s3[1] = 0;
    return 1;
}
/**/
int nhan(char s1[],char s2[],int l1,int l2,char s3[])
{
    int i,j;
    int arr[1500];
    int l;
    
    l = l1 + l2 + 2;
    
    for(i=l;i>=0;i--)
        arr[i] = 0;
    l1--;
    l2--;
    for(i=0;i<=l1;i++)
    {
        for(j=0;j<=l2;j++)
        {
            arr[i+j] += (s1[l1-i] - 48) * (s2[l2-j] - 48);
            if(arr[i+j] > 9)
            {
                arr[i+j+1] += arr[i+j] / 10;
                arr[i+j] %= 10;
            }
        }
    }
    
    for(i=l;i>=0;i--)
        if(arr[i])
        {
            for(j=0;j<=i;j++)
                s3[j] = arr[i-j] + 48;
            s3[i+1] = 0;
            return i+1;
        }
        
    s3[0] = '0';
    s3[1] = 0;
    return 1;
}
/**/
bool sosanh(char s1[],char s2[],int l1,int l2)
{
    int i;
    
    if(l1 > l2)
        return true;
    if(l2 > l1)
        return false;
    
    for(i=0;i<l1;i++)
    {
        if(s1[i] > s2[i])
            return true;
        if(s2[i] > s1[i])
            return false;
    }
    return true;
}
/**/
void pblank(int x)
{
    int i;
    for(i=0;i<x;i++)
        printf(" ");
}
/**/
void pdash(int x)
{
    int i;
    for(i=0;i<x;i++)
        printf("-");
}
/**/
void solve(char s[])
{
    int i,j;
    char tt;
    char s1[1000],s2[1000],s3[1500],s4[1500];
    int l1,l2,l3,l,maxlen;
    
    l = strlen(s);
    
    for(i=0,j=0;i<l;i++)
        if(s[i] >= '0' && s[i] <= '9')
            s1[j++] = s[i];
        else
        {
            tt = s[i];
            i++;
            break;
        }
        
    s1[j] = 0;
    l1 = j;
    j = 0;
    while(i < l)
    {
        if(s[i] >= '0' && s[i] <= '9')
            s2[j++] = s[i];
        i++;
    }
    s2[j] = 0;
    l2 = j;
    
    if(tt == '-')
        l3 = tru(s1,s2,l1,l2,s3);
    else if(tt == '*')    
        l3 = nhan(s1,s2,l1,l2,s3);
    else
    {
        if(sosanh(s1,s2,l1,l2))
            l3 = cong(s1,s2,l1,l2,s3);
        else
            l3 = cong(s2,s1,l2,l1,s3);
    }
    
    maxlen = max(max(l1,l2+1),l3);
    
    pblank(maxlen-l1);
    printf("%s\n",s1);
    pblank(maxlen-(l2+1));
    printf("%c%s\n",tt,s2);
    
    if(tt == '+' || tt == '-')
    {
        pdash(maxlen);
        printf("\n");
        pblank(maxlen-l3);
        printf("%s\n",s3);
    }
    else
    {
        pblank(maxlen - max(l1,l2+1));
        pdash(max(l1,l2+1));
        printf("\n");
        for(i=0;i<l2;i++)
        {
            s4[0] = s2[l2-i-1];
            l = nhan(s1,s4,l1,1,s4);
            pblank(maxlen-i-l);
            printf("%s\n",s4);
        }
        if(l2 > 1)
        {
            pdash(maxlen);
            printf("\n");
            pblank(maxlen-l3);
            printf("%s\n",s3);
        }
    }
    printf("\n");
}
/**/
void input()
{
    int ntest;
    char s[10000];
    
    scanf("%d",&ntest);
    gets(s);
    while(ntest--)
    {
        gets(s);  
        solve(s);
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
