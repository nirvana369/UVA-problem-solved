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

#define fi "1266.inp"
#define fo "1266.out"
/**/
using namespace std;
/**/
int tong[16],row[16],col[16],a[16][16],d[250];
int diag1,diag2;
int n;
bool tim;
/**/
void precal()
{
    int i,j;
    int temp;
    for(i=3;i<=15;i+=2)
        tong[i] = i*i;
    i = 3;
    temp = 0;
    for(j=1;j<=15*15;j++)
    {
        temp += j;
        if(j == tong[i])
        {
            tong[i] = temp / i;
            i += 2;
        }
    }
}
/**/
void khoitao()
{
    int i;
    diag1 = diag2 = tong[n];
    for(i=1;i<=n;i++)
        row[i] = col[i] = tong[n];
    for(i=1;i<=n*n;i++)
        d[i] = 0;
    tim = false;
}
/**/
bool kiemtra()
{
    int i;
    if(diag1 != 0 || diag2 != 0)
        return false;
    for(i=1;i<=n;i++)
        if(row[i] != 0 || col[i] != 0)
            return false;
    return true;
}
/**/
void filla(int hang,int cot,int id)
{
    int i,j;
    if(id == n*n)
    {
        if(kiemtra())
        {
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=n;j++)
                    printf("%d ",a[i][j]);
                printf("\n");   
            }
            tim = true;
        }
        return;
    }
    if(cot > n)
    {
        cot = 1;
        hang++;
    }

    for(i=1;i<=n*n;i++)
    {
        if(d[i] == 0)
        {
            if(hang-1 == n-cot)
                diag2 -= i;
            if(hang == cot)
                diag1 -= i;
            row[hang] -= i;
            col[cot] -= i;
            d[i] = 1;

            if(diag1 >= 0 && diag2 >= 0 && row[hang] >= 0 && col[cot] >= 0)
            {
                a[hang][cot] = i;
                filla(hang,cot+1,id+1);
            }

            d[i] = 0;
            col[cot] += i;
            row[hang] += i;
            if(hang-1 == n-cot)
                diag2 +=i;
            if(hang == cot)
                diag1 +=i;
        }
        if(tim)
            return;
    }
}
/**/
void input()
{
    precal();
    while(scanf("%d",&n) == 1)
    {
        khoitao();
        filla(1,1,0);
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
