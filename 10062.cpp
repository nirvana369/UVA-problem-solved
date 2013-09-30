/*
                                                Hoang Linh
                                                
                                Problem: TELL ME THE FREQUENCIES! - 10062 (10062.*)
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10062.inp"
#define fo "10062.out"
/**/
using namespace std;
/**/
char kq[200];
int d[200];
int demkq;
/**/
bool kiemtra(char kt)
{
    int i;
    for(i=0;i<demkq;i++)
        if(kt == kq[i])
        {
            d[kt]++;
            return false;
        }
    return true;
}
/**/
void sapxep()
{
    int i,j;
    char temp;
    
    for(i=0;i<demkq-1;i++)
        for(j=i+1;j<demkq;j++)
            if(d[kq[i]] > d[kq[j]])
            {
                temp = kq[i];
                kq[i] = kq[j];
                kq[j] = temp;
            }
            else if(d[kq[i]] == d[kq[j]])
            {
                if(kq[i] < kq[j])
                {
                    temp = kq[i];
                    kq[i] = kq[j];
                    kq[j] = temp;
                }
            }
            
}
/**/
void output()
{
    int i;
    for(i=0;i<demkq;i++)
        printf("%d %d\n",kq[i],d[kq[i]]);
}
/**/
void xuly(char s[])
{
    int i;
    int l;
    
    demkq = 0;
    l = strlen(s);
    for(i=0;i<l;i++)
        if(kiemtra(s[i]))
        {
            kq[demkq] = s[i];
            d[s[i]] = 1;
            demkq++;
        }
    sapxep();
    output();    
}
/**/
void input()
{
    char temp[10000];
    int id;
    id = 1;
    while(!feof(stdin))
    {
        gets(temp);
        if(feof(stdin))
            break;
        if(id != 1)
            printf("\n");
        xuly(temp);
        id++;
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
