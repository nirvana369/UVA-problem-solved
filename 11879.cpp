/*
                                                    Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "11879.inp"
#define fo "11879.out"
/**/
using namespace std;
/**/
void daochuoi(char s[],int j)
{
    int i;
    char temp;
    i = 0;
    j = j - 1;
    while(i < j)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
}
/**/
void donchuoi(char s[],int l)
{
    int i;
    for(i=0;i<l;i++)
        s[i] = s[i+1];
}
/**/
int sub(char s1[],char s2[],int l1,int l2)
{
    int i,j;
    int arr[10000];
    int temp;
    
    temp = l1 + l2;
    for(i=temp;i>=0;i--)
        arr[i] = 0;

    for(i=0;i<l1;i++)
    {
        if(i < l2)
        {
            arr[i] += (s1[i] - 48) - (s2[i] - 48);
            if(arr[i] < 0)
            {
                arr[i] += 10;
                arr[i+1]--;
            }
        }
        else
        {
            arr[i] += (s1[i] - 48);
            if(arr[i] < 0)
            {
                arr[i] += 10;
                arr[i+1]--;
            }
        }
    }
    
    for(i=temp;i>=0;i--)
        if(arr[i] != 0)
        {
            for(j=0;j<=i;j++)
                s1[j] = arr[j] + 48;
            return i+1;
        }
}
/**/
void solve(char s[])
{
    int l,ltemp;
    bool div;
    long long value;
    char temp[100];
    l = strlen(s);
    div = false;
    
    if(l < 20)
    {
        sscanf(s,"%lld",&value);
        if(value % 17 == 0)
            div = true;
    }
    else
    {
        daochuoi(s,l);
        while(l > 19)
        {
            value = (s[0] - 48) * 5;
            sprintf(temp,"%lld",value);
            ltemp = strlen(temp);
            daochuoi(temp,ltemp);
            donchuoi(s,l);
            l--;
            l = sub(s,temp,l,ltemp);
        }
        daochuoi(s,l);
        s[l] = 0;
        sscanf(s,"%lld",&value);
        if(value % 17 == 0)
            div = true;
    }
    
    if(div)
        printf("1\n");
    else
        printf("0\n");
}
/**/
void input()
{
    char temp[10000];
    while(true)
    {
        scanf("%s",&temp);
        if(temp[0] == '0' && strlen(temp) == 1)
            break;
        solve(temp);
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
