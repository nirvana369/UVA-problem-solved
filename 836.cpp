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

#define fi "836.inp"
#define fo "836.out"
/**/
using namespace std;
/**/
char a[50][50];
int nhang,ncot;
/**/
int capnhap(int r1,int c1,int r2,int c2,int kc)
{
    int i,j;
    int temp;
    
    temp = 0;
    for(i=r1;i<=r2;i++)
        for(j=c1;j<=c2;j++)
            if(a[i][j] == '0')
                return kc;
            else
                temp++;
    
    return (temp > kc) ? temp : kc;
}
/**/
void solve()
{
    int i,j,k,hang,cot;
    int maxsq,temp;
    bool cont_c,cont_r;
    ncot = strlen(a[0]);
    
    maxsq = 0;
    for(i=0;i<nhang;i++)
        for(j=0;j<ncot;j++)
            if(a[i][j] == '1')
            {
                maxsq = 1 < maxsq ? maxsq : 1;
                hang = i;
                cot = j;
                
                while(hang < nhang && cot < ncot)
                {
                   // printf("%d %d , %d %d - > %d \n",i,j,hang,cot,maxsq);
                    
                    cont_r = cont_c = false;
                    if(hang +1 < nhang && a[hang+1][j] == '1')
                        cont_r = true;
                    if(cot + 1 < ncot && a[i][cot+1] == '1')
                        cont_c = true;
                        
                    if(cont_r && hang + 1 < nhang)
                        hang++;
                    else
                        cont_r = false;
                        
                    if(cont_c && cot + 1 < ncot)
                        cot++;
                    else
                        cont_c = false;
                        
                    if(!cont_r && !cont_c)
                        break;
                        
                    maxsq = capnhap(i,j,hang,cot,maxsq);
                        
                }
                
            }
    printf("%d\n",maxsq);
}
/**/
void input()
{
    int ntest;
    scanf("%d",&ntest);
    gets(a[0]);
    gets(a[0]);
    while(ntest--)
    {
        nhang = 0;
        while(true)
        {
            a[nhang][0] = 0;
            gets(a[nhang]);
            if(!a[nhang][0])
                break;
            nhang++;
        }
        solve();
        if(ntest)
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
