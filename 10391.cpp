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

#define fi "10391.inp"
#define fo "10391.out"
/**/
using namespace std;
/**/
map<string, int > mmap;
char a[120010][30];
long da;
/**/
bool kiemtra(char s[])
{
    int i,j,k;
    bool combine;
    char temp;
    char s1[30];
    
    i = 1;
    
    if(!s[i])
        return false;
        
    while(s[i] != 0)
    {
        combine = false;
        temp = s[i];
        s[i] = 0;
        if(mmap[s])
        {
            j = 0;
            s1[j++] = temp;
            k = i + 1;
            while(s[k] != 0)
                s1[j++] = s[k++];
            s1[j] = 0;
            if(mmap[s1])
                combine = true;
        }
        s[i] = temp;
        if(combine)
            return true;
        i++;
    }
    return false;
}
/**/
void solve()
{
    long i;
 
    for(i=0;i<da;i++)
        if(kiemtra(a[i]))
            printf("%s\n",a[i]);
}
/**/
void input()
{
    da = 0;
    mmap.clear();
    while(true)
    {
        a[da][0] = 0;
        gets(a[da]);
        if(!a[da][0])
            break;
        mmap[a[da]] = 1;
        da++;
    }
    solve();
}
/**/
int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    input();
    return 0;
}
