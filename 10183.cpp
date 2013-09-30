/*
                                            Hoang Linh
                                        
                                    Problem: HOW MANY FIBS? - 10183 (10183.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10183.inp"
#define fo "10183.out"
/**/
using namespace std;
/**/
char f[1000][200],a[1000],b[1000];
int len[1000];
int maxf;
/**/
void add(char s1[],int l1,char s2[],int l2,char s[],int id)
{
    int arr[1000];
    int mlen;
    int i,j;
    
    mlen = l1 + l2;
    for(i=mlen;i>=0;i--)
        arr[i] = 0;
    
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
    
    for(i=mlen;i>=0;i--)
        if(arr[i] != 0)
        {
            for(j=0;j<=i;j++)
                s[j] = arr[j] + 48;
            s[i+1] = 0;
            len[id] = i+1;
            return;
        }
}
/**/
void precal()
{
    int i,j;
    f[1][0] = '1';
    f[1][1] = 0;
    f[2][0] = '1';
    f[2][1] = 0;
    f[3][0] = '2';
    f[3][1] = 0;
    f[4][0] = '3';
    f[4][1] = 0;
    f[5][0] = '5';
    f[5][1] = 0;
    f[6][0] = '8';
    f[6][1] = 0;

    for(i=1;i<7;i++)
        len[i] = 1;
    i = 7;
    while(true)
    {
        add(f[i-1],len[i-1],f[i-2],len[i-2],f[i],i);
        if(len[i] >= 102)
            break;
        i++;
    }
    maxf = i;
}
/**/
int kiemtra(char s[],char s1[])
{
    int i,j;
    int l,l1;
    l = strlen(s);
    l1 = strlen(s1);
    if(l > l1)
        return 1;
    else if(l == l1)
    {
        j = 0;
        
        for(i=l-1;i>=0;i--,j++)
            if(s[i] > s1[j])
                return 1;
            else if(s[i] < s1[j])
                return 0;
        return 2;
    }
    
    return 0;
}
/**/
void solve()
{
    int i,j;
    int dem,temp;
    dem = 0;
    for(i=2;i<maxf;i++)
    {
        temp = kiemtra(f[i],a);
        if(temp != 0)
            break;
    }
    
    for(j=i;j<maxf;j++)
    {
        temp = kiemtra(f[j],b);
        if(temp != 0)
            break;
        dem++;
    }
    if(temp == 2)
        dem++;
    printf("%d\n",dem);
}
/**/
void input()
{
    precal();
    while(true)
    {
        scanf("%s %s",&a,&b);
        if(a[0] == '0' && b[0] == '0')
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
