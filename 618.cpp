/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "618.inp"
#define fo "618.out"
/**/
using namespace std;
/**/
struct rat{
                int w,h;
            };
rat win;
rat a[4];
bool d[4];
/**/
int ucln(int x,int y)
{
    int r;
    while(y != 0)
    {
        r = x % y;
        x = y;
        y = r;
    }
    return x;
}
/**/
int bcnn(int x,int y)
{
    return (x / ucln(x,y) * y);
}
/**/
rat samew(rat x,rat y)
{
    rat tmp;
    
    tmp.w = bcnn(x.w,y.w); // lay min chieu rong
    tmp.h = ((tmp.w / x.w) * x.h + (tmp.w / y.w) * y.h); // quy dong - > cong chieu cao
    return tmp;
}
/**/
rat sameh(rat x,rat y)
{
    rat tmp;
    
    tmp.h = bcnn(x.h,y.h); // lay min chieu cao
    tmp.w = ((tmp.h / x.h) * x.w + (tmp.h / y.h) * y.w); // quy dong - > cong chieu rong
    return tmp;
}
/**/
bool chk(rat x)
{
    if((double)x.h / x.w == (double)win.h / win.w)
    {
        //printf("%d %d\n",x.h,x.w);
        return true;
    }
    return false;
}
/**/
bool solve()
{
    int i,j,j1,k;
    rat tmp,tmp1,tmp2;
    
    tmp = a[0];
    tmp1 = a[0];
    for(i=1;i<4;i++)
    {
        d[i] = true;
        tmp = samew(tmp,a[i]);
        tmp1 = sameh(tmp1,a[i]);
    }
    d[0] = true;
    
    if(chk(tmp))
        return true;
        
    if(chk(tmp1))
        return true;
        
    for(i=0;i<4;i++)
    {
        d[i] = false;
        
        for(j=0,k=0;j<4;j++,k++)
            if(d[j])
            {
                if(!k)
                {
                    tmp = a[j];
                    tmp1 = a[j];
                }
                else
                {
                    tmp = samew(tmp,a[j]);
                    tmp1 = sameh(tmp1,a[j]);
                }
            }
        tmp = sameh(a[i],tmp);
        tmp1 = samew(a[i],tmp1);
        if(chk(tmp))
            return true;
            
        if(chk(tmp1))
            return true;
            
        d[i] = true;
    }
    
    for(i=0;i<4;i++)
    {
        d[i] = false;
        for(j=i+1;j<4;j++)
        {
            tmp = samew(a[i],a[j]);
            d[j] = false;
            for(j1=0,k=0;j1<4;j1++,k++)
                if(d[j1])
                {
                    if(!k)
                        tmp1 = a[j1];
                    else
                        tmp1 = samew(tmp1,a[j1]);
                }
            tmp = sameh(tmp,tmp1);
            if(chk(tmp))
                return true;
                
            d[j] = true;
        }
        d[i] = true;
    }
    
    for(i=0;i<4;i++)
    {
        d[i] = false;
        for(j=i+1;j<4;j++)
        {
            tmp = sameh(a[i],a[j]);
            d[j] = false;
            for(j1=0,k=0;j1<4;j1++,k++)
                if(d[j1])
                {
                    if(!k)
                        tmp1 = a[j1];
                    else
                        tmp1 = sameh(tmp1,a[j1]);
                }
            tmp = samew(tmp,tmp1);
            if(chk(tmp))
                return true;
                
            d[j] = true;
        }
        d[i] = true;
    }
    
    for(i=0;i<4;i++)
    {
        d[i] = false;
        for(j=0;j<4;j++)
        {
            if(d[j])
            {
                tmp = samew(a[i],a[j]);
                d[j] = false;
                for(j1=0,k=0;j1<4;j1++,k++)
                    if(d[j1])
                    {
                        if(!k)
                            tmp1 = a[j1];
                        else
                            tmp1 = sameh(tmp1,a[j1]);
                    }
                tmp2 = samew(tmp,tmp1);
                
                if(chk(tmp2))
                    return true;
                    
                tmp2 = sameh(tmp,tmp1);    
                
                if(chk(tmp2))
                    return true;
                    
                d[j] = true;
            }
        }
        d[i] = true;
    }
    return false;
}
/**/
void input()
{
    int i;
    int id;
    id = 1;
    
    while(scanf("%d %d",&win.w,&win.h))
    {
        if(!win.h && !win.w)
            return;
            
        for(i=0;i<4;i++)
            scanf("%d %d",&a[i].w,&a[i].h);
        printf("Set %d: ",id++);
        if(solve())
            printf("Yes\n");
        else
            printf("No\n");
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
