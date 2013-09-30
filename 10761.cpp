/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "10761.inp"
#define fo "10761.out"
/**/
using namespace std;
/**/
char s[1000];
bool d[30];
/**/
void khoitao()
{
    int i;
    for(i=0;i<27;i++)
        d[i] = false;
    i = 0;
    while(s[i])
    {
        if(s[i] >= 'A' && s[i] <= 'Z')
            s[i] += 32;
        if(isalpha(s[i]))
            d[s[i] - 97] = true;
        i++;
    }
}
/**/
bool chk(char kt)
{
    int i;
    i = 0;
    while(s[i])
    {
        if(s[i] == kt)
            return true;
        i++;
    }
    return false;
}
/**/
void out()
{
    int i,j;
    char s1[100];
    for(i=0;i<28;i++)
        s1[i] = ' ';
    s1[28] = 0;
    for(i=0,j=0;i<26;i++)
        if(!d[i])
            s1[j++] = i + 97;
    printf("%s",s1);
    printf("|\n+----------+----------------+-----------------------------+\n");
}
void input()
{
    int i;
    int id,line;
    char s1[1000];
    bool broken,quit;
    
    id = 1;
    printf("+----------+----------------+-----------------------------+\n");
    printf("| Keyboard | # of printable | Additionally, the following |\n");
    printf("|          |      lines     |  letter keys can be broken  |\n");
    printf("+----------+----------------+-----------------------------+\n");
    while(true)
    {
        scanf("%s",&s);
        gets(s1);
        if(strcmp(s,"finish") == 0)
            break;
        khoitao();
        line = 0;
        quit = false;
        while(!quit)
        {
            gets(s1);
            if(strcmp(s1,"END") == 0)
                quit = true;
            broken = false;
            i = 0;
            while(s1[i])
            {
                if(isalpha(s1[i]))
                {
                    if(s1[i] >= 'A' && s1[i] <= 'Z')
                        s1[i] += 32;
                    broken = chk(s1[i]);
                }
                if(broken)
                    break;
                i++;
            }
            if(!broken)
            {
                line++;
                i = 0;
                while(s1[i])
                {
                    if(isalpha(s1[i]))
                        d[s1[i]-97] = true;
                    i++;
                }
            }
        }
        printf ("|   %3d    |      %3d       | ",id++,line);
        out();
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
