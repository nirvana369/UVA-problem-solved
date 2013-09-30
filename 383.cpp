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

#define fi "383.inp"
#define fo "383.out"
/**/
using namespace std;
/**/
map <string, int> mmap;
int q[40],d[40],a[40][40],kc[40];
int nship;
/**/
void khoitao()
{
    int i,j;
    for(i=0;i<nship;i++)
    {
        for(j=0;j<nship;j++)
            a[i][j] = 0;
        d[i] = 0;
    }
}
/**/
void resetd(int cuoi)
{
    int i;
    for(i=0;i<=cuoi;i++)
        d[q[i]] = 0;
}
/**/
int loang(char s1[],char s2[])
{
    int i;
    int dau,cuoi;
    
    if(mmap[s1] == mmap[s2])
        return 0;
    q[0] = mmap[s1];
    d[mmap[s1]] = 1;
    kc[0] = 0;
    
    dau = -1;
    cuoi = 0;
    while(dau != cuoi)
    {
        dau++;
        for(i=0;i<nship;i++)
            if(d[i] == 0 && a[q[dau]][i] == 1)
            {
                cuoi++;
                q[cuoi] = i;
                kc[cuoi] = kc[dau] + 1;
                d[i] = 1;
                if(i == mmap[s2])
                {
                    resetd(cuoi);
                    return kc[cuoi];
                }
            }
    }
    resetd(cuoi);
    return -1;
}
/**/
void input()
{
    int nnoi,q;
    char s1[100],s2[100];
    int i,id;
    int temp,mney;
    long kq;
    int ntest;
    id = 1;
    scanf("%d",&ntest);
    printf("SHIPPING ROUTES OUTPUT\n\n");
    while(ntest--)
    {
        scanf("%d %d %d",&nship,&nnoi,&q);
        printf("DATA SET  %d\n\n",id++);
        mmap.clear();
        for(i=0;i<nship;i++)
        {
            scanf("%s",&s1);
            mmap[s1] = i;
        }
        khoitao();
        for(i=0;i<nnoi;i++)
        {
            scanf("%s %s",&s1,&s2);
            a[mmap[s1]][mmap[s2]] = 1;
            a[mmap[s2]][mmap[s1]] = 1;
        }
        for(i=0;i<q;i++)
        {
            scanf("%d %s %s",&mney,&s1,&s2);
            temp = loang(s1,s2);
            kq = temp * mney * 100;
            if(temp != -1)
                printf("$%ld\n",kq);
            else
                printf("NO SHIPMENT POSSIBLE\n");
        }
        printf("\n");
    }
    printf("END OF OUTPUT\n");
}
/**/
int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    input();
    return 0;
}
