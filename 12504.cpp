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
#include <vector>

#define fi "12504.inp"
#define fo "12504.out"
/**/
using namespace std;
/**/
map <string, string> dic1,dic2;
map <string, int> mmap;
/**/
void xuly(char s[],int id)
{
    int i;
    int flg,dem;
    char s1[100],s2[100];
    
    dem = 0;
    flg = 0;
    i = 0;
    
    while(s[i])
    {
        if(s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9')
        {
            if(!flg)
                s1[dem++] = s[i];
            else
                s2[dem++] = s[i];
        }
        else if(dem != 0)
        {
            if(!flg)
            {
                s1[dem] = 0;
                flg = 1;
            }
            else
            {
                s2[dem] = 0;
                flg = 0;
                if(id == 1)
                {
                    dic1[s1] = s2;
                    mmap[s1]++;
                }
                else
                {
                    dic2[s1] = s2;
                    mmap[s1]++;
                }
            }
            dem = 0;
        }
        i++;
    }
}
/**/
void solve()
{
    int change;
    int _1st;
    
    map<string,string>::iterator i;
    change = 0;
    _1st = 0;
    
    for(i=dic2.begin();i!=dic2.end();i++)
        if(mmap[i->first] == 1)    
        {
            if(!_1st)
                cout << "+";
            else
                cout << ",";
                
            cout << i->first;
            
            _1st++;
            change = 1;
        }
        
    if(change == 1)
        cout << endl;
        
    _1st = 0;
    for(i=dic1.begin();i!=dic1.end();i++)
        if(mmap[i->first] == 1)    
        {
            if(!_1st)
                cout << "-";
            else
                cout << ",";
                
            cout << i->first;
            
            _1st++;
            change = 2;
        }
        
    if(change == 2)
        cout << endl;
        
    _1st = 0;
    for(i=dic1.begin();i!=dic1.end();i++)
        if(mmap[i->first] == 2) 
            if(dic1[i->first] != dic2[i->first])
            {
                if(!_1st)
                    cout << "*";
                else
                    cout << ",";
                
                cout << i->first;
                
                _1st++;
                change = 3;
            }
            
    if(change == 3)
        cout << endl;        
        
    if(change == 0)
        cout << "No changes" << endl;
    
    cout << endl;
}
/**/
void input()
{
    char s[10000];
    int ntest;
    scanf("%d",&ntest);
    gets(s);
    while(ntest--)
    {
        dic1.clear();
        dic2.clear();
        mmap.clear();
        gets(s);
        xuly(s,1);
        gets(s);
        xuly(s,2);
        solve();
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
