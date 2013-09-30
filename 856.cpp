/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
//#include <queue>
#include <vector>
//#include <map>

#define fi "856.inp"
#define fo "856.out"
/**/
using namespace std;
/**/
vector<string > de;
char num[11][10];
/**/
void dfs(int id,string tmp)
{
    int i;
    string tg;
    
    if(id == 3)
    {
        de.push_back(tmp);
        return;
    }
    
    for(i=0;i<10;i++)
        dfs(id+1,tmp+num[i]);
}
/**/
void _init()
{
    strcpy(num[0],"nine");
    strcpy(num[1],"eight");
    strcpy(num[2],"seven");
    strcpy(num[3],"six");
    strcpy(num[4],"five");
    strcpy(num[5],"four");
    strcpy(num[6],"three");
    strcpy(num[7],"two");
    strcpy(num[8],"one");
    strcpy(num[9],"zero");
    
    dfs(0,"");
}
/**/
void decode(char x,char y)
{
    printf("%c",((('z' - x) + (y - 'A')) % 26 + 'A'));
}
/**/
void input()
{
    int i,j;
    char s[10000];
    int len;
    bool fst;
     
    _init();   
    fst = true;
    while(gets(s))
    {
        if(fst)
            fst = false;
        else
            printf("\n");
            
        len = strlen(s);
        for(i=0;i<de.size();i++) 
        {
            if(de[i].size() == len)
            {
                for(j=0;j<de[i].size();j++) 
                    decode(de[i][j],s[j]);
                cout << " -> " << de[i] << endl;
            }
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
