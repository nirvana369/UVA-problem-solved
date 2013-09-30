/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "462.inp"
#define fo "462.out"
/**/
using namespace std;
/**/
int d[100],sl[100],stop[100],king[100],queen[100];
int point,flg;
char esuit;
char a[15][3];
/**/
void khoitao()
{
    point = 0;
    d['S'] = sl['S'] = stop['S'] = king['S'] = queen['S'] = 0;
    d['D'] = sl['D'] = stop['D'] = king['D'] = queen['D'] = 0;
    d['H'] = sl['H'] = stop['H'] = king['H'] = queen['H'] = 0;
    d['C'] = sl['C'] = stop['C'] = king['C'] = queen['C'] = 0;
}
/**/
int getpoint(char card)
{
    if(card == 'A')
        return 4;
    if(card == 'K')
        return 3;
    if(card == 'Q')
        return 2;
    if(card == 'J')
        return 1;
    return 0;
}
/**/
int kiemtra(int id)
{
    int i;
    int dem;
    char suit,val;

    val = a[id][0];
    suit = a[id][1];

    if(val == 'A')
        stop[suit] = 1;
        
    if(val == 'K')
    {
        king[suit] = 1;
        for(i=0;i<13;i++)
            if(i != id)            
                if(a[i][1] == suit)
                    return 0;
        return -1;
    }
    else if(val == 'Q')
    {
        queen[suit] = 1;
        dem = 0;
        for(i=0;i<13;i++)
            if(i != id)            
                if(a[i][1] == suit)
                    dem++;
        if(dem <= 1)
            return -1;
        return 0;
    }
    else if(val == 'J')
    {
        dem = 0;
        for(i=0;i<13;i++)
            if(i != id)            
                if(a[i][1] == suit)
                    dem++;
        if(dem <= 2)
            return -1;
        return 0;
    }
    return 0;
}
/**/
void addpoint()
{
    if(sl['H'] <= 2)
    {
        if(sl['H'] == 2)
            point++;
        else
            point += 2;
    }
    if(sl['D'] <= 2)
    {
        if(sl['D'] == 2)
            point++;
        else
            point += 2;
    }
    if(sl['C'] <= 2)
    {
        if(sl['C'] == 2)
            point++;
        else
            point += 2;
    }
    if(sl['S'] <= 2)
    {
        if(sl['S'] == 2)
            point++;
        else
            point += 2;
    }
}
/**/
int getrank(char s)
{
    if(s == 'S')
        return 4;
    if(s == 'H')
        return 3;
    if(s == 'D')
        return 2;
    if(s == 'C')
        return 1;
}
/**/
char getmax(char s1,char s2)
{
    if(sl[s1] > sl[s2])
        return s1;
    if(sl[s1] < sl[s2])
        return s2;
    return (getrank(s1) > getrank(s2)) ? s1 : s2;
}
/**/
void checkstop()
{
    int i;
    char s[5];
    s[0] = 'H';
    s[1] = 'S';
    s[2] = 'D';
    s[3] = 'C';
    for(i=0;i<4;i++)
    {
        if(sl[s[i]]-1 >= 1 && king[s[i]])
            stop[s[i]] = 1;
        if(sl[s[i]]-1 >= 2 && queen[s[i]])
            stop[s[i]] = 1;
    }
}
/**/
int solve()
{
    int i;
    int tmp;
    
    for(i=0;i<13;i++)
    {
        tmp = getpoint(a[i][0]);
        d[a[i][1]] += tmp;
        point += tmp;
        point += kiemtra(i);
        sl[a[i][1]]++;
    }
    if(point >= 16)
    {
        checkstop();
        if(stop['H'] != 0 && stop['S'] != 0 && stop['D'] != 0 && stop['C'] != 0) //  no trump
            return 1;
    }
    
    addpoint();
    
    if(point < 14)  // pass
        return 0;
        
    esuit = getmax(getmax('S','H'),getmax('D','C'));
    return 2;
}
/**/
void output()
{
    if(!flg)
        printf("PASS\n");
    else if(flg == 1)
        printf("BID NO-TRUMP\n");
    else
        printf("BID %c\n",esuit);
}
/**/
void input()
{
    int i;
    while(scanf("%s",&a[0]) == 1)
    {
        for(i=1;i<13;i++)
            scanf("%s",&a[i]);
        khoitao();
        flg = solve();
        output();
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
