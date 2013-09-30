/*
                                                            Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "124.inp"
#define fo "124.out"
/**/
using namespace std;
/**/
int d[200][200],dd[500];
char luu[500],a[500];
int maxa;
/**/
void sapxep()
{
    int i,j;
    char temp;
    for(i=0;i<maxa-1;i++)
        for(j=i+1;j<maxa;j++)
            if(a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
}
/**/
void khoitao()
{
    int i,j;
    for(i='a';i<='z';i++)
        for(j='a';j<='z';j++)
            d[i][j] = 0;
    maxa = 0;
}
/**/
void xuly(char s[])
{
    int i;
    int l;

    khoitao();
    l = strlen(s);
    for(i=0;i<l;i++)
        if(s[i] >= 'a' && s[i] <= 'z')
        {
            a[maxa] = s[i];
            maxa++;
        }
    for(i=0;i<maxa;i++)
        dd[i] = 0;
    sapxep();
}
/**/
void danhdau(char s[])
{
    int i;
    int l;
    char x,y;
    
    l = strlen(s);
    x = 0;
    y = 0;
    for(i=0;i<l;i++)
    {
        if(s[i] >= 'a' && s[i] <= 'z')
        {
            if(x == 0)
                x = s[i];
            else
            {
                y = s[i];
                d[y][x] = 1;
                x = y = 0;
            }
        }
    }
}
/**/
void output(int id)
{
    int i,j;
    bool ok;
    if(id == maxa)
    {
        for(i=0;i<id;i++)
            printf("%c",luu[i]);
        printf("\n");
        return;
    }
    for(i=0;i<maxa;i++)
    {
        if(dd[i] == 0)
        {
            ok = true;
            for(j=id-1;j>=0;j--)
            {
                if(d[luu[j]][a[i]] == 1)
                {
                    ok = false;
                    break;
                }
            }
            if(ok)
            {
                luu[id] = a[i];
                dd[i] = 1;
                
                output(id+1);
                
                dd[i] = 0;
            }
        }
    }
}
/**/
void input()
{
    int id;
    char temp[10000];
    id = 0;
    while(true)
    {
        temp[0] = 0;
        gets(temp);
        if(temp[0] == 0)
            break;
        if(id != 0)
            printf("\n");
        xuly(temp);
        gets(temp);
        danhdau(temp);
        output(0);
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
