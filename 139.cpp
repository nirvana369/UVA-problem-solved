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

#define fi "139.inp"
#define fo "139.out"
/**/
using namespace std;
/**/
struct tele{
                char name[1000],code[1000];
                int l,f;
            };
tele a[10000];
char key[10000];
int n;
/**/
bool chk_out(char s[])
{
    int i;
    if(s[0] == '#')
        return true;
    return false;
}
/**/
void xuly(char s[],int id)
{
    int i,j;
    
    i = 0;
    while(s[i])
    {
        if(s[i] == '$')
            break;
        a[id].name[i] = s[i];
        i++;
    }
    a[id].name[i] = 0;
    
    i++;
    j = 0;
    while(s[i])
    {
        s[j] = s[i];
        j++;
        i++;
    }
    s[j] = 0;
    sscanf(s,"%d",&a[id].f);
}
/**/
bool cmp(char s1[],char s2[])
{
    int i,j;
    
    i = j = 0;
    
    while(s1[i] && s2[j])    
    {
        if(s1[i] != s2[j])
            return false;
        i++;
        j++;
    }
    
    j = 0;
    while(s1[i])
        key[j++] = s1[i++];
    key[j] = 0;
    return true;
}
/**/
int annalys(char s[])
{
    int len;
    int i;
    
    len = strlen(s);   
    
    if(s[0] >= '1' && s[0] <= '9')
    {
        strcpy(key,s);
        return 0;
    }
    for(i=1;i<n;i++)
        if(len > a[i].l && cmp(s,a[i].code))
        {
            if(a[i].code[1] == '0' && (len - a[i].l < 4 || len - a[i].l > 10))
                continue;
            if(a[i].code[1] != '0' && (len - a[i].l < 4 || len - a[i].l > 7))
                continue;
            return i;
        }
    return -1;
}
/**/
void input()
{
    int i;
    int id,val;
    char s[10000];
    
    n = 1;
    strcpy(a[0].name,"Local");
    a[0].f = 0;
    
    while(gets(s))
    {
        sscanf(s,"%s %[^$] $ %d",&a[n].code,&a[n].name,&a[n].f);
        
        if (!strcmp(a[n].code, "000000"))
			break;
        a[n].l = strlen(a[n].code);

        if (a[n].code[0] != '0') 
			continue;

		if (a[n].code[1]=='0' && (a[n].l < 3 || a[n].l > 5)) 
			continue;
		else if (a[n].l < 2 || a[n].l > 6)
			continue;

        n++;
    }
    
    while(scanf("%s",&s))
    {
        if(chk_out(s))
            break;
        scanf("%d",&val);
        id = annalys(s);
        if(id >= 0)
            printf("%-15s %-25s%10s%5d%3d.%02d%4d.%02d\n",s,a[id].name,key,val,a[id].f/100,a[id].f%100,a[id].f*val/100,a[id].f*val%100);
        else
            printf("%-15s %-25s            %3d        -1.00\n",s,"Unknown",val);
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
