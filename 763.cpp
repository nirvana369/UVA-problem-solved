/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "763.inp"
#define fo "763.out"
/**/
using namespace std;
/**/
char val[150],f[110][150];
/**/
bool cmps(char s1[],char s2[])
{
    int l1,l2;
    l1 = strlen(s1);
    l2 = strlen(s2);
    
    if(l1 > l2)
        return true;
    if(l1 == l2)
    {
        for(l1=l2-1;l1>=0;l1--)
        {
            if(s1[l1] > s2[l1])
                return true;
            if(s1[l1] < s2[l1])
                return false;
        }
        return true;
    }
    return false;
}
/**/
void subt(char s1[],char s2[])
{
    int i,j;
    int l1,l2;
    int arr[110];
    
    l1 = strlen(s1);
    l2 = strlen(s2);
    
    for(i=0;i<=l1+l2;i++)
        arr[i] = 0;
    
    for(i=0;i<l1;i++)
    {
        if(i < l2)
        {
            arr[i] += (s1[i] - 48) - (s2[i] - 48);
            if(arr[i] < 0)
            {
                arr[i+1]--;
                arr[i] += 10;
            }
        }
        else
        {
            arr[i] += (s1[i] - 48);
            if(arr[i] < 0)
            {
                arr[i+1]--;
                arr[i] += 10;
            }
        }
    }
    
    for(i=l1+l2;i>=0;i--)
        if(arr[i] > 0)
        {
            for(j=0;j<=i;j++)
                s1[j] = arr[j] + 48;
            s1[j] = 0;
            return;
        }
    s1[0] = '0';
    s1[1] = 0;
}
/**/
void add(char s[],char s1[],char s2[])
{
    int i,j;
    int l1,l2;
    int arr[110];
    
    l1 = strlen(s1);
    l2 = strlen(s2);
    for(i=l1+l2;i>=0;i--)
        arr[i] = 0;
        
    for(i=0;i<l2;i++)
    {
        if(i < l1)
        {
            arr[i] += (s1[i] - 48) + (s2[i] - 48);
            if(arr[i] > 9)
            {
                arr[i+1]++;
                arr[i] %= 10;
            }
        }
        else
        {
            arr[i] += (s2[i] - 48);
            if(arr[i] > 9)
            {
                arr[i+1]++;
                arr[i] %= 10;
            }
        }
    }
    
    for(i=l1+l2;i>=0;i--)
        if(arr[i] != 0)
        {
            for(j=0;j<=i;j++)
                s[j] = arr[j] + 48;
            s[j] = 0;
            return;
        }
}
/**/
void _init()
{
    int i;
    f[1][0] = '1';
    f[1][1] = 0;
    f[2][0] = '2';
    f[2][1] = 0;
    for(i=3;i<106;i++)
        add(f[i],f[i-2],f[i-1]);
}
/**/
void getval(char s1[],char s[])
{
    int i;
    int l;

    l = strlen(s);
    s1[0] = '0';
    s1[1] = 0;
    
    for(i=0;i<l;i++)
        if(s[i] == '1')
        {
            if(cmps(s1,f[l-i]))        
                add(s1,f[l-i],s1);
            else
                add(s1,s1,f[l-i]);
        }
}
/**/
void solve()
{
    int i;
    
    if(strlen(val) == 1 && val[0] == '0')    
    {
        printf("0\n");    
        return;
    }
    
    for(i=105;i>=1;i--)
        if(cmps(val,f[i]))
            break;
        
    while(i > 0)
    {
        if(cmps(val,f[i]))
        {
            printf("1");
            subt(val,f[i]);
        }
        else
            printf("0");
        i--;
    }

    printf("\n");
}
/**/
void input()
{
    int id;
    char s[110],s1[110],s2[110];
    
    _init();
    id = 0;
    while(scanf("%s %s",&s,&val) == 2)
    {
        getval(s1,s);   
         
        getval(s2,val);
        
        if(cmps(s2,s1))
            add(val,s1,s2);
        else
            add(val,s2,s1);
            
        if(id)
            printf("\n");
        solve();
        id++;
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
