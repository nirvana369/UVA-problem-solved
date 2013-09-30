/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
//#include <queue>
//#include <vector>
//#include <map>

#define fi "11660.inp"
#define fo "11660.out"
/**/
using namespace std;
/**/
string s[1100];
/**/
void input()
{
    int i,j,i1,j1,k;
    int id,vt,len;
    long dem;
    char tmp[10000];
    while(1)
    {
        cin >> s[0] >> id >> vt;
        len = s[0].length();
        if(len == 1 && s[0][0] == '0' && !id && !vt)
            break;
        
        for(k=0;k<id;k++)
        {
            s[k+1] = "";
            i = 0;
            while(s[k][i] && i <= vt)
            {
                j = i+1;
                dem = 1;
                while(s[k][j] && s[k][j] == s[k][i])
                {
                    dem++;
                    j++;
                }
                sprintf(tmp,"%ld",dem);
                
                s[k+1] += tmp;
                    
                s[k+1] += s[k][i];
                i = j;
            }
        }
        printf("%c\n",s[id-1][vt-1]);
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
