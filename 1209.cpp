/*
                                                        Hoang Linh
                                                        
                            using dfs + mark array genarate next-permutation && pre-permutation
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "1209.inp"
#define fo "1209.out"
#define maxgt 100000
/**/
using namespace std;
/**/
char s[110],s1[110],kq[110],a[30][110];
int len,success;
bool u[110],rs[110];
/**/
void dq_pre(int id) // pre permutation
{
    int i;
    bool d[27];
    bool first;
    int vt;
    
    if(id == len)
    {
        kq[id] = 0;
        ++success;
        if(success > 11)
            strcpy(a[success-1],kq);
        return;
    }
    
    for(i=0;i<27;i++)
        d[i] = true;
    
    if(rs[id])
    {       
        for(i='Z'-65;i>s[id]-65;i--)
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
        if(u[i] && d[s1[i]-65])
        {
            u[i] = false;
            d[s1[i]-65] = false;
            kq[id] = s1[i];
            dq_pre(id+1);
            
            if(success == 21)
                return;
                
            u[i] = true;
        }
    }
}
/**/
void sapxep_pre()
{
    int i,j;
    char tmp;
    
    for(i=0;i<len;i++)
        for(j=i+1;j<len;j++)
            if(s1[i] < s1[j])
            {
                tmp = s1[i];
                s1[i] = s1[j];
                s1[j] = tmp;
            }
}
/**/
void dq(int id) //  next permutation
{
    int i;
    bool d[27];
    bool first;
    int vt;
    
    if(id == len)
    {
        kq[id] = 0;
        strcpy(a[success--],kq);
        return;
    }
    
    for(i=0;i<27;i++)
        d[i] = true;
    
    if(rs[id])
    {       
        for(i=0;i<s[id]-65;i++)
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
        if(u[i] && d[s1[i]-65])
        {
            u[i] = false;
            d[s1[i]-65] = false;
            kq[id] = s1[i];
            dq(id+1);
            
            if(success == -1)
                return;
                
            u[i] = true;
        }
    }
}
/**/
void sapxep()
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
}
/**/
void solve()
{
    int i,j;
    int mind,maxd;
    long kq,tmp;
    
    maxd = 0;
    for(i=20;i>=0;i--)
    {
        mind = maxgt;
        for(j=0;j<len-1;j++)
            mind = min(mind,abs(a[i][j]-a[i][j+1]));

        if(mind > maxd && mind != maxgt)
        {
            maxd = mind;
            tmp = i;
            kq = mind;
        }
    }
    
    printf("%s%d\n",a[tmp],kq);
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
        success = 10;
        
        sapxep();
        dq(0);
        
        i = 0;       
        while(s[i])
        {
            s1[i] = s[i];
            u[i] = true;
            rs[i] = true;
            i++;
        }
        success = 10;
        sapxep_pre();
        dq_pre(0);
        
        //for(i=success-1;i>=0;i--) // check 0 to 20 
          //  printf("%s\n",a[i]);
        solve();
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
