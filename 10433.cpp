/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "10433.inp"
#define fo "10433.out"
/**/
using namespace std;
/**/
bool mul(char s[],int l)
{
    int i,j;
    int arr[10000];
    char s1[10000];
    int len;
    
    if(l == 1)
        if(s[0] == '0' || s[0] == '1')
            return false;
    
    for(i=0;i<l;i++)
        s1[i] = s[l-i-1];
    
    i--;
    while(s1[i] == '0')
        i--;
    if(i < 0 || (!i && s1[0] == '1'))
        return false;
    
    l = i + 1;
    
    len = l * 2;
    
    for(i=len;i>=0;i--)
        arr[i] = 0;
        
    for(i=0;i<l;i++)
    {
        if((s1[i] - 48))
            for(j=0;j<l;j++)
                arr[i+j] += (s1[i] - 48) * (s1[j] - 48);
        arr[i+1] += arr[i] / 10;
        arr[i] %= 10;
        if(arr[i] != (s1[i] - 48))
            return false;
    }
    
    return true;
}
/**/
void input()
{
    char s[10000];
    int len;
    while(scanf("%s",&s) == 1)
    {
        len = strlen(s);
        if(mul(s,len))
            printf("Automorphic number of %d-digit.\n",len);
        else
            printf("Not an Automorphic number.\n");
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
