/*
                                                            Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10523.inp"
#define fo "10523.out"
/**/
using namespace std;
/**/
int n,k;
/**/
void mul(char s1[],char s2[],char s[])
{
    int arr[10000];
    int l1,l2,l;
    int i,j;
    
    l1 = strlen(s1);
    l2 = strlen(s2);
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
                s[j] = arr[j] + 48;
            s[j] = 0;
            return;
        }
}
/**/
void add(char s1[],char s2[])
{
    int arr[10000];
    int l,l1,l2;
    int i,j;
    l1 = strlen(s1);
    l2 = strlen(s2);
    l = l1 + l2;
    for(i=l;i>=0;i--)
        arr[i] = 0;
    if(l1 > l2)
    {
        for(i=0;i<l1;i++)
        {
            if(i < l2)
            {
                arr[i] = arr[i] + (s1[i] - 48) + (s2[i] - 48);
                if(arr[i] > 9)
                {
                    arr[i] = arr[i] % 10;
                    arr[i+1]++;
                }
            }
            else
            {
                arr[i] = arr[i] + (s1[i] - 48);
                if(arr[i] > 9)
                {
                    arr[i] = arr[i] % 10;
                    arr[i+1]++;
                }
            }
        }
    }
    else
    {
        for(i=0;i<l2;i++)
        {
            if(i < l1)
            {
                arr[i] = arr[i] + (s1[i] - 48) + (s2[i] - 48);
                if(arr[i] > 9)
                {
                    arr[i] = arr[i] % 10;
                    arr[i+1]++;
                }
            }
            else
            {
                arr[i] = arr[i] + (s2[i] - 48);
                if(arr[i] > 9)
                {
                    arr[i] = arr[i] % 10;
                    arr[i+1]++;
                }
            }
        }    
    }
    
    for(i=l;i>=0;i--)
        if(arr[i] != 0)
        {
            for(j=0;j<=i;j++)
                s2[j] = arr[j] + 48;
            s2[j] = 0;
            return;
        }
}
/**/
void daochuoi(char s[])
{
    int i,l;
    char temp;
    l = strlen(s)-1;
    i = 0;
    while(i < l)
    {
        temp = s[i];
        s[i] = s[l];
        s[l] = temp;
        i++;
        l--;
    }
}
/**/
void solve()
{
    int i;
    int l;
    char temp[10000],a[10000],cs[10000],kq[10000],tg[10000];
    
    sprintf(temp,"%d",k);
    daochuoi(temp);
    strcpy(a,temp);
    strcpy(kq,a);
    for(i=2;i<=n;i++)
    {
        sprintf(cs,"%d",i);
        daochuoi(cs);
        mul(temp,a,temp);
        mul(temp,cs,tg);
        add(tg,kq);
    }
    l = strlen(kq);    
    for(i=l-1;i>=0;i--)
        printf("%c",kq[i]);
    printf("\n");
}
/**/
void input()
{
    while(true)
    {
        n = k = 0;
        scanf("%d %d",&n,&k);
        if(!n && !k)
            break;
        if(k == 0)
            printf("0\n");
        else
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
