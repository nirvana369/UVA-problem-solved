/*
                                                    Hoang Linh
                                        
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define fi "11235.inp"
#define fo "11235.out"
/**/
using namespace std;
/**/
struct  fvalue{
                long xp,kt;
                long vl,vm,vr;
                long fl,fm,fr;
                };
                
fvalue tree[1000000],khoang[10000];
fvalue luu;
long a[100010];
long n,q,demkhoang,maxkhoang,maxkq;
/**/
void ctree(long dau,long cuoi,long nut)
{
    long mid;
    if(dau == cuoi)
    {
        tree[nut].xp = dau;
        tree[nut].kt = cuoi;
        tree[nut].vm = a[dau];
        tree[nut].fm = 1;
        tree[nut].vr = a[dau];
        tree[nut].fr = 1;
        tree[nut].vl = a[dau];
        tree[nut].fl = 1;
        return;    
    }
    
    tree[nut].xp = dau;         // cap nhap dau cuoi
    tree[nut].kt = cuoi;
    
    mid = (dau+cuoi)/2;
    //
    ctree(dau,mid,nut*2);
    ctree(mid+1,cuoi,nut*2+1);
    //
    tree[nut].vm = tree[nut*2].vm;  // gan gia tri giua nut con trai cho nut cha
    tree[nut].fm = tree[nut*2].fm;
    
    if(tree[nut*2+1].fm > tree[nut].fm)     // neu gia tri giua nut con phai > giatri giua nut cha >> cap nhap
    {
        tree[nut].vm = tree[nut*2+1].vm;
        tree[nut].fm = tree[nut*2+1].fm;
    }
    
    if(tree[nut*2].vr == tree[nut*2+1].vl)      // neu gia tri trai nut con phai == gia tri phai nut con trai
        if(tree[nut*2].fr + tree[nut*2+1].fl > tree[nut].fm)// -- >  tong tan suat > nut cha
        {
            tree[nut].fm = tree[nut*2].fr + tree[nut*2+1].fl;   // gan cho nut cha tong tan suat va gia tri
            tree[nut].vm = tree[nut*2].vr;
        }
    
    if(tree[nut*2+1].vl == tree[nut*2].vr && tree[nut*2+1].fr == (tree[nut*2+1].kt - tree[nut*2+1].xp)+1)  // cap nhap nut cha phai
    {
        tree[nut].vr = tree[nut*2].vr;      
        tree[nut].fr = tree[nut*2+1].fr + tree[nut*2].fr;
    }
    else
    {
        tree[nut].vr = tree[nut*2+1].vr; 
        tree[nut].fr = tree[nut*2+1].fr;
    }
    
    if(tree[nut*2+1].vl == tree[nut*2].vr && tree[nut*2].fl == (tree[nut*2].kt - tree[nut*2].xp)+1)    // same ^ with right subtree
    {
        tree[nut].vl = tree[nut*2].vl;
        tree[nut].fl = tree[nut*2].fl + tree[nut*2+1].fl;
    }
    else
    {
        tree[nut].vl = tree[nut*2].vl;
        tree[nut].fl = tree[nut*2].fl;
    }
}
/**/
void xuly(long nut)
{
    //printf("%ld %ld | %ld:%ld %ld:%ld %ld:%ld\n",tree[nut].xp,tree[nut].kt,tree[nut].vl,tree[nut].fl,tree[nut].vm,tree[nut].fm,tree[nut].vr,tree[nut].fr);
    if(tree[nut].fm == (tree[nut].kt - tree[nut].xp) + 1 && tree[nut].vl == tree[nut].vr)
    {
        if(tree[nut].vl == khoang[maxkhoang-1].vm)
            khoang[maxkhoang-1].fm = khoang[maxkhoang-1].fm + tree[nut].fm;
        else
        {
            khoang[maxkhoang].fm = tree[nut].fm;
            khoang[maxkhoang].vm = tree[nut].vm;
            maxkhoang++;   
        }
        
        if(khoang[maxkhoang-1].fm > maxkq)
            maxkq = khoang[maxkhoang-1].fm;
    }
    else
    {
        if(tree[nut].vl == khoang[maxkhoang-1].vm)
        {
            khoang[maxkhoang-1].fm = khoang[maxkhoang-1].fm + tree[nut].fl;
            
            if(khoang[maxkhoang-1].fm > maxkq)
                maxkq = khoang[maxkhoang-1].fm;
                
            khoang[maxkhoang].fm = tree[nut].fm;
            khoang[maxkhoang].vm = tree[nut].vm;
            maxkhoang++;
            
            if(khoang[maxkhoang-1].fm > maxkq)
                maxkq = khoang[maxkhoang-1].fm;
            
            khoang[maxkhoang].fm = tree[nut].fr;
            khoang[maxkhoang].vm = tree[nut].vr;
            maxkhoang++;
            
            if(khoang[maxkhoang-1].fm > maxkq)
                maxkq = khoang[maxkhoang-1].fm;
        }
        else
        {
            khoang[maxkhoang].fm = tree[nut].fl;
            khoang[maxkhoang].vm = tree[nut].vl;
            maxkhoang++;
            
            if(khoang[maxkhoang-1].fm > maxkq)
                maxkq = khoang[maxkhoang-1].fm;
                
            khoang[maxkhoang].fm = tree[nut].fm;
            khoang[maxkhoang].vm = tree[nut].vm;
            maxkhoang++;
            
            if(khoang[maxkhoang-1].fm > maxkq)
                maxkq = khoang[maxkhoang-1].fm;
                
            khoang[maxkhoang].fm = tree[nut].fr;
            khoang[maxkhoang].vm = tree[nut].vr;
            maxkhoang++;
            
            if(khoang[maxkhoang-1].fm > maxkq)
                maxkq = khoang[maxkhoang-1].fm;
        }
    }
}
/**/
void ftree(long dau,long cuoi,long nut)
{
    long mid;
    if(tree[nut].xp == dau && tree[nut].kt == cuoi)
    {    
        xuly(nut);
        return;
    }
    
    if(cuoi <= tree[nut*2].kt)
        ftree(dau,cuoi,nut*2);
    else if(dau >= tree[nut*2+1].xp)
        ftree(dau,cuoi,nut*2+1);
    else
    {
        mid = (tree[nut].xp+tree[nut].kt)/2;
        ftree(dau,mid,nut*2);
        ftree(mid+1,cuoi,nut*2+1);
    }
}
/**/
void solve()
{
    int i;
    
    for(i=1;i<maxkhoang;i++)
        printf("%ld %ld\n",khoang[i].vm,khoang[i].fm);
    printf("\n");
}
/**/
void resetval()
{
    khoang[0].fm = 200000; 
    khoang[0].vm = 200000;
    maxkhoang = 1;
    maxkq = 0;
}
/**/
void input()
{
    long i;
    long dau,cuoi;
    while(true)
    {
        scanf("%ld %ld",&n,&q);
        if(n == 0)
            break;
        for(i=1;i<=n;i++)
            scanf("%ld",&a[i]);
        ctree(1,n,1);
        
        for(i=0;i<q;i++)
        {
            resetval();
            scanf("%ld %ld",&dau,&cuoi);
            ftree(dau,cuoi,1);
            //solve();
            printf("%ld\n",maxkq);
        }
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
