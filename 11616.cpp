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

#define fi "11616.inp"
#define fo "11616.out"
/**/
using namespace std;
/**/
int d[100];
char kq[1000];
int dkq;
/**/
void chuyenso(int value)
{
    int i;
    if(value < 10)
    {
        if(value < 4)
        {
            for(i=1;i<=value;i++)
                kq[dkq++] = 'I';
        }
        else if(value == 4)
        {
            kq[dkq++] = 'V';
            kq[dkq++] = 'I';
        }
        else if(value == 5)
            kq[dkq++] = 'V';
        else if(value < 9)
        {
            for(i=1;i<=value-5;i++)
                kq[dkq++] = 'I';
            kq[dkq++] = 'V';
        }
        else if(value == 9)
        {
            kq[dkq++] = 'X';
            kq[dkq++] = 'I';
        }
    }
    else if(value < 100)
    {
        if(value < 40)
        {
            for(i=10;i<=value;i+=10)
                kq[dkq++] = 'X';
        }
        else if(value == 40)
        {
            kq[dkq++] = 'L';
            kq[dkq++] = 'X';
        }
        else if(value == 50)
            kq[dkq++] = 'L';
        else if(value < 90)
        {
            for(i=10;i<=value-50;i+=10)
                kq[dkq++] = 'X';
            kq[dkq++] = 'L';
        }
        else if(value == 90)
        {
            kq[dkq++] = 'C';
            kq[dkq++] = 'X';
        }
    }
    else if(value < 1000)
    {
        if(value < 400)
        {
            for(i=100;i<=value;i+=100)
                kq[dkq++] = 'C';
        }
        else if(value == 400)
        {
            kq[dkq++] = 'D';
            kq[dkq++] = 'C';
        }
        else if(value == 500)
            kq[dkq++] = 'D';
        else if(value < 900)
        {
            for(i=100;i<=value-500;i+=100)
                kq[dkq++] = 'C';
            kq[dkq++] = 'D';
        }
        else if(value == 900)
        {
            kq[dkq++] = 'M';
            kq[dkq++] = 'C';
        }
    }
    else
    {
        for(i=1000;i<=value;i+=1000)
            kq[dkq++] = 'M';
    }
}
/**/
void xulyso(char s[])
{
    int i,j;
    int l;
    int gt;
    char temp;
    
    l = strlen(s);
    gt = 1;
    dkq = 0;
    for(i=l-1;i>=0;i--)
    {
        chuyenso((s[i]-48)*gt);
        gt *=10;
    }
    i = 0;
    j = dkq-1;
    while(i < j)
    {
        temp = kq[i];
        kq[i] = kq[j];
        kq[j] = temp;
        i++;
        j--;
    }
    kq[dkq] =  0;
    printf("%s\n",kq);
}
/**/
void xulykt(char s[])
{
    int i,j;
    int l;
    int number,value;
    
    l = strlen(s);
    number = 0;
    for(i=l-1;i>=0;i--)
    {
        value = d[s[i]];
        for(j=i-1;j>=0;j--)
            if(d[s[j]] > d[s[i]])
                break;
            else if(d[s[j]] == d[s[i]])
                value += d[s[j]];
            else
                value -=d[s[j]];
        i = j+1;
        number += value;
    }
    printf("%d\n",number);
}
/**/
void khoitao()
{
    d['I'] = 1;
    d['V'] = 5;
    d['X'] = 10;
    d['L'] = 50;
    d['C'] = 100;
    d['D'] = 500;
    d['M'] = 1000;
}
/**/
void input()
{
    char temp[1000];
    khoitao();
    while(true)
    {
        temp[0] = 0;
        scanf("%s",&temp);
        if(temp[0] == 0)
            break;
        if(temp[0] >= '1' && temp[0] <= '9')
            xulyso(temp);
        else
            xulykt(temp);
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
