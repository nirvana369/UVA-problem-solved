/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "159.inp"
#define fo "159.out"
#define n 41
/**/
using namespace std;
/**/
char a[60][60];
bool match;
int hx,lx;
/**/
void khoitao()
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            a[i][j] = ' ';
    
    hx = -1;
    lx = n;
}
/**/
bool xh(char kt,char s[],int hang,int cot)
{
    int i,j;
    int x;
    
    i = 0;
    while(s[i])
    {
        if(s[i] == kt)
        {
            j = i-1;
            x = hang - 1;
            while(j >= 0)
            {
                a[x][cot] = s[j];
                x--;
                j--;
            }
            if(x < lx)       
                lx = x;
            j = i+1;
            x = hang + 1;
            while(s[j])
            {
                a[x][cot] = s[j];
                x++;
                j++;
            }
            if(x > hx)
                hx = x;
            return true;
        }
        i++;
    }
    return false;
}
/**/
void output(int cot)
{
    int i,j,k;
    if(match)
    {
        lx++;
        hx--;
        for(i=lx;i<=hx;i++)
        {
            for(j=cot;j>=0;j--)
                if(a[i][j] != ' ')
                    break;
            for(k=0;k<=j;k++)
                printf("%c",a[i][k]);
            printf("\n");
        }
    }
    else
        printf("Unable to make two crosses\n");
}
/**/
void input()
{
    int i;
    int x,y,id;
    char s[30],s1[30];
    
    id = 0;
    while(true)
    {
        scanf("%s",&s);
        if(s[0] == '#')
            break;

        if(id++)
            printf("\n");
            
        khoitao();
        scanf("%s",&s1);
        i = y = 0;
        x = 20;
        match = false;
        while(s[i])
        {
            if(!match)
                match = xh(s[i],s1,x,y);
            a[x][y] = s[i];
            y++;
            i++;
        }
        if(!match)
            scanf("%s %s",&s,&s1);
        else
        {
            scanf("%s %s",&s,&s1);
            match = false;
            y += 3;
            i = 0;
            while(s[i])
            {
                if(!match)
                    match = xh(s[i],s1,x,y);
                a[x][y] = s[i];
                y++;
                i++;
            }
        }
        output(y-1);
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
