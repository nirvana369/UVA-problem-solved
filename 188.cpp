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

#define fi "188.inp"
#define fo "188.out"
/**/
using namespace std;
/**/
long long a[16];
int n;
/**/
void sapxep()
{
    int i,j;
    
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
            if(a[i] > a[j])
                swap(a[i],a[j]);
}
/**/
void xuly(char s[])
{
    int i;
    long long val;
    
    n = 0;
    i = 0;
    val = 0;
    
    while(s[i])
    {
        if(isalpha(s[i]))
        {
            val *= 32;
            val += s[i] - 96;
        }
        else if(val)
        {
            a[n++] = val;
            val = 0;
        }
        i++;
    }
    
    if(val)
        a[n++] = val;
        
    sapxep();
}
/**/
long long solve()
{
    int i,j;
    long long c;
    
    c = a[0];
    
    while(1)
    {
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
                if((c / a[i]) % n == (c / a[j]) % n)
                {
                    c = min((c / a[i] + 1) * a[i],(c / a[j] + 1) * a[j]);
                    break;
                }
            if(j != n)
                break;
        }
        if(i == n)
            break;
    }
    
    return c;
}
/**/
void input()
{
    char s[10000];
    int id;
    
    id = 0;
    while(1)
    {
        s[0] = 0;
        gets(s);
        if(!s[0])
            break;
        xuly(s);
        printf("%s\n%lld\n\n",s,solve());
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
