/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "11225.inp"
#define fo "11225.out"
/**/
using namespace std;
/**/
map <string,int > mmap;
int oud[5];
/**/
void _init()
{
    mmap.clear();
    mmap["fool"] = 4;
    mmap["twenty-one of trumps"] = 4;
    mmap["one of trumps"] = 4;
    mmap["king"] = 4;
    mmap["queen"] = 3;
    mmap["knight"] = 2;
    mmap["jack"] = 1;
    
    oud[0] = 56;
    oud[1] = 51;
    oud[2] = 41;
    oud[3] = 36;
}
/**/
int xuly(char s[])
{
    int i,j;
    int tmp;
    i = j = 0;
    while(s[i] == ' ')
        i++;

    while(s[i])
    {
        s[j++] = s[i++];
        if(s[i] == ' ') 
            break;
    }
    s[j] = 0;
    tmp = mmap[s];
    return tmp;
}
/**/
void input()
{
    int i;
    int ntest,n,id;
    int oudler,p,tmp,extra;
    char s[1000];
    
    _init();
    scanf("%d",&ntest);
    id = 1;
    while(ntest--)
    {
        scanf("%d",&n);
        gets(s);
        p = oudler = extra = 0;
        for(i=0;i<n;i++)
        {
            extra++;
            gets(s);
            tmp = mmap[s];
            if(!tmp)
                tmp = xuly(s);
            p += tmp;
            if(tmp == 4 && s[0] != 'k')
                ++oudler;
        }
        p += extra / 2;
        oudler = oud[oudler];
        printf("Hand #%d\n",id++);
        if(oudler > p)
            printf("Game lost by %d point(s).\n",oudler-p);
        else
            printf("Game won by %d point(s).\n",p-oudler);
        if(ntest)
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
