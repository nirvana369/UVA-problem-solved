/*
                                                                Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "516.inp"
#define fo "516.out"
/**/
using namespace std;
/**/
int nt[1000000],d[1000000],luu[100000];
int cnt;
/**/
bool isnt(int value)
{
    int i;
    int temp,add;
    
    if(value < 2 || value % 2 == 0 || value % 3 == 0)
        return false;
    add = 2;
    temp = (int)sqrt(temp);
    
    for(i=5;i<=temp;i=i+add,add=6-add)
        if(value % i == 0)
            return false;
    return true;
}
/**/
void precal()
{
    int i;
    
    nt[0] = 2;
    d[2] = d[3] = 0;
    nt[1] = 3;
    cnt = 2;
    for(i=4;i<=32767;i++)
        if(isnt(i))
        {
            nt[cnt++] = i;
            d[i] = 0;
        }
}
/**/
void solve(char s[])
{
    int i,j;
    int l,flag,dem;
    char temp[1000];
    int num,mul;
    long long value;
    
    l = strlen(s);
    s[l] = ' ';
    dem = flag = 0;
    value = 1;
    for(i=0;i<=l;i++)
        if(s[i] == ' ' && dem != 0)
        {
            temp[dem] = 0;
            if(flag == 0)
            {
                sscanf(temp,"%d",&num);
                flag = 1;
            }
            else
            {
                sscanf(temp,"%d",&mul);
                flag = 0;
                for(j=1;j<=mul;j++)
                    value *= num;
            }
            dem = 0;
        }
        else
            temp[dem++] = s[i];
    value--;
    
    i = 0;
    dem = 1;
    luu[0] = 0;
    while(true)
    {
        if(i == cnt)
            break;
        while(value % nt[i] == 0)
        {
            value /= nt[i];
            d[nt[i]]++;
            if(nt[i] != luu[dem-1])
                luu[dem++] = nt[i];
        }
        i++;
    }
    for(i=dem-1;i>0;i--)
    {
        printf("%d %d",luu[i],d[luu[i]]);
        if(i != 1)
            printf(" ");
        d[luu[i]] = 0;
    }
    printf("\n");
}
/**/
void input()
{
    char temp[10000];
    int num;
    precal();
    while(true)
    {
        gets(temp);
        sscanf(temp,"%d",&num);
        if(num == 0)
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
