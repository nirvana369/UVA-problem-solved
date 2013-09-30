/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "860.inp"
#define fo "860.out"
/**/
using namespace std;
/**/
map<string, long > mmap;
long cword;
/**/
bool chk(char kt)
{
    if(kt == ' ' || kt == ',' ||  kt == '.' || kt == ':' || kt == ';' || kt == '!' || kt == '?' || kt == '(' || kt == ')' || kt== 34)
        return false;
    return true;
}
void solve(char s[])
{
    int i;
    int dem;
    char tmp[1000];
    
    i = dem = 0;
    while(s[i])
    {
        if(s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z' || chk(s[i]))
        {
            if(s[i] >= 'A' && s[i] <= 'Z')
                s[i] += 32;
            tmp[dem++] = s[i];
        }
        else if(dem != 0)
        {
            tmp[dem] = 0;
            mmap[tmp]++;
            cword++;
            dem = 0;
        }
        i++;
    }
    
    if(dem != 0)
    {
        tmp[dem] = 0;
        mmap[tmp]++;
        cword++;
    }
}
/**/
void output()
{
    double et,erel,emax,t;
    map<string, long >::iterator i;
    
    emax = log10(cword);
    t = 0;
    for(i=mmap.begin();i!=mmap.end();i++)
        t += i -> second * (emax - log10(i -> second));
    et = t / cword;
    erel = (et / emax) * 100;
    if(!cword)
    {
        et = 0;
        erel = 0;
    }
    printf("%ld %0.1lf %.lf\n",cword,et,erel);
    
    cword = 0;
    mmap.clear();
}
/**/
void input()
{
    char s[100100],next[100],quit[100];
    
    strcpy(next,"****END_OF_TEXT****");
    strcpy(quit,"****END_OF_INPUT****");
    
    mmap.clear();
    cword = 0;
    while(true)
    {
        gets(s);
        if(strcmp(s,next) == 0)
            output();
        else if(strcmp(s,quit) == 0)
            break;
        else 
            solve(s);
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
