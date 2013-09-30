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

#define fi "10957.inp"
#define fo "10957.out"
/**/
using namespace std;
/**/
struct toado{
                int x , y ;
                int land ;
            };
toado zero[82] ;
int maxz ;
int dhang[10][10] , dcot[10][10] , sudoku[10][10] , vung[10][10] ;
int socach;
/**/
void output()
{
    int ihang , icot ;
    for(ihang=1;ihang<=9;ihang++)
    {
        if(ihang!=1)
            printf("\n");
        for(icot=1;icot<=9;icot++)
            if(icot != 1)
                printf(" %d",sudoku[ihang][icot]);
            else
                printf("%d",sudoku[ihang][icot]);
    }
}
/**/
int xacdinhvung(int vtx , int vty)
{
    int i , j ;
    int ihang , icot ;
    int ktvung ;
    
    ktvung = 0 ;
    for(i=0;i<9;i=i+3)
    {
        for(j=0;j<9;j=j+3)
        {
            ktvung++;
            if(vtx > i && vtx <= i+3 && vty > j && vty <= j+3)
                return ktvung;
        }
    }
}
/**/
void dequy(int i)
{
    int j ;
    
    
    if(i == maxz)
    {
        socach++;
        return;   
    }
    
    for(j=1;j<=9;j++)
    {
        if(dhang[zero[i].x][j] == 0 && dcot[j][zero[i].y] == 0 && vung[zero[i].land][j] == 0)
        {
                dhang[zero[i].x][j] = 1;
                dcot[j][zero[i].y] = 1;
                sudoku[zero[i].x][zero[i].y] = j;
                vung[zero[i].land][j] = 1;
                
                dequy(i+1);
                
                if(socach > 1)                
                    return;
                    
                vung[zero[i].land][j] = 0;
                dhang[zero[i].x][j] = 0;
                dcot[j][zero[i].y] = 0;
                dhang[zero[i].x][j] = 0;
        }
    }
}
/**/
void khoitao()
{
    int i , j ;
    for(i=1;i<=9;i++)
        for(j=1;j<=9;j++)
        {
            dhang[i][j] = 0;
            dcot[i][j] = 0;
            vung[i][j] = 0;
        }
    maxz = 0;
}
/**/
void input()
{
    int ihang , icot ;
    int id;
    bool sai;
    id = 1;
    while(true)
    {
        khoitao();
        sai = false;
        sudoku[1][1] = -1;
        for(ihang=1;ihang<=9;ihang++)
            for(icot=1;icot<=9;icot++)
            {
                scanf("%d",&sudoku[ihang][icot]);
                if(sudoku[1][1] == -1)
                    return;
                if(sudoku[ihang][icot] != 0)
                {
                    dhang[ihang][sudoku[ihang][icot]]++;
                    dcot[sudoku[ihang][icot]][icot]++;
                    vung[xacdinhvung(ihang,icot)][sudoku[ihang][icot]]++;
                    
                    if(dhang[ihang][sudoku[ihang][icot]] == 2 || dcot[sudoku[ihang][icot]][icot] == 2 || vung[xacdinhvung(ihang,icot)][sudoku[ihang][icot]] == 2)
                        sai = true;
                }
                else
                {
                    zero[maxz].x = ihang;
                    zero[maxz].y = icot;
                    zero[maxz].land = xacdinhvung(ihang,icot);
                    maxz++;
                }
            }
        printf("Case %d: ",id++);
        if(sai)
            printf("Illegal.\n");
        else
        {
            socach = 0;
            dequy(0);
            if(!socach)
                printf("Impossible.\n");
            else if(!(socach-1))
                printf("Unique.\n");
            else
                printf("Ambiguous.\n");
        }
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
