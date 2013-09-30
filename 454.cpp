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

#define fi "454.inp"
#define fo "454.out"
/**/
using namespace std;
/**/
struct str{
            string s;
            };
class sosanh{
public:
    bool operator()(string s1,string s2){
        if(s1.compare(s2) > 0)
            return true;
        return false;
    }    
};
priority_queue <string, vector <string>, sosanh > pq;
str a[110];
int da;
/**/
bool kiemtra(int i1,int i2)
{
    int i,j;
    char temp[100];
    bool find;
    
    i = 0;
    while(a[i2].s[i] != 0)
    {
        temp[i] = a[i2].s[i];
        i++;
    }
    temp[i] = 0;
    
    i = 0;
    while(a[i1].s[i] != 0)
    {
        j = 0;
        find = false;
        if(a[i1].s[i] != ' ')
        {
            while(temp[j] != 0)    
            {
                if(a[i1].s[i] == temp[j])
                {
                    find = true;
                    temp[j] = ' ';
                    break;
                }
                j++;
            }
            if(!find)
                return find;
        }
        i++;
    }
    
    i = 0;
    while(temp[i] != 0)
    {
        if(temp[i] != ' ')
            return false;
        i++;
    }
    return true;
}
/**/
void solve()
{
    int i,j;
    while(!pq.empty())
    {
        a[da].s = pq.top();
        da++;
        pq.pop();
    }
    for(i=0;i<da-1;i++)
    {
        for(j=i+1;j<da;j++)
            if(kiemtra(i,j))
                cout << a[i].s << " = " << a[j].s << endl;
    }
}
/**/
void input()
{
    char s1[100];
    int ntest;
    scanf("%d",&ntest);
    gets(s1);
    gets(s1);
    while(ntest--)
    {
        da = 0;
        while(true)
        {
            s1[0] = 0;
            gets(s1);
            if(!s1[0])
                break;
            pq.push(s1);
        }
        solve();
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
