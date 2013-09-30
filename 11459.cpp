/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "11459.inp"
#define fo "11459.out"
/**/
using namespace std;
/**/
int a[110],player[1000010];
long pl,sl,die;
/**/
void khoitao()
{
    long i;
    for(i=1;i<=100;i++)
        a[i] = i;
    for(i=1;i<=pl;i++)
        player[i] = 1;
}
/**/
void output()
{
    long i;
    for(i=1;i<=pl;i++)
        printf("Position of player %d is %d.\n",i,player[i]);
}
/**/
void input()
{
    long i,j;
    int x,y;
    int ntest;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%ld %ld %ld",&pl,&sl,&die);
        khoitao();
        for(i=0;i<sl;i++)
        {
            scanf("%d %d",&x,&y);
            a[x] = y;
        }
        
        i = 1;
        while(die--)
        {
            scanf("%d",&x);
    
            player[i] += x;
            
            if(player[i] >= 100)
            {
                player[i] = 100;
                break;
            }
            else
            {
                player[i] = a[player[i]];
                if(player[i] == 100)
                    break;
            }
            i++;
            if(i > pl)
                i = 1;
            
        }
        
        if(die > 0)
            while(die--)
                scanf("%d",&x);
            
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
