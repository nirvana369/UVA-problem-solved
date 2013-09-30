/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <queue>
#include <iostream>

#define fi "10896.inp"
#define fo "10896.out"
/**/
using namespace std;
/**/
char s[100],key[100];
/**/
int kiemtra(char text[],int len)
{
    int i;
    int temp,minval;
    minval = text[0] - key[0];
    minval = minval < 0 ? 26+minval:minval;
    for(i=1;i<len;i++)
    {
        temp = text[i] - key[i];
        temp = temp < 0 ? temp+26:temp;
        if(temp != minval)
            return -1;
    }
    return minval;
}
/**/
void sapxep(char text[],int len)
{
    int i,j;
    char temp;
    for(i=0;i<len-1;i++)
        for(j=i+1;j<len;j++)
            if(text[i] > text[j])
            {
                temp = text[i];
                text[i] = text[j];
                text[j] = temp;
            }
}
/**/
void output(char text[],int len)
{
    text[len] = 0;
    printf("%s\n",text);
}
/**/
void solve()
{
    int i;
    int l,dem,lk,id,val;
    char temp[100],kq[100];
    
    l = strlen(s);
    s[l] = ' ';
    lk = strlen(key);
    dem = 0;
    id = 0;
    for(i=0;i<=l;i++)
        if(s[i] >= 'a' && s[i] <= 'z')
            temp[dem++] = s[i];
        else
        {
            temp[dem] = 0;
            if(dem == lk)
            {
                val = kiemtra(temp,dem);
                if(val != -1)
                    kq[id++] = 97 + val;
            }
            dem = 0;
        }
    sapxep(kq,id);
    output(kq,id);
}
/**/
void input()
{
    int ntest;
    scanf("%d",&ntest);
    gets(s);
    while(ntest--)
    {
        gets(s);
        gets(key);
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
