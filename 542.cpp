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

#define fi "542.inp"
#define fo "542.out"
/**/
using namespace std;
/**/
struct name{
                char quocgia[15];  
           };
name ten[17];
float data[17][17],tilebk[17],tileck[17],tilewin[17];
/**/
float tinhbk(int a,int b,int c,int d)
{
    float kq;
    kq=data[a][b]*(data[a][c]*data[c][d]+data[a][d]*data[d][c]);
    return kq;
}
/**/
float tinh(int doi1,int doi2,float tile[])
{
    float kq;
    kq=tile[doi2]*data[doi1][doi2];
    return kq;
}
/**/
void solve()
{
    int i,j;
    float temp;
    //tinh ban ket
    for(i=1;i<=16;i=i+4)
    {
        tilebk[i]=tinhbk(i,i+1,i+2,i+3);
        tilebk[i+1]=tinhbk(i+1,i,i+2,i+3);
        tilebk[i+2]=tinhbk(i+2,i+3,i,i+1);
        tilebk[i+3]=tinhbk(i+3,i+2,i,i+1);
    }
    // tinh chung ket
    for(i=1;i<=16;i++)
    {
        if(i<5)
        {
            temp=0;
            for(j=5;j<=8;j++)
                temp=temp+tinh(i,j,tilebk);
            tileck[i]=tilebk[i]*temp;
        }
        else if(i<9)
        {   
            temp=0;
            for(j=1;j<=4;j++)
                temp=temp+tinh(i,j,tilebk);
            tileck[i]=tilebk[i]*temp;
        }
        else if(i<13)
        {
            temp=0;
            for(j=13;j<=16;j++)
                temp=temp+tinh(i,j,tilebk);
            tileck[i]=tilebk[i]*temp;
        }
        else
        {
            temp=0;
            for(j=9;j<=12;j++)
                temp=temp+tinh(i,j,tilebk);
            tileck[i]=tilebk[i]*temp;
        }
    }
    //tinh doi vo dich
    for(i=1;i<=16;i++)
    {
        if(i<9)
        {
            temp=0;
            for(j=9;j<=16;j++)
                temp=temp+tinh(i,j,tileck);
            tilewin[i]=tileck[i]*temp*100;
        }
        else
        {
            temp=0;
            for(j=1;j<=8;j++)
                temp=temp+tinh(i,j,tileck);
            tilewin[i]=tileck[i]*temp*100;
        }
    }
}
/**/
void output()
{
    int i;
    for(i=1;i<=16;i++)
        printf("%-11sp=%0.2f%%\n",ten[i].quocgia,tilewin[i]);
}
/**/
void input()
{
    int i,j,temp;
    for(i=1;i<=16;i++)
        scanf("%s",&ten[i].quocgia);
    for(i=1;i<=16;i++)
        for(j=1;j<=16;j++)
        {
            scanf("%d",&temp);
            if(temp!=0)
                data[i][j]=(float)temp/100;
            else
                data[i][j]=0;
        }
    solve();
    output();
}
/**/
int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    input();   
    return 0;
}
