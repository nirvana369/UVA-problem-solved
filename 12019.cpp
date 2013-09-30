/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "12019.inp"
#define fo "12019.out"
/**/
using namespace std;
/**/
int d[13][32];
char datex[9][10];
/**/
void _init()
{
    int i,j,thang,ngay;
    int m[13];
    
    for(i=1;i<13;i+=2)
    {
        m[i] = 31;
        if(i == 7)
        {
            i--;
            continue;
        }
        m[i+1] = 30;
    }
    m[2] = 28;
    
    j = 2;
    d[4][4] = 2;
    thang = 4;
    ngay = 4;
    
    while(thang)
    {
        ngay--;
        j--;
        if(!ngay)
        {
            thang--;
            if(thang)
                ngay = m[thang];
        }
        if(j == 1)
            j = 8;
        if(!thang && !ngay)
            break;
        d[thang][ngay] = j;
    }
    
    thang = 4;
    ngay = 4;
    j = 2;
    
    while(thang != 13)
    {
        ngay++;
        j++;
        if(ngay > m[thang])
        {
            thang++;
            ngay = 1;
        }
        if(j == 9)
            j = 2;
        if(thang == 13)
            break;
        d[thang][ngay] = j;
    }
    
    strcpy(datex[2],"Monday");
    strcpy(datex[3],"Tuesday");
    strcpy(datex[4],"Wednesday");
    strcpy(datex[5],"Thursday");
    strcpy(datex[6],"Friday");
    strcpy(datex[7],"Saturday");
    strcpy(datex[8],"Sunday");
}
/**/
void output(int flg)
{
    if(flg == 2)
        
    printf("\n");
}
/**/
void input()
{
    int ntest;
    int mon,day;

    _init();
    scanf("%d",&ntest);
    while(ntest--)       
    {
        scanf("%d %d",&mon,&day);
        printf("%s\n",datex[d[mon][day]]);
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
