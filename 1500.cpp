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
#include <vector>

#define fi "1500.inp"
#define fo "1500.out"
/**/
using namespace std;
/**/
void input()
{
    int i;
    long tong;
    int temp,n;
    bool alice;
    int ntest,id;
    
    id = 1;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d",&n);
        tong = 0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&temp);
            tong += temp;
        }
        if((n-1) % 2 != 0)
            alice = false;
        else
            alice = true;
        //tong -= (n-1);
        printf("Case #%d: ",id++);
        if(alice)
        {
            if(tong % 2 == 0)
                printf("Alice");
            else
                printf("Bob");
        }
        else
        {
            if(tong % 2 != 0)
                printf("Bob");
            else
                printf("Alice");
        }
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
