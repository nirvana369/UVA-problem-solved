!!!!!!!!!!!!!!!!!!!!!!
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10223.inp"
#define fo "10223.out"
/**/
using namespace std;
/**/
long long n;
bool f;
/**/
void tree(long long id,long bac)
{
    if(id == n)
    {
        f = true;
        printf("%ld\n",bac);
        return;
    }
    else if(id > n)
        return;
    tree(id*2,bac+1);
    if(f)
        return;
    tree(id*2+1,bac+1);
}
/**/
void input()
{
    while(true)
    {
        n = 0;
        scanf("%lld",&n);
        if(!n)
            break;
        f = false;
        tree(1,1);
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
