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

//#define fi "kmp.inp"
//#define fo "kmp.out"
#define MAX 100
/**/
using namespace std;
/**/
int KMP(char *source, char *find)
{
    int next[MAX], i = 0, len, j=-1, lensource;
   
    len = strlen(find);
    lensource = strlen(source);
    next[0] = -1;
    
    do {
    
      if (j == -1 || find[i] == find[j])
      {
        i++;
        j++;
        next[i] = j;
      }
      else
        j = next[j];
    
    }while (i < len-1);
    
    i = j = 0;
    
    do {
    
      if (j==0 || source[i] == find[j])
      {
        i++;
        j++;
      }
      else
        j = next[j];
    
    } while (j<len && i<lensource);
    
    if (j>=len)
      return i-len;
    else
      return -1;
}
/**/
void input()
{
    char a[1000],b[1000];
    strcpy(a,"luffy1234nami");
    strcpy(b,"1234");
    KMP(a,b);
}
/**/
int main()
{
    //freopen(fi,"r",stdin);
    //freopen(fo,"w",stdout);
    
    input();

    return 0;
}
