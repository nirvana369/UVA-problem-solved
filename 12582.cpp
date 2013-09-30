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
#include <stack>

#define fi "12582.inp"
#define fo "12582.out"
/**/
using namespace std;
/**/
int d[200];
char s[1000000];
long vt;
/**/
void khoitao()
{
    int i;
    
    for(i='A';i<='Z';i++)
        d[i] = 0;
}
/**/
void output(int id)
{
    int i;
    
    printf("Case %d\n",id);
    for(i='A';i<='Z';i++)
        if(d[i])
            printf("%c = %d\n",i,d[i]);
}
/**/
void input()
{
    int ntest,id;
    long i;
    stack<char > st;
    id = 1;
    scanf("%d",&ntest);
    while(ntest--)
    {
        scanf("%s",&s);
        khoitao();
        
        i = 0;
        st.push(s[i++]);
        while(s[i])
        {
            if(s[i] == st.top())
                st.pop();
            else
            {
                d[st.top()]++;
                
                st.push(s[i]);
                
                d[st.top()]++;
            }
            i++;
        }
        output(id++);
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
