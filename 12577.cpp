/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "12577.inp"
#define fo "12577.out"
/**/
using namespace std;
/**/
void input()
{
    int id;
    char s[100];
    map<string,string > mmap;
    mmap.clear();
    mmap["Hajj"] = "Hajj-e-Akbar";
    mmap["Umrah"] = "Hajj-e-Asghar";
    id = 1;
    while(true)
    {
        scanf("%s",&s);
        if(s[0] == '*')
            break;
        printf("Case %d: ",id++);
        cout << mmap[s] << endl;
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
