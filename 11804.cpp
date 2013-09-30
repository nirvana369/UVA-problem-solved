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

#define fi "11804.inp"
#define fo "11804.out"
/**/
using namespace std;
/**/
struct football{
                    char name[30];
                    int attack,defend;
                };
football p[11];
/**/
void swapfb(int i,int j)
{
    football temp;
    
    temp = p[i];
    p[i] = p[j];
    p[j] = temp;
}
/**/
void sortlexi(int dau,int cuoi)
{
    int i,j;
    for(i=dau;i<cuoi;i++)
        for(j=i+1;j<=cuoi;j++)
            if(strcmp(p[i].name,p[j].name) > 0)
                swapfb(i,j);
}
void sapxep()
{
    int i,j;
    football temp;
    int at1,at2,df1,df2;
    
    at1 = at2 = df1 = df2 = 0;
    for(i=0;i<9;i++)
    {
        for(j=i+1;j<10;j++)
            if(p[i].attack < p[j].attack)
                swapfb(i,j);
            else if(p[i].attack == p[j].attack)
            {
                if(p[i].defend > p[j].defend)
                    swapfb(i,j);
                else if(p[i].defend == p[j].defend)
                    if(strcmp(p[i].name,p[j].name) > 0)
                        swapfb(i,j);
            }
        if(i < 5)
            at1 += p[i].attack;
        else
            at2 += p[i].attack;
    }
    at2 += p[9].attack;
    
    if(at1 == at2)     
    {
        for(i=0;i<9;i++)
        {
            for(j=i+1;j<10;j++)
                if(p[i].defend > p[j].defend)
                    swapfb(i,j);
                else if(p[i].defend == p[j].defend)
                    if(strcmp(p[i].name,p[j].name) > 0)
                        swapfb(i,j);
                    
            if(i < 5)
                df1 += p[i].defend;
            else
                df2 += p[i].defend;
        }
        df2 += p[9].defend;
        
        if(df1 == df2)
        {
            sortlexi(0,9);
            return;
        }
    }
    
    sortlexi(0,4);
    sortlexi(5,9);
}
/**/
void output()
{
    int i;
    for(i=0;i<5;i++)
        if(!i)
            printf("(%s",p[i].name);
        else
            printf(", %s",p[i].name);
    printf(")\n");
    for(i=5;i<10;i++)
        if(!(i-5))
            printf("(%s",p[i].name);
        else
            printf(", %s",p[i].name);
    printf(")\n");
}
/**/
void input()
{
    int ntest;
    int id,i;
    scanf("%d",&ntest);
    id = 1;
    while(ntest--)
    {
        for(i=0;i<10;i++)
            scanf("%s %d %d",&p[i].name,&p[i].attack,&p[i].defend);
        sapxep();
        printf("Case %d:\n",id++);
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
