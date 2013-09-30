/*
                                                            Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "12250.inp"
#define fo "12250.out"
/**/
using namespace std;
/**/
map <string, string> mmap;
/**/
void khoitao()
{
    mmap.clear();
    mmap["HELLO"] = "ENGLISH";
    mmap["HOLA"] = "SPANISH";
    mmap["HALLO"] = "GERMAN";
    mmap["BONJOUR"] = "FRENCH";
    mmap["CIAO"] = "ITALIAN";
    mmap["ZDRAVSTVUJTE"] = "RUSSIAN";
}
/**/
void input()
{
    khoitao();
    int id;
    char temp[20];
    id = 1;
    while(true)
    {
        gets(temp);
        if(strcmp(temp,"#") == 0)
            break;
        printf("Case %d: ",id++);
        if(mmap[temp] != "")
            cout<< mmap[temp] << endl;
        else
            printf("UNKNOWN\n");
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
