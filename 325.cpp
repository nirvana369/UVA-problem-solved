/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "325.inp"
#define fo "325.out"
/**/
using namespace std;
/**/
char s[1000];
int len;
/**/
void xuly()
{
    int i,j,k;
    i = 0;
    j = strlen(s) - 1;

    while(s[i] == ' ')
        i++;

    while(s[j] == ' ')
        j--;

    for(k=0;i<=j;i++,k++)
        s[k] = s[i];
    s[k] = 0;
    len = k;
}
/**/
bool solve()
{
    int cham,dcham,e,de,dd,dau;
    int i;
    
    cham = dau = -1;
    dcham = dd = de = 0;
    e = len-1;

    for(i=0;i<len;i++)
    {
        if(s[i] == '+' || s[i] == '-')
        {
            dau = i;
            dd++;
        }
        if(s[i] == '.')
        {
            cham = i;
            dcham++;
        }
        if(s[i] == 'E' || s[i] == 'e')
        {
            e = i;
            de++;
            break;
        }
    }
    
    if(dd > 1 || dcham > 1 || de > 1 || cham == 0) // neu co nhieu cham || neu dau cham xuat hien o dau || co nhieu dau
        return false;
    
    if(dd && (dau > 0 || !(s[dau+1] >= '0' && s[dau+1] <= '9'))) //  kiem tra neu co dau va dang sau dau la gi ?
        return false;
        
    if(!de && !dcham) // neu ko co cham && ko co e
        return false;
    
    if(de && e == len-1) // neu co e va phan sau ko co gi
        return false;
        
    if(dcham && (!(s[cham+1] >= '0' && s[cham+1] <= '9') || !(s[cham-1] >= '0' && s[cham-1] <= '9')))    // neu co cham va sau cham ko co so
        return false;
        
    for(i=0;i<e;i++)
        if(!((s[i] >= '0' && s[i] <= '9') || s[i] == '.' || (!i && (s[0] == '+' || s[0] == '-'))))
            return false;
    dd = 0;
    dau = e + 1;
    
    for(i=e+1;i<len;i++)
    {
        if((s[i] == '+' || s[i] == '-'))
        {
            dau = i;
            dd++; 
        }
        if(!((s[i] >= '0' && s[i] <= '9') || (i == (e + 1) && (s[e+1] == '+' || s[e+1] == '-'))))
            return false;
        if(s[i] == '.')
            return false;
    }
    if(dd > 1 || dau != (e + 1))
        return false;
  
    if(dd && !(s[dau+1] >= '0' && s[dau+1] <= '9')) //  neu co dau va dang sau dau ko co gi
        return false;
        
    return true;
}
/**/
void input()
{
    while(true)
    {
        gets(s);
        if(s[0] == '*') 
            break;
        xuly();
        if(solve())
            printf("%s is legal.\n",s);
        else
            printf("%s is illegal.\n",s);
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
