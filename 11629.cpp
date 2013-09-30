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

#define fi "11629.inp"
#define fo "11629.out"
/**/
using namespace std;
/**/
map <string, int> mmap;
/**/
void xuly(char s[])
{
    int i;
    char temp[10000],comp[10000];
    int l,dem,dc;
    int sum,val;
    bool back;
        
    l = strlen(s);
    s[l] = ' ';
    dem = dc = 0;
    sum = 0;
    back = false;
    //process string
    for(i=0;i<=l;i++)
        if(s[i] == ' ' || s[i] == '+')
        {
            temp[dem] = 0;
            if(back && dem != 0)
            {
                sscanf(temp,"%d",&val);
                break;
            }
            if(dem != 0)
                sum += mmap[temp];
            dem = 0;
        }
        else if(s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9')
            temp[dem++] = s[i];
        else if(s[i] == '>' || s[i] == '<' || s[i] == '=')
        {
            back = true;
            comp[dc++] = s[i];
        }
    val *= 10;
    // compare
    if(dc == 1)
    {
        if(comp[dc-1] == '=')
        {
            if(val == sum)
                printf("correct.");
            else
                printf("incorrect.");
        }
        
        if(comp[dc-1] == '>')
        {
            if(sum > val)
                printf("correct.");
            else
                printf("incorrect.");
        }
        if(comp[dc-1] == '<')
        {
            if(sum < val)
                printf("correct.");
            else
                printf("incorrect.");
        }
    }
    else
    {
        if(comp[dc-2] == '<' && comp[dc-1] == '=')
        {
            if(sum <= val)
                printf("correct.");
            else
                printf("incorrect.");
        }
        
        if(comp[dc-2] == '>' && comp[dc-1] == '=')
        {
            if(sum >= val)
                printf("correct.");
            else
                printf("incorrect.");
        }
    }
    printf("\n");
}
/**/
void input()
{
    int i;
    char temp[10000],name[100];
    double val;
    int p,g;
    
    while(true)
    {
        p = g = 0;
        scanf("%d %d",&p,&g);
        
        if(!p && !g)
            break;
        gets(temp);
        
        mmap.clear();
        for(i=0;i<p;i++)
        {
            gets(temp);
            sscanf(temp,"%s %lf",&name,&val);
            val *=10;
            mmap[name] = (int)val;
        }
        for(i=0;i<g;i++)
        {
            gets(temp);
            printf("Guess #%d was ",i+1);
            xuly(temp);
        }
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
