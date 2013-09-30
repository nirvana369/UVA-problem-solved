/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "146.inp"
#define fo "146.out"
/**/
using namespace std;
/**/
char s[110],s1[110],kq[110];
int len,success;
bool u[110],rs[110];
/**/
void dq(int id)
{
    int i;
    bool d[27];
    bool first;
    int vt;
    
    if(id == len)
    {
        success++;
        return;
    }
    
    for(i=0;i<27;i++)
        d[i] = true;
    
    if(rs[id])
    {       
        for(i=0;i<s[id]-97;i++)
            d[i] = false;
        rs[id] = false;
        
        for(i=0;i<len;i++)
            if(s1[i] == s[id] && u[i])
            {
                vt = i;
                break;
            }
    }
    else
        vt = 0;
        
    for(i=vt;i<len;i++)
    {
        if(u[i] && d[s1[i]-97])
        {
            u[i] = false;
            d[s1[i]-97] = false;
            kq[id] = s1[i];
            dq(id+1);
            if(success == 2)
                return;
            u[i] = true;
        }
    }
}
/**/
bool sapxep()
{
    int i,j;
    char tmp;
    
    for(i=0;i<len;i++)
        for(j=i+1;j<len;j++)
            if(s1[i] > s1[j])
            {
                tmp = s1[i];
                s1[i] = s1[j];
                s1[j] = tmp;
            }
            
    for(i=0,j=len-1;i<len;i++,j--)
        if(s[i] != s1[j])
            return true;
    return false;
}
/**/
void input()
{
    int i;
    while(gets(s))
    {
        if(s[0] == '#')
            break;
        i = 0;
        while(s[i])
        {
            s1[i] = s[i];
            u[i] = true;
            rs[i] = true;
            i++;
        }
        len = i;
        success = 0;
        kq[len] = 0;
    
        if(sapxep())
            dq(0);
    
        if(success == 2)
            printf("%s\n",kq);
        else
            printf("No Successor\n");
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
