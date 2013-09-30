/*
                                                    Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <map>
#include <iostream>

#define fi "10282.inp"
#define fo "10282.out"
/**/
using namespace std;
/**/
struct dictionary{
                    char word[12],mes[12];
                 };
char mess[100010][12];
dictionary dic[1000010];
map <string,string> trans;
/**/
void input()
{
    char temp[1000],nofind[10];
    strcpy(nofind,"eh");
    long i,j,k;
    i = 0;
    while(true)
    {
        temp[0] = 0;
        gets(temp);
        if(temp[0] == 0)
            break;
        sscanf(temp,"%s %s",&dic[i].word,&dic[i].mes);
        i++;
    }
    j = 0;
    while(true)
    {
        mess[j][0] = 0;
        gets(mess[j]);    
        if(mess[j][0] == 0)
            break;
        trans[mess[j]] = nofind;
        j++;
    }
    for(k=0;k<i;k++)
        trans[dic[k].mes] = dic[k].word;
    for(k=0;k<j;k++)
        cout<<trans[mess[k]]<<endl;
}
/**/
int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    input();
    return 0;
}

