/*
                                            Hoang Linh
                                        
                                    Problem: POLYNOMIAL SHOWDOWN - 392 (392.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "392.inp"
#define fo "392.out"
/**/
using namespace std;
/**/
void xuly(char s[])
{
    int i,j;
    char temp[1000];
    int a[200];
    int l,dem,bac;
    bool first;
    
    l = strlen(s);
    s[l] = ' ';
    dem = 0;
    j = 0;
    for(i=0;i<=l;i++)
    {
        if(s[i] == ' ' && dem != 0)
        {
            temp[dem] = 0;
            sscanf(temp,"%d",&a[j]);
            j++;
            dem = 0;
        }
        if(s[i] != ' ')
        {
            temp[dem] = s[i];
            dem++;
        }
    }
    bac = j-1;
    first = true;
    for(i=0;i<j;i++,bac--)    
    {
        if(a[i] != 0)
        {
            if(!first)
            {
                if(a[i] > 0)
                    printf(" + ");
                else
                {
                    printf(" - ");
                    a[i] = a[i] * -1;
                }
            }
            else if(first)
            {
                if(a[i] < 0)
                {
                    printf("-");
                    a[i] = a[i] * -1;
                }
            }
            if(a[i] != 1 && bac != 0)
                printf("%d",a[i]);
            if(bac != 0)    
                printf("x",bac);
            else if(bac == 0)
                printf("%d",a[i]);
            if(bac > 1)
                printf("^%d",bac);
            first = false;
        }
    }
    if(first)
        printf("0");
    printf("\n");
}
/**/
void input()
{
    char temp[10000];
    while(true)
    {
        temp[0] = 0;
        gets(temp);
        if(temp[0] == 0)
            break;
        xuly(temp);
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
