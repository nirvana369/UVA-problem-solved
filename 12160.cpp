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

#define fi "12160.inp"
#define fo "12160.out"
/**/
using namespace std;
/**/
/**/
int d[10001],kc[10001],key[20],q[10001];
int lock,ulock,n;
/**/
void resetd(int cuoi)
{
    int i;
    for(i=0;i<=cuoi;i++)
        d[q[i]] = 0;
}
/**/
int loang()
{
    int dau,cuoi;
    int i,j;
    int temp;
    
    if(lock == ulock)
        return 0;
    dau = -1;
    cuoi = 0;
    q[0] = lock;
    d[lock] = 1;
    kc[0] = 0;
    
    while(dau != cuoi)
    {
        dau++;
        for(i=0;i<n;i++)
        {
            temp = q[dau] + key[i];
            if(temp > 9999)
                temp = temp % 10000;
            if(temp >= 0 && temp < 10000)
            {
                if(d[temp] == 0)
                {
                    cuoi++;
                    q[cuoi] = temp;
                    kc[cuoi] = kc[dau]+1;
                    d[temp] = 1;
                    if(temp == ulock)
                    {
                        resetd(cuoi);
                        return kc[cuoi];
                    }
                }
            }
        }
    }
    resetd(cuoi);
    return -1;
}
/**/
void khoitao()
{
    int i;
    for(i=0;i<10000;i++)
        d[i] = 0;
}
/**/
void input()
{
    int i,id;
    int kq;
    
    khoitao();
    id = 1;
    while(true)
    {
        scanf("%d %d %d",&lock,&ulock,&n);
        if(!lock && !ulock && !n)
            break;
        for(i=0;i<n;i++)
            scanf("%d",&key[i]);
        printf("Case %d: ",id++);
        kq = loang();
        if(kq == -1)
            printf("Permanently Locked\n");
        else
            printf("%d\n",kq);
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
