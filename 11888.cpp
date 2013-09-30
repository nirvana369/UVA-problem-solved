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

#define fi "11888.inp"
#define fo "11888.out"
/**/
using namespace std;
/**/
char s[200100];
bool kt(long dau,long cuoi)
{
    if(dau > cuoi)
        return false;
        
    while(dau < cuoi)
    {
        if(s[dau] != s[cuoi])
            return false;
        dau++;
        cuoi--;
    }
    return true;
}
/**/
void input()
{
    int ntest;
    bool palin,alin1,alin2;
    long i;
    long l;
    
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%s",&s);
        l = strlen(s)-1;
        palin = kt(0,l);
        alin1 = alin2 = false;
        for(i=0;i<=l;i++)
        {
            if(i+1 <= l && s[0] == s[i] && s[i+1] == s[l])
            {
                alin1 = kt(0,i);
                if(!alin1)
                    continue;
                alin2 = kt(i+1,l);
                if(alin1 && alin2)
                    break;
            }
        }
        if(alin1 && alin2)
            printf("alindrome\n");
        else if(palin)
            printf("palindrome\n");
        else
            printf("simple\n");
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
