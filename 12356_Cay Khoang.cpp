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

#define fi "12356.inp"
#define fo "12356.out"
/**/
using namespace std;
/**/
struct khoang{
                long trai,phai;
                long conlai;
            };
khoang a[300100];
long n;
long l,r,id,leftmost,rightmost;
/**/
void ctree(long id, long dau, long cuoi)
{
    long mid;
    if(dau == cuoi)
    {
        a[id].trai = a[id].phai = dau;
        a[id].conlai = 1;
        return;
    }
    mid = (dau + cuoi) / 2;
    ctree(id*2,dau,mid);
    ctree(id*2+1,mid+1,cuoi);
    a[id].trai = dau;
    a[id].phai = cuoi;
    a[id].conlai = a[id*2].conlai + a[id*2+1].conlai;
}
/**/
long danhdau(long id,long left,long right)
{
    long mid,temp;
    if(a[id].trai == a[id].phai)
    {
        a[id].conlai = 0;
        return a[id].conlai;
    }
    mid = (a[id].trai + a[id].phai) / 2;
    temp = a[id].conlai;
    if(right <= mid)
        a[id].conlai -= danhdau(id*2,left,right);
    else if(left > mid)
        a[id].conlai -= danhdau(id*2+1,left,right);
    else
    {
        a[id].conlai -= danhdau(id*2,left,mid);
        a[id].conlai -= danhdau(id*2+1,mid+1,right);
    }
    return temp - a[id].conlai;
}
/**/
void timtrai(long id,long left,long right)
{
    long mid;
    
    if(a[id].trai == a[id].phai && a[id].conlai != 0)
    {
        leftmost = a[id].trai;
        return;
    }
    
    mid = (a[id].trai + a[id].phai) / 2;
    if(right <= mid)
    {
        if(a[id*2].conlai != 0)
            timtrai(id*2,left,right);
    }
    else if(left > mid)
    {
        if(a[id*2+1].conlai != 0)
            timtrai(id*2+1,left,right);
    }
    else
    {
        if(a[id*2+1].conlai != 0)
            timtrai(id*2+1,mid+1,right);
        if(leftmost == -1 && a[id*2].conlai != 0)
            timtrai(id*2,left,mid);
    }
}
/**/
void timphai(long id,long left,long right)
{
    long mid;
    
    if(a[id].trai == a[id].phai && a[id].conlai != 0)
    {
        rightmost = a[id].phai;
        return;
    }
    
    mid = (a[id].trai + a[id].phai) / 2;
    if(right <= mid)
    {
        if(a[id*2].conlai != 0)
            timphai(id*2,left,right);
    }
    else if(left > mid)
    {
        if(a[id*2+1].conlai != 0)
            timphai(id*2+1,left,right);
    }
    else
    {
        if(a[id*2].conlai != 0)
            timphai(id*2,left,mid);
            
        if(rightmost == -1 && a[id*2+1].conlai != 0)
            timphai(id*2+1,mid+1,right);
    }
}
/**/
void output()
{
    if(leftmost == -1)
        printf("* ");
    else
        printf("%ld ",leftmost);
    if(rightmost == -1)
        printf("*");
    else
        printf("%ld",rightmost);
    printf("\n");
}
/**/
void input()
{
    long i;
    long x,y;
    long rep;
    while(scanf("%ld %ld",&n,&rep) == 2)
    {
        if(!n && !rep)
            break;
        ctree(1,1,n);
        for(i=0;i<rep;i++)
        {
            scanf("%ld %ld",&l,&r);
            danhdau(1,l,r);
            leftmost = rightmost = -1;
            timtrai(1,1,l-1);
            timphai(1,r+1,n);
            output();
        }
        printf("-\n");
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
