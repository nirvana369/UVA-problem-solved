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

#define fi "12602.inp"
#define fo "12602.out"
/**/
using namespace std;
/**/
int mu[3] = {676,26,1};
/**/
void input()
{
    int i,j;
    int ntest;
    int val,val1;
    char s[10];
    
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%s",&s);
        val = 0;
        for(i=0;i<3;i++)
            val += (s[i] - 'A') * mu[i];
            
        for(i=0,j=4;j<8;i++,j++)
            s[i] = s[j];
        s[4] = 0;
        
        sscanf(s,"%d",&val1);
        val = val1 > val ? (val1 - val) : (val-val1);
        if(val <= 100)
            printf("nice\n");
        else
            printf("not nice\n");
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
