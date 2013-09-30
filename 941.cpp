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

#define fi "941.inp"
#define fo "941.out"
/**/
using namespace std;
/**/
long long f[23];
char s[23],kq[23];
int len;
/**/
void sapxep()
{
    int i,j;
    
    for(i=0;s[i];i++)
        for(j=i+1;s[j];j++)
            if(s[i] > s[j])
                swap(s[i],s[j]);
    len = i;
}
/**/
void donchuoi(char s1[],int j,int len1)
{
    int i;
    for(i=j;i<len1-1;i++)
        s1[i] = s1[i+1];
    s1[len1-1] = 0;
}
/**/
void permu(char s1[],long long vitri,int len1)
{
    int i;
    int id;
    long long kt;
        
    if(!len1)
        return;
        
    kt = 0;
    id = 0;
    for(i=0;i<=len1;i++)
        if(i * f[len1-1] <= vitri)
        {
            id = i;
            kt = i * f[len1-1];
        }
        else
            break;
        
    kq[len-len1] = s1[id];
    donchuoi(s1,id,len1);
    permu(s1,vitri-kt,len1-1);
}
/**/
void _init()
{
    int i;
    
    f[0] = 1;
    
    for(i=1;i<=21;i++)
        f[i] = i * f[i-1];
}
/**/
void input()
{
    int ntest;
    long long vt;
    
    _init();
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%s %lld",&s,&vt);
        sapxep();
        permu(s,vt,len);
        kq[len] = 0;
        printf("%s\n",kq);
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
