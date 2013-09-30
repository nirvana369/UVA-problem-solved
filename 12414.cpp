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

#define fi "12414.inp"
#define fo "12414.out"
/**/
using namespace std;
/**/
char s[20];
int len,da;
int a[1000];
/**/
bool xuly(int st)
{
    int i,j;
    int tmp[1000];
    int val;
    int dem;
    
    da = 0;
    for(i=0;i<len;i++)
    {
        val = s[i] - 65 + st;
        dem = 0;
        while(val != 0)
        {
            tmp[dem++] = val % 10;
            val /= 10;
        }
        for(j=dem-1;j>=0;j--)
            a[da++] = tmp[j];
    }
    
    i = 0;
    while(i < 100)
    {
        for(i=0;i<da-1;i++)
        {
            a[i] += a[i+1];
            a[i] %= 10;
        }
        da--;
        if(da == 3)
            break;
        i++;
    }
    val = 0;
    for(i=0;i<da;i++)
    {
        val *= 10;
        val += a[i];
    }
    if(val == 100)
        return true;
    return false;
}
/**/
void input()
{
    int i;
    while(scanf("%s",&s) == 1)
    {
        len = strlen(s);
        for(i=1;i<=10000;i++)
            if(xuly(i))
                break;
        if(i > 10000)
            printf(":(\n");
        else
            printf("%d\n",i);
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
