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

#define fi "10880.inp"
#define fo "10880.out"
/**/
using namespace std;
/**/
long eat[1000];
long c,r;
/**/
void sapxep(int maxe)
{
    int i,j;
    long temp;
    for(i=0;i<maxe;i++)
    {
        for(j=i+1;j<maxe;j++)
            if(eat[i] > eat[j])
            {
                temp = eat[i];
                eat[i] = eat[j];
                eat[j] = temp;
            }
        printf(" %ld",eat[i]);
    }
}
/**/
void input()
{
    long i;
    int j;
    long temp,val;
    int ntest,id;
    scanf("%d",&ntest);
    id = 1;
    while(ntest--)
    {
        scanf("%ld %ld",&c,&r);
        printf("Case #%d:",id++);
        if(c == r)
            printf(" 0");
        else if(c - r > r)
        {
            val = c-r;
            temp = (int)sqrt(val);
            j = 0;
            for(i=1;i<=temp;i++)
                if(val % i == 0)
                {
                    if(i > r)
                        eat[j++] = i;
                    if(val / i > r && i * i != val)
                        eat[j++] = val / i;
                }
            sapxep(j);
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
