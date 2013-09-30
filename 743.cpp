/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "743.inp"
#define fo "743.out"
/**/
using namespace std;
/**/
string chk(string s)
{
    int i,j;
    int l;
    string s1;
    
    if(s[0] == 'N' || s == "")
        return "N";
        
    l = s.length();
    
    if(s[0] == '2')
    {
        i = 1;
        s1 = "";
        while(i < l)
            s1 += s[i++];
        if(s1 == "")    
            return "N";
        return s1;
    }
    
    if(s[0] == '3')
    {
        i = 1;
        s1 = "";
        while(i < l)
            s1 += s[i++];
        s = chk(s1);
        if(s == "")    
            return "N";
        return s + "2" + s;
    }
    return "N";
}
/**/
void input()
{
    string s;
    int i;
    int l;
    while(true)
    {
        cin >> s;
        l = s.length();
        if(l == 1 && s[0] == '0')
            break;
            
        for(i=0;i<l;i++)
            if(s[i] == '0')
            {
                s[0] = 'N';
                break;
            }
        s = chk(s);
        
        if(s[0] != 'N')
            cout << s << endl;
        else
            cout << "NOT ACCEPTABLE" << endl;
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
