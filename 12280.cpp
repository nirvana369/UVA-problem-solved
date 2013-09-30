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

#define fi "12280.inp"
#define fo "12280.out"
/**/
using namespace std;
/**/
char trai[8][20],phai[8][20],bang[8][20],a[10][30];
char p[9] = "........";
int dtrai,dphai,ctrai,cphai;
long wtrai,wphai;
/**/
/**/
long tinh(int value)
{
    long gt;
    gt = 0;
    while(value != 0)
    {
        if(value % 2 == 0)
            gt += 250;
        else
            gt += 500;
        value /= 2;
    }
    return gt;
}
/**/
void xuly()
{
    int i,j;
    wtrai = wphai = 0;
    dtrai = dphai = -1;
    ctrai = cphai = -1;
    for(i=0;i<7;i++)
        for(j=0;j<8;j++)
        {
            if(dtrai == -1 && a[i][j] == '/')
                dtrai = i;
            if(ctrai == -1 && a[i][j] == '_')
                ctrai = i;
            if(a[i][j] >= 'A' && a[i][j] <= 'Z')
                wtrai += tinh(a[i][j]);
        }
        
    for(i=0;i<7;i++)
        for(j=10;j<18;j++)
        {
            if(dphai == -1 && a[i][j] == '/')
                dphai = i;
            if(cphai == -1 && a[i][j] == '_')
                cphai = i;
            if(a[i][j] >= 'A' && a[i][j] <= 'Z')
                wphai += tinh(a[i][j]);
        }
}
/**/
void intrai(int id)
{
    if(id < 0 || id > 4)
        printf("%s",p);
    else
        printf("%s",trai[id]);
}
/**/
void inphai(int id)
{
    if(id < 0 || id > 4)
        printf("%s",p);
    else
        printf("%s",phai[id]);
}
/**/
void output()
{
    int i,j;
    int strai,sphai;
    strai,sphai;
    if(wtrai < wphai)
    {
        strai = 0;
        sphai = -2;
    }
    else if(wtrai > wphai)
    {
        strai = -2;
        sphai = 0;
    }
    else
    {
        strai = -1;
        sphai = -1;
    }
    for(i=0;i<7;i++)
    {
        intrai(strai);
        printf("||");
        inphai(sphai);
        strai++;
        sphai++;
        printf("\n");
    }
}
/**/
void solve()
{
    int i,j,k;
    
    if((ctrai < cphai && wtrai < wphai) || (ctrai > cphai && wtrai > wphai) || (ctrai == cphai && wtrai == wphai))
        printf("The figure is correct.\n");
    else
    {
        
        for(i=dtrai,k=0;i<=ctrai;i++,k++)
        {
            for(j=0;j<8;j++)
                trai[k][j] = a[i][j];
            trai[k][8] = 0;
        }
        
        for(i=dphai,k=0;i<=cphai;i++,k++)
        {
            for(j=10;j<18;j++)
                phai[k][j-10] = a[i][j];
            phai[k][8] = 0;
        }
        output();
    }    
}
/**/
void input()
{
    int i,id;
    int ntest;
    
    scanf("%d",&ntest);
    id = 1;
    while(ntest--)
    {
        a[0][0] = 0;
        i = 0;
        while(a[i][0] != '.')
            gets(a[i]);
        while(true)
        {
            i++;
            gets(a[i]);
            if(a[i][0] == '-')
                break;
        }
        xuly();
        printf("Case %d:\n",id++);
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
