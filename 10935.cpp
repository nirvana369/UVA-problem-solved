/*
                                                        Hoang Linh
                                                        
                                    Problem: THROWING CARDS AWAY I - 10935 (10935.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10935.inp"
#define fo "10935.out"
/**/
using namespace std;
/**/
int n;
int d[60];
/**/
void khoitao()
{
    int i;
    for(i=1;i<=n;i++)   
        d[i] = 0;
}
/**/
void solve()
{
    int i;
    int flag,temp;
    khoitao();
    flag = 0;
    temp = n;
    i = 1;
    printf("Discarded cards: ");
    while(true)
    {
        if(flag == 1 && d[i] == 0)
            flag = 0;
        else if(flag == 0 && d[i] == 0)
        {
            d[i] = 1;
            printf("%d",i);
            temp--;
            if(temp != 1)
                printf(", ");
            flag = 1;
        }
        if(temp == 1)
            break;
        i++;
        if(i > n)
            i = 2;
    }
    printf("\nRemaining card: ");
    for(i=1;i<=n;i++)
        if(d[i] == 0)
        {
            printf("%d\n",i);
            return;
        }
}
/**/
void input()
{
    while(true)
    {
        scanf("%d",&n);
        if(!n)
            break;
        if(n == 1)
            printf("Discarded cards:\nRemaining card: 1\n");
        else
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
