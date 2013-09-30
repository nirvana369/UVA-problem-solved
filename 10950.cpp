/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "10950.inp"
#define fo "10950.out"
/**/
using namespace std;
/**/
char op[110][10000],s[10000],code[2000][10000],a[2000][10000],kq[10000];
int len,d,n;
/**/
void swapcode(int x,int y)
{
    char tmp[10000];
    
    strcpy(tmp,a[x]);
    strcpy(a[x],a[y]);
    strcpy(a[y],tmp);
    
    strcpy(tmp,code[x]);
    strcpy(code[x],code[y]);
    strcpy(code[y],tmp);
}
/**/
void sapxep()
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
            if(strcmp(a[i],a[j]) > 0)
                swapcode(i,j);
}
/**/
int sosanh(char s1[],int vt)
{
    int i;
    i = 0;
    while(s1[i] && vt < len)
    {
        if(s1[i] != s[vt])
            return 0;
        i++;
        vt++;
    }
    if(s1[i] && vt == len)
        return 0;
        
    return vt;
}
/**/
int ghep(char s1[],int id,char s2[])
{
    int i;
    i = 0;
    while(s2[i])
        s1[id++] = s2[i++];
    return id;
}
/**/
void dq(int id,int tt)
{
    int i;
    int tmp,l;
    
    if(id == len)
    {
        kq[tt] = 0;
        strcpy(op[d++],kq);
        return;
    }
    
    for(i=0;i<n;i++)
    {
        tmp = sosanh(code[i],id);
        if(tmp)
        {
            l = ghep(kq,tt,a[i]);
            dq(tmp,l);
            if(d == 100)
                return;
        }
    }
    
    if(s[id] == '0')
    {
        id++;
        for(i=0;i<n;i++)
        {
            tmp = sosanh(code[i],id);
            if(tmp)
            {
                l = ghep(kq,tt,a[i]);
                dq(tmp,l);
                if(d == 100)
                    return;
            }
        }   
    }
}
/**/
void output(int id)
{
    int i;
    printf("Case #%d\n",id);
    for(i=0;i<d;i++)
        printf("%s\n",op[i]);
    printf("\n");
}
/**/
void input()
{
    int i;
    int id;
    id = 1;
    while(scanf("%d",&n) && n)
    {
        for(i=0;i<n;i++)
            scanf("%s %s",&a[i],&code[i]);
        scanf("%s",&s);
        len = strlen(s);
        d = 0;
        sapxep();
        dq(0,0);
        output(id++);
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
