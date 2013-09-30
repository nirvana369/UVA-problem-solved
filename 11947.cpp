/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "11947.inp"
#define fo "11947.out"
/**/
using namespace std;
/**/
int m[14];
int month,year,day;
char zodiac[14][20];
/**/
void _init()
{
    int i;
    for(i=1;i<8;i++)
        if(i % 2 != 0)
            m[i] = 31;
        else
            m[i] = 30;
    for(i=8;i<13;i++)
        if(i % 2 != 0)
            m[i] = 30;
        else
            m[i] = 31;
            
    strcpy(zodiac[1],"aquarius");
    strcpy(zodiac[2],"pisces");
    strcpy(zodiac[3],"aries");
    strcpy(zodiac[4],"taurus");
    strcpy(zodiac[5],"gemini");
    strcpy(zodiac[6],"cancer");
    strcpy(zodiac[7],"leo");
    strcpy(zodiac[8],"virgo");
    strcpy(zodiac[9],"libra");
    strcpy(zodiac[10],"scorpio");
    strcpy(zodiac[11],"sagittarius");
    strcpy(zodiac[12],"capricorn");
}
/**/
bool chky(int ny)
{
    if(ny % 400 == 0)
        return true;
    if(ny % 100 == 0)
        return false;
    if(ny % 4 == 0)
        return true;
    return false;
}
/**/
int chkz()
{
    if(month == 1)
    {
        if(day < 20)
            return 12;
        else
            return 1;
    }
   
    if(month == 2)
    {
        if(day < 19)
            return 1;
        else
            return 2;
    }
    
    if(month == 3)
    {
        if(day < 20)
            return 2;
        else
            return 3;
    }
    
    if(month == 4)
    {
        if(day < 20)
            return 3;
        else
            return 4;
    }
    
    if(month == 5)
    {
        if(day < 21)
            return 4;
        else
            return 5;
    }
    
    if(month == 6)
    {
        if(day < 21)
            return 5;
        else
            return 6;
    }
    
    if(month == 7)
    {
        if(day < 22)
            return 6;
        else
            return 7;
    }
    
    if(month == 8)
    {
        if(day < 21)
            return 7;
        else
            return 8;
    }
    
    if(month == 9)
    {
        if(day < 23)
            return 8;
        else
            return 9;
    }
    
    if(month == 10)
    {
        if(day < 23)
            return 9;
        else
            return 10;
    }
    
    if(month == 11)
    {
        if(day < 22)
            return 10;
        else
            return 11;
    }
    
    if(month == 12)
    {
        if(day < 22)
            return 11;
        else
            return 12;
    }
}
/**/
void solve()
{
    int im,ms,baby,d;
    bool checkyear;
    
    checkyear = false;
    baby = 40*7;
    
    while(baby--)
    {
        if(!checkyear)    
        {
            if(chky(year))
                m[2] = 29;
            else
                m[2] = 28;
            checkyear = true;
        }
        day++;
        
        if(day > m[month])
        {
            day = 1;
            month++;
        }
        if(month == 13)
        {
            month = 1;
            year++;
            checkyear = false;
        }
    }
}
/**/
void xuly(char s[])
{
    int i;
    month = (s[0] - 48) * 10 + (s[1] - 48);
    day = (s[2] - 48) * 10 + (s[3] - 48);
    year = 0;
    for(i=4;s[i];i++)
    {
        year *= 10;
        year += (s[i] - 48);
    }
}
/**/
void input()
{
    _init();
    char s[100];
    int ntest,id;
    
    id = 1;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%s",&s);
        xuly(s);
        solve();
        printf("%d %02d/%02d/%04d %s\n",id++,month,day,year,zodiac[chkz()]);
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
