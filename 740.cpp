/*
                                                                Hoang Linh
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define fi "740.inp"
#define fo "740.out"

/**/
using namespace std;
/**/
char up[10000],down[10000],u[10000],d[10000];
/**/
void xuly()
{
    int i;
    int l;
    l = strlen(down);
    for(i=0;i<l;i++)
        u[i] = up[i];
    l = strlen(down);
    for(i=0;i<l;i++)
        d[i] = down[i];
}
/**/
int getbac(int bac)
{
    int i;
    int value;
    value = 1;
    for(i=1;i<=bac;i++)
        value *= 2;
    return value;
}
/**/
int getnum(char s[],int l)
{
    int i;
    int bac,value;
    bac = l-1;
    value = 0;
    for(i=0;i<l;i++,bac--)
        if(s[i] != '0')
            value += getbac(bac);
    return value;
}
/**/
void solve(char s[])
{
    int i;
    char temp[1000];
    int l,dem,num;
    int flag;
    l = strlen(s);
    dem = 0;
    flag = 1;
    for(i=0;i<=l;i++)
    {
        if(i!= 0 && i % 5 ==  0)
        {
            temp[dem] = 0;
            if(strcmp(temp,"11011") == 0)
                flag = 1;
            else if(strcmp(temp,"11111") == 0)
                flag = 0;
            else
            {
                num = getnum(temp,dem);
                if(flag == 0)
                    printf("%c",u[num]);
                else
                    printf("%c",d[num]);
            }
            dem = 0;
        }
        temp[dem++] = s[i];
    }
}
/**/
void input()
{
    char temp[10000];
    gets(down);
    gets(up);
    xuly();
    while(!feof(stdin))
    {
        gets(temp);
        if(feof(stdin))
            break;
        solve(temp);
        printf("\n");
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
