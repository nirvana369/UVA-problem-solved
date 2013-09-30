/*
                                        Hoang Linh
                                    
                                     SUDOKU (Sudoku.*)
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define fi "1309.inp"
#define fo "1309.out"
////////////////////
using namespace std;
//////////////////////
struct toado{
                int x , y ;
                int land ;
            };
toado zero[256] ;
int maxz ;
int dhang[18][18] , dcot[18][18] , sudoku[18][18] , vung[18][18] ;
int thang[18] , tcot[18] , tvung[18];
bool find ;
///////////////////////
void output()
{
    int ihang , icot ;
    for(ihang=1;ihang<=16;ihang++)
    {
        if(ihang!=1)
            printf("\n");
        for(icot=1;icot<=16;icot++)
            if(icot != 1)
                printf(" %c",sudoku[ihang][icot]+64);
            else
                printf("%c",sudoku[ihang][icot]+64);
    }
}
/////////////////////////
int xacdinhvung(int vtx , int vty)
{
    int i , j ;
    int ihang , icot ;
    int ktvung ;
    
    ktvung = 0 ;
    for(i=0;i<16;i=i+4)
    {
        for(j=0;j<16;j=j+4)
        {
            ktvung++;
            if(vtx > i && vtx <= i+4 && vty > j && vty <= j+4)
                return ktvung;
        }
    }
}
///////////////////////
void dequy(int i)
{
    int j ;
    
    if(find)
        return;
    
    if(i == maxz)
    {
        find = true;
        output();
        return;   
    }
    
    for(j=1;j<=16;j++)
    {
        if(thang[zero[i].x] >= 0 && tcot[zero[i].y] >= 0 && tvung[zero[i].land] >= 0 && dhang[zero[i].x][j] == 0 && dcot[j][zero[i].y] == 0 && vung[zero[i].land][j] == 0)
        {
                thang[zero[i].x] -= j;
                tcot[zero[i].y] -= j;
                tvung[zero[i].land] -= j;              
                
                dhang[zero[i].x][j] = 1;
                dcot[j][zero[i].y] = 1;
                sudoku[zero[i].x][zero[i].y] = j;
                vung[zero[i].land][j] = 1;
                
                dequy(i+1);
                
                thang[zero[i].x] += j;
                tcot[zero[i].y] += j;
                tvung[zero[i].land] += j;
                
                vung[zero[i].land][j] = 0;
                dhang[zero[i].x][j] = 0;
                dcot[j][zero[i].y] = 0;
                dhang[zero[i].x][j] = 0;
        }
    }
}
////////////////////////
void khoitao()
{
    int i , j ;
    for(i=1;i<=16;i++)
    {
        for(j=1;j<=16;j++)
        {
            dhang[i][j] = 0;
            dcot[i][j] = 0;
            vung[i][j] = 0;
        }
        thang[i] = 136;
        tcot[i] = 136;
        tvung[i] = 136;
    }
    maxz = 0;
    find = false;
}
//////////////////////
void input()
{
    char s[100];
    int ntest , itest ;
    int ihang , icot ;
    bool sai;
    //scanf("%d",&ntest);
    ntest = 1;
    for(itest=0;itest<ntest;itest++)
    {
        if(itest != 0 && find)
            printf("\n\n");
        else if(itest != 0 && !find)
            printf("\n");
        khoitao();
        sai = false;
        for(ihang=1;ihang<=16;ihang++)
        {
            scanf("%s",&s);
            for(icot=1;icot<=16;icot++)
            {
                if(s[icot-1] == '-')
                    sudoku[ihang][icot] = 0;
                else
                    sudoku[ihang][icot] = s[icot-1] - 64;

                if(sudoku[ihang][icot] != 0)
                {
                    thang[ihang] -= sudoku[ihang][icot];
                    tcot[icot] -= sudoku[ihang][icot];
                    tvung[xacdinhvung(ihang,icot)] -= sudoku[ihang][icot];
                    
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
        }
        if(!sai)
            dequy(0);
        if(!find || sai)
            printf("Dien the cho nao duoc.\n");
    }
}
/////////////////////
main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    input();
}
