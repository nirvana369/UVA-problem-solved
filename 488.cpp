/*
                                                    Hoang Linh
                                                    
                                        Problem: TRIANGLE WAVE - 488 (488.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define fi "wave.inp"
#define fo "wave.out"
/**/
using namespace std;
/**/
int h,f;
/**/
void vetg(int docao)
{
    int i,j;
    for(i=1;i<docao;i++)
    {
        for(j=1;j<=i;j++)
        {
            printf("%d",i);
        }
        printf("\n");
    }
    
    for(i=1;i<=docao;i++)
        printf("%d",docao);
    printf("\n");
    
    for(i=docao-1;i>=1;i--)
    {
        for(j=1;j<=i;j++)
        {
            printf("%d",i);
        }
        printf("\n");
    }
}
/**/
void solve()
{
    int i;
    for(i=0;i<f;i++)
    {
        if(i != 0)
            printf("\n");
        vetg(h);
    }
}
/**/
void input()
{
    int ntest;
    int itest;
    scanf("%d",&ntest);
    for(itest=0;itest<ntest;itest++)
    {
        if(itest != 0)
            printf("\n");
        scanf("%d %d",&h,&f);
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
