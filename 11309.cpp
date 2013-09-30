/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "11309.inp"
#define fo "11309.out"
/**/
using namespace std;
/**/
bool chk(int m)
{
    int h;
    int i,j;
    int t[10];
    
    h = m / 60;
    m = m % 60;
    i = 0;
    if(!h && m < 10)
        t[i++] = m;
    else
    {
        if(m < 10)
        {
            t[i++] = m;
            t[i++] = 0;
        }
        else
        {
            while(m != 0)
            {
                t[i++] = m % 10;
                m /= 10;
            }
        }
    }
    
    while(h != 0)    
    {
        t[i++] = h % 10;
        h /= 10;
    }
    
    i--;
    j = 0;
    while(i >= 0 && j < i)
    {
        if(t[i] != t[j])
            return false;
        i--;
        j++;
    }
    return true;
}
/**/
void output(int m)
{
    int h;
    h = m / 60;
    m = m % 60;
    printf("%02d:%02d\n",h,m);
}
/**/
void input()
{
    int ntest;
    int h,m;
    
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%d:%d",&h,&m);
        m += h * 60;
        while(true)
        {
            m++;
            if(m == 1440)
                m = 0;
            if(chk(m))
                break;
        }
        output(m);
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
