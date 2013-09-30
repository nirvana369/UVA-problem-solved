/*
                                                                    Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10226.inp"
#define fo "10226.out"
/**/
using namespace std;
/**/
map <string, int> mmap;
/**/
void input()
{
    char temp[50];
    int ntest;
    long id;
    double tile;
    
    scanf("%d",&ntest);
    gets(temp);
    gets(temp);
    
    map <string, int>::iterator i;
    
    cout.setf(ios::fixed);
    cout.precision(4);
    
    while(ntest--)
    {
        mmap.clear();
        id = 0;
        while(true)
        {
            temp[0] = 0;
            gets(temp);
            if(temp[0] == 0)
                break;
            mmap[temp]++;
            id++;
        }
            
        tile = (double)100 / id;
        
        for(i=mmap.begin();i!=mmap.end();i++)
            cout << i->first << " " << i->second * tile << endl;
            
        if(ntest != 0)
            printf("\n");
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
