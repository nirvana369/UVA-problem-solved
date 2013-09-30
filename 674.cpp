/*
                                                        Hoang Linh
                                                
                                               Problem: COIN CHANGE - 674 (674.*)
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define fi "674.inp"
#define fo "674.out"
#define maxcent 7492
/**/
using namespace std;
/**/
long change[maxcent];
/**/
void khoitao()
{
    int i;
    for(i=0;i<maxcent;i++)
        change[i] = 0;
}
/**/
void preprocess()
{
    int coin[5];
    int i,j;
    khoitao();
    coin[0] = 1;
    coin[1] = 5;
    coin[2] = 10;
    coin[3] = 25;
    coin[4] = 50;
    
    change[0] = 1;
    
    for(i=0;i<5;i++)
        for(j=0;j<maxcent;j++)
            if(change[j] > 0)
                change[coin[i]+j] = change[coin[i]+j] + change[j];
}
/**/
void input()
{
    int coin;
    preprocess();
    scanf("%d",&coin);
    while(coin != -1)
    {
        printf("%ld\n",change[coin]);
        coin = -1;
        scanf("%d",&coin);
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
