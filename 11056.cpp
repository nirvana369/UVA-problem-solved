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

#define fi "11056.inp"
#define fo "11056.out"
/**/
using namespace std;
/**/
struct f1{
            char name[30];
            int m,s,ms;
         };
f1 p[110];
map <string, string> mmap;
int n;
/**/
void xuly(int id,char s[])
{
    int i,j;
    int gio,phut,giay;
    char temp[1000],temp1[1000];
    int l,dem;

    l = strlen(s);
    i = 0;
    dem = 0;
    while(i != l)
    {
        if(s[i] == ':')
            break;
        temp1[dem++] = s[i];
        i++;
    }
    temp1[dem] = 0;
    sscanf(temp1,"%s",&temp);
    
    dem = 0;
    j = 0;
    while(i < l)
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            temp1[dem++] = s[i];
        }
        else if(dem != 0)
        {
            temp1[dem] = 0;
            if(j == 0)
            {
                sscanf(temp1,"%d",&gio);
                j++;
            }
            else if(j == 1)
            {
                sscanf(temp1,"%d",&phut);
                j++;
            }
            else
            {
                sscanf(temp1,"%d",&giay);
                break;
            }
            dem = 0;    
        }
        i++;    
    }
    
    l = strlen(temp);
    for(i=0;i<l;i++)
    {
        if(temp[i] >= 'A' && temp[i] <= 'Z')
            temp1[i] = temp[i] + 32;
        else
            temp1[i] = temp[i];
        p[id].name[i] = temp[i];
    }
    temp1[l] = 0;
    p[id].name[l] = 0;
    p[id].m = gio;
    p[id].s = phut;
    p[id].ms = giay;
    mmap[temp] = temp1;
    
}
/**/
void swapp(int i,int j)
{
    f1 temp;
    temp = p[i];
    p[i] = p[j];
    p[j] = temp;    
}
/**/
void sapxep()
{
    int i,j;
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if(p[i].m > p[j].m)
                swapp(i,j);
            else if(p[i].m == p[j].m)
            {
                if(p[i].s > p[j].s)
                    swapp(i,j);                    
                else if(p[i].s == p[j].s)
                {
                    if(p[i].ms > p[j].ms)
                        swapp(i,j);                        
                    else if(p[i].ms == p[j].ms)
                    {
                        if(mmap[p[i].name] > mmap[p[j].name])
                            swapp(i,j);
                    }
                }
            }
}
/**/
void output()
{
    int id,i;
    id = 1;
    for(i=0;i<n;i++)
    {
        if(i % 2 == 0)
            printf("Row %d\n",id++);
        printf("%s\n",p[i].name);
    }
    printf("\n");
}
/**/
void input()
{
    int i;
    char temp[1000];
    while(true)
    {
        n = 0;
        scanf("%d",&n);
        if(!n)
            break;
        mmap.clear();
        gets(temp);
        for(i=0;i<n;i++)
        {
            gets(temp);
            xuly(i,temp);
        }
        sapxep();
        output();
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
