/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <vector>
#include <iostream>

#define fi "789.inp"
#define fo "789.out"
/**/
using namespace std;
/**/
map<string,int > mmap;
vector<int > a[32000];
char key;
int id;
/**/
char xuly(char s[])
{
    int i;
    i = 0;
    while(s[i])
    {
        if(s[i] >= 'A' && s[i] <= 'Z')
            return s[i];
        i++;
    }
    return 0;
}
/**/
void proc(int row,char s[])
{
    int i,j;
    int dem;
    char tmp[100];
    
    i = 0;
    dem = 0;
    while(s[i])
    {
        if(s[i] >= 'A' && s[i] <= 'Z')
            tmp[dem++] = s[i];
        else if(dem != 0)
        {
            tmp[dem] = 0;
            j = mmap[tmp];
            if(j)
               a[j].push_back(row); 
            else
            {
                j = id;
                mmap[tmp] = id++;
                a[j].push_back(0);
                a[j].push_back(row);
            }
            dem = 0;
        }
        i++;
    }
    
    if(dem != 0)
    {
        tmp[dem] = 0;
        j = mmap[tmp];
        if(j)
            a[j].push_back(row); 
        else
        {
            j = id;
            mmap[tmp] = id++;
            a[j].clear();
            a[j].push_back(0);
            a[j].push_back(row);
        }
        dem = 0;
    }
}
/**/
void solve()
{
    int j,k;
    bool tontai;
    
    map<string, int >::iterator i;
    string str;
    tontai = false;
    
    for(i=mmap.begin();i!=mmap.end();i++)
    {
        str = i -> first;
        if(key == str[0])
        {
            cout << str;
            k = i -> second;
            for(j=1;j<a[k].size();j++)
                if(a[k][j] != a[k][j-1])
                    cout << " " << a[k][j];
            printf("\n");
            tontai = true;
        }
    }
    if(!tontai)
        printf("\n");
}
/**/
void input()
{
    int i;
    char s[1001000];
    
    gets(s);
    key = xuly(s);
    mmap.clear();
    id = 1;
    i = 1;
    while(!feof(stdin))
    {
        gets(s);
        proc(i,s);
        i++;
    }
    solve();
}
/**/
int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    input();
    return 0;
}
