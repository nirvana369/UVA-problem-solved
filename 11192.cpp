/*
                                                    Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "11192.inp"
#define fo "11192.out"
/**/
using namespace std;
/**/
char s[10000];
int n;
/**/
void dao(char s1[],int len)
{
    int i;
    for(i=len;i>=0;i--)
        printf("%c",s1[i]);
}
/**/
void solve()
{
    char temp[1000];
    int i;
    int l,dem,moc;
    dem = 0;
    l = strlen(s);
    moc = l / n;
    for(i=0;i<l;i++)
    {
        temp[dem] = s[i];
        dem++;    
        if(dem == moc)
        {
            dao(temp,dem-1);
            dem = 0;
        }
    }
    if(dem != 0)
        dao(temp,dem-1);
    printf("\n");
}
/**/
void input()
{
    while(true)
    {
        scanf("%d",&n);
        if(!n)
            break;
        scanf("%s",&s);
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
