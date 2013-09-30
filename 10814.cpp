/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "10814.inp"
#define fo "10814.out"
/**/
using namespace std;
/**/
bool chk(char s1[],char s2[],int l1,int l2) //  so sanh 2 so
{
    int i;
    if(l1 > l2)
        return true;
    if(l1 < l2)
        return false;
    i = 0;
    while(i < l1)
    {
        if(s1[i] > s2[i])
            return true;
        if(s1[i] < s2[i])
            return false;
        i++;
    }
    return true;
}
/**/
int sub(char s1[],char s2[],int l1,int l2,char s3[]) //  subtract function
{
    int i,j;
    int arr[1000];
    
    for(i=l1;i>=0;i--)
        arr[i] = 0;
    l1--;
    l2--;
    for(i=0;i<=l1;i++)
    {
        if(l2 >= 0)
        {
            arr[i] += (s1[l1-i] - 48) - (s2[l2] - 48);
            if(arr[i] < 0)
            {
                arr[i+1]--;
                arr[i] += 10;
            }
            l2--;
        }
        else
        {
            arr[i] += (s1[l1-i] - 48);
            if(arr[i] < 0)
            {
                arr[i+1]--;
                arr[i] += 10;
            }
        }
    }
    
    for(i=l1+1;i>=0;i--)
        if(arr[i] > 0)
        {
            for(j=i;j>=0;j--)
                s3[i-j] = arr[j] + 48;
            s3[i+1] = 0;
            return (i+1);
        }
    return 0;
}
/**/
int divmod(char s1[],char s2[],int l1,int l2,char s3[]) // get mod big-num function
{
    int i;
    int len;
    char tmp[100];
    
    len = 0;
    if(!(l2 == 1 && s2[0] == '1'))
        for(i=0;i<l1;i++)
        {
            tmp[len++] = s1[i];
            if(chk(tmp,s2,len,l2))
                len = sub(tmp,s2,len,l2,tmp);
        }
    
    if(!len)
        tmp[len++] = '0';
    tmp[len] = 0;
    strcpy(s3,tmp);
    return len;
}
/**/
/**/
int divs(char s1[],char s2[],int l1,int l2,char s3[]) //  div big-num function
{
    int i,j;
    int len,l,dem;
    char tmp[100],kq[100],tg[100];
    
    len = l = 0;
    for(i=0;i<l1;i++)
    {
        tmp[len++] = s1[i];
        if(len && tmp[0] == '0')
            len = 0;
        if(chk(tmp,s2,len,l2))
        {
            dem = 0;
            while(chk(tmp,s2,len,l2))
            {
                len = sub(tmp,s2,len,l2,tmp);
                dem++;
            }
            tg[0] = 0;
            sprintf(tg,"%d",dem);
            j = 0;
            while(tg[j])
                kq[l++] = tg[j++];
        }
        else if(l)
            kq[l++] = '0';
    }
    
    if(!l)
        kq[l++] = '1';
    kq[l] = 0;
    strcpy(s3,kq);
}
/**/
int ucln(char s1[],char s2[],char s3[]) //  GCD big-num
{
    int l1,l2;
    
    l1 = strlen(s1);
    l2 = strlen(s2);
    while(true)
    {
        if(l1 == 1 && s1[0] == '0' || l2 == 1 && s2[0] == '0')
            break;
        if(chk(s1,s2,l1,l2))
            l1 = divmod(s1,s2,l1,l2,s1);
        else
            l2 = divmod(s2,s1,l2,l1,s2);
    }
    if(l1 == 1 && s1[0] == '0')
    {
        strcpy(s3,s2);
        return l2;
    }
    
    strcpy(s3,s1);
    return l1;
}
/**/
void input()
{
    int l,la,lb;
    char a[100],b[100],tga[100],tgb[100],slh[10];
    
    int ntest;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%s %s %s",&a,&slh,&b);
        strcpy(tga,a);
        strcpy(tgb,b);
        l = ucln(tga,tgb,tga);
        if(l == 1 && tga[0] == '1')
            printf("%s / %s\n",a,b);
        else
        {
            la = strlen(a);    
            lb = strlen(b);
            divs(a,tga,la,l,a);
            divs(b,tga,lb,l,b);
            printf("%s / %s\n",a,b);
        }
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
