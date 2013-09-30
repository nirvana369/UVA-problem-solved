/*
                                                    Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "750.inp"
#define fo "750.out"
/**/
using namespace std;
/**/
int row[10],ngang[10],doc[10],cheo1[100],cheo2[100];
int hang,cot,sln;
/**/
void khoitao()
{
    int i,j;
    for(i=0;i<=8;i++)
    {
        ngang[i] = 0;
        doc[i] = 0;
    }
    for(i=0;i<=16;i++)
    {
        cheo1[i] = 0;
        cheo2[i] = 0;
    }
}
/**/
void solve(int id)
{
    int i;
    if(id == 9)
    {
        printf("%2d     ",sln);
        for(i=1;i<9;i++)
            printf(" %d",row[i]);
        printf("\n");
        sln++;
        return;
    }
    if(doc[id] == 1)
    {
        solve(id+1);
        return;
    }
    for(i=1;i<9;i++)
    {
        if(ngang[i] == 0 && cheo1[id + i] == 0 && cheo2[i-id+7] == 0)
        {
            ngang[i] = 1;
            cheo1[id + i] = 1;
            cheo2[i-id+7] = 1;
            
            row[id] = i;
            
            solve(id+1);
            
            ngang[i] = 0;
            cheo1[id + i] = 0;
            cheo2[i-id+7] = 0;
        }
    }
}
/**/
void input()
{
    int ntest;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d %d",&hang,&cot);
        khoitao();
        ngang[hang] = 1;
        doc[cot] = 1;
        row[cot] = hang;
        cheo1[hang+cot] = 1;
        cheo2[hang-cot+7] = 1;
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        sln = 1;
        solve(1);
        if(ntest != 0)
            printf("\n");
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
