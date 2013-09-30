/*
                                                    Hoang Linh
                                                    
                                            Proble: BOX OF BRICKS - 591 (591.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "591.inp"
#define fo "591.out"
/**/
using namespace std;
/**/
int n,ah;
int h[100];
/**/
int solve()
{
    int i;
    int move;
    move = 0;
    for(i=0;i<n;i++)
        if(h[i] > ah)
            move = move + (h[i] - ah);
    return move;
}
/**/
void input()
{
    int i;
    int id,kq;
    id = 1;
    while(true)
    {
        scanf("%d",&n);
        if(!n)
            break;
        ah = 0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&h[i]);
            ah = ah + h[i];
        }
        ah = ah / n;
        kq = solve();
        printf("Set #%d\nThe minimum number of moves is %d.\n\n",id,kq);
        id++;
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
