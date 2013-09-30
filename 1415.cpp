/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "1415.inp"
#define fo "1415.out"
/**/
using namespace std;
/**/
bool chk(long val)
{
    int i;
    int add,tmp;
    
    if(val == 2 || val == 3)
        return true;
        
    if(val < 2 || val % 2 == 0 || val % 3 == 0)
        return false;
    
    tmp = (int)sqrt(val);
    add = 2;
    for(i=5;i<=tmp;i+=add,add=6-add)
        if(val % i == 0)
            return false;
    return true;
}
/**/
void input()
{
    long a,b;
    bool p;
    int ntest;
    
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%ld %ld",&a,&b);
        p = false;
        if(!a)
        {
            b -= 6;
            if(b < 0)
                b = -b;
            if(b % 8 == 0)
                p = true;
        }
        else if(!b)
        {
            a -= 6;
            if(a < 0)
                a = -a;
            if(a % 8 == 0)
                p = true;
        }
        else
        {
            a *= a;
            b *= b;
            b *= 2;
            a += b;
            if(chk(a))
                p = true;
        }
        if(p)
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
