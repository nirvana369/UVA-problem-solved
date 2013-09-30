/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
//#include <queue>
#include <vector>
//#include <map>

#define fi "10029.inp"
#define fo "10029.out"
#define m 25000
/**/
using namespace std;
/**/
char a[m+10][20];
vector<int > id[m+10];
int nhan[m+10];
int maxlen;
/**/
void khoitao()
{
    int i;
    
    for(i=0;i<=m;i++)
    {
        nhan[i] = 0;
        id[i].clear();
    }
    
    maxlen = 0;
}
/**/
int hash_val(long val)
{
    return (val % m);
}
/**/
int conv(char s[])
{
    int i;
    long val;
    
    val = 0;
    i = 0;
    
    while(s[i])
    {
        val *= 2;
        val += (s[i] - 96);
        i++;
    }
    
    return hash_val(val);
}
/**/
int proc(char s[])
{
    int i,j,k,t,j1;
    int lbl;
    char tmp;
    char s1[16],s2[16],s3[16];

    //////////
    for(i=0,j=1;s[i];i++,j++)
    {
        s3[j] = s[i];
        s2[i] = s[i];
    }
    s3[j] = 0;
    s2[i] = 0;
    ///////
    lbl = 0;
    
    for(i=0;s[i];i++) // del
    {
        for(j=0,k=0;s[j];j++)
            if(j != i)
                s1[k++] = s[j];
                        
        s1[k] = 0;
        t = conv(s1);
        
        for(j=0;j<id[t].size();j++)
        {
            k = id[t][j];
            if(strcmp(s1,a[k]) == 0)
            {
                if(lbl <= nhan[k])
                    lbl = nhan[k] + 1;
            }
        }    
        tmp = s2[i];
        
        for(j='a';j<='z';j++) // add & change
        {
            s2[i] = j;
            s3[i] = j;
            
            if(j != tmp)
            {
                t = conv(s2);
                for(j1=0;j1<id[t].size();j1++)
                {
                    k = id[t][j1];
                    if(strcmp(s2,a[k]) == 0)
                    {
                        if(lbl <= nhan[k])
                            lbl = nhan[k] + 1;
                    }
                }   
            }
            
            t = conv(s3);
            for(j1=0;j1<id[t].size();j1++)
            {
                k = id[t][j1];
                if(strcmp(s3,a[k]) == 0)
                {
                    if(lbl <= nhan[k])
                        lbl = nhan[k] + 1;
                }
            }
        }
        
        s2[i] = tmp;
        swap(s3[i],s3[i+1]);
    }
    
    for(j='a';j<='z';j++) // add 
    {
        s3[i] = j;
            
        t = conv(s3);
        for(j1=0;j1<id[t].size();j1++)
        {
            k = id[t][j1];
            if(strcmp(s3,a[k]) == 0)
            {
                if(lbl <= nhan[k])
                    lbl = nhan[k] + 1;
            }
        }
    }
    
    return lbl;
}
/**/
void solve(int k)
{
    nhan[k] = proc(a[k]);
    
    maxlen = nhan[k] > maxlen ? nhan[k] : maxlen;
    
    id[conv(a[k])].push_back(k);
}
/**/
void input()
{
    int i;
    
    khoitao();
    
    i = 0;
    while(scanf("%s",a[i]) == 1)
    {
        solve(i);
        i++;
    }
    
    if(maxlen)
        maxlen++;
        
    printf("%d\n",maxlen);
}
/**/
int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    
    input();

    return 0;
}
