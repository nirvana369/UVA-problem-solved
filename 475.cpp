/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "475.inp"
#define fo "475.out"
/**/
using namespace std;
/**/
string p[10000];
char s[1000000];
int dp,len,da;
bool out,dau,cuoi;
/**/
void xuly()
{
    int i;
    int dem;
    string tmp;
    
    dp = 0;
    i = 0;
    dau = cuoi = false;

    sscanf(s,"%s",&s);
    
    if(s[i] != '*')
        dau = true;
    tmp = "";
    while(s[i])
    {
        if(s[i] != '*')
            tmp += s[i];
        else if(tmp != "")
        {
            p[dp++] = tmp;
            tmp = "";
        }
        i++;
    }
    
    if(s[i-1] != '*')
        cuoi = true;

    if(tmp != "")
        p[dp++] = tmp;
}
/**/
void solve(int vt,int id)
{
    int i,j,j1;
        
    if(id == dp)
    {
        if(cuoi)
        {
            j = len-1;
            j1 = p[id-1].length()-1;
            while(j1 >= 0)
            {
                if(p[id-1][j1] != s[j])
                    break;
                j--;
                j1--;
            }
            if(j1 < 0)
                out = true;
        }
        else
            out = true;
        return;
    }
    
    if(vt >= len)
        return;
    
    if(dau)
    {
        if(id == 0)
        {
            j = 0;
            j1 = 0;
            while(p[id][j1] && j < len)
            {
                if(p[id][j1] != s[j])
                {
                    out = false;
                    return;
                }
                j1++;
                j++;
            }
            solve(j,id+1);
        }
    }
    
    for(i=vt;i<len;i++)
    {
        if(p[id][0] == s[i])
        {
            j = i;
            j1 = 0;
            while(p[id][j1] && j < len)
            {
                if(p[id][j1] != s[j])
                    break;
                j1++;
                j++;
            }
            if(!p[id][j1])
                solve(j,id+1);
        }
    }
}
/**/
void input()
{
    int id,pre;
    char tmp[100000];
    bool fst;
    
    id = 0;
    while(gets(s))
    {
        strcpy(tmp,s);
        
        xuly();
        
        da = 1;
        fst = true;
        while(true)
        {
            s[0] = 0;
            gets(s);
            if(!s[0])
                break;
                
            sscanf(s,"%s",&s);
            out = false;
            
            len = strlen(s);
            
            if(!dp && (dau || cuoi))
            {
                if(fst)
                {
                    if(id++ && pre > 1)
                        printf("\n");
                    printf("MATCHES FOR THE PATTERN: %s\n",tmp);
                    fst = false;
                }
                printf("%s\n",s);
                da++;
                continue;
            }
            solve(0,0);
            if(out)
            {
                if(fst)
                {
                    if(id++ && pre > 1)
                        printf("\n");
                    printf("MATCHES FOR THE PATTERN: %s\n",tmp);
                    fst = false;
                }
                printf("%s\n",s);
                da++;
            }
        }
        pre = da;
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
