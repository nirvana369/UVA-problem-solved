/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "213.inp"
#define fo "213.out"
/**/
using namespace std;
/**/
char pat[10000][10],s[10000],tmp[10];
int bin[5];
map<string, int > mmap;
int es,dp,seg,len,dem;
/**/
void dfs(int id,int one)
{
    int i;
    int o;
    
    if(id == es)
    {
        if(one == es)
            return;
        s[es] = 0;
        strcpy(pat[dp++],s);
        return;
    }
    
    for(i='0';i<='1';i++)
    {
        if(i == '1')
            o = 1;
        else
            o = 0;
            
        s[id] = i;
        dfs(id+1,one+o);
    }
}
/**/
void gen()
{
    int i;
    
    dp = 0;
    for(i=1;i<=7;i++)
    {
        es = i;
        dfs(0,0);
    }
    
    for(i=3,es=4;i>0;i--,es/=2)
        bin[i] = es;
}
/**/
void gan(char s[])
{
    int i,j;
    
    i = j = 0;
    mmap.clear();
    while(s[i])
        mmap[pat[j++]] = s[i++];
}
/**/
bool solve(char s[])
{
    int i;
    int kt;
    
    i = 0;
    while(s[i])
    {
        if(seg)
        {
            if(s[i] == '1')
                len += bin[seg];
            seg--;
        }
        else
        {
            tmp[dem++] = s[i];
            if(dem == len)
            {
                tmp[dem] = 0;
                dem = 0;
                
                kt = mmap[tmp];
                if(kt)
                    printf("%c",kt);
                else
                {
                    seg = 3;
                    len = 0;
                }
            }
        }
        i++;
    }
    if(!len && !seg)
        return true;
    return false;
}
/**/
void input()
{
    gen();
    
    while(gets(s))
    {
        gan(s);
        
        seg = 3;
        len = 0;
        dem = 0;
        
        while(gets(s))
        {
            if(solve(s))
                break;
        }   
        printf("\n");
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
