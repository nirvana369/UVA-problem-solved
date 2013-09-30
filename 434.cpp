/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
//#include <queue>
//#include <vector>
//#include <map>

#define fi "434.inp"
#define fo "434.out"
/**/
using namespace std;
/**/
int a[10],b[10];
int n;
/**/
void solve()
{
    int i,j;
    int minb,maxb;
    int da,db;
    
    minb = maxb = 0;
    // min block
    for(i=1;i<=9;i++)
    {
        da = db = 0; // dem so khoi chung kich thuoc i
        for(j=0;j<n;j++)
            if(i == a[j])
                da++;
        for(j=0;j<n;j++)
            if(i == b[j])
                db++;
        da = da > db ? da : db;
        minb += da * i;
    }
    
    // maxblock
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            maxb += a[i] > b[j] ? b[j] : a[i];
    //if(!minb)
      //  minb = maxb;
        
    printf("Matty needs at least %d blocks, and can add at most %d extra blocks.\n",minb,maxb-minb);
}
/**/
void input()
{
    int i;
    int ntest;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]); // mat truoc
        for(i=0;i<n;i++)
            scanf("%d",&b[i]); // mat ben
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
