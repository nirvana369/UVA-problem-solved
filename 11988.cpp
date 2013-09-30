/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <vector>

#define fi "11988.inp"
#define fo "11988.out"
/**/
using namespace std;
/**/
vector<char> wr[100100];
char text[100100];
long id;
/**/
void output()
{
    long i,j;
    
    for(i=id;i>=0;i--)
        for(j=0;j<wr[i].size();j++)
            cout << wr[i][j];
    printf("%s\n",text);
}
/**/
void input()
{
    long i,j,k;
    int flg;
    char s[100100];
    
    while(gets(s))
    {
        i = 0;
        flg = 0;
        id = 0;
        wr[id].clear();
        k = 0;
        while(s[i])
        {
            if(s[i] == '[')
            {
                if(wr[id].size())
                {
                    id++;
                    wr[id].clear();
                }
                flg = 1;
            }
            else if(s[i] == ']')
                flg = 0;
            else
            {
                if(flg)
                    wr[id].push_back(s[i]);
                else
                    text[k++] = s[i];
            }
            i++;
        }
        text[k] = 0;
        if(!wr[id].size())
            id--;
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
