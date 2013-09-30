/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <queue>
#include <iostream>

#define fi "1254.inp"
#define fo "1254.out"
/**/
using namespace std;
/**/
struct word{
                string str;
                int id;
                int l;
            };
            
class sosanh{
public:
    bool operator()(word s1,word s2)
    {
        int tmp;
        if(s1.l > s2.l)
            return true;
        else if(s1.l == s2.l)
        {
            tmp = s1.str.compare(s2.str);
            if(tmp > 0)
                return true;
            else if(tmp == 0)
                if(s1.id > s2.id)
                    return true;
        }
        return false;
    }                
};
word dic[20010];
priority_queue<word, vector<word>, sosanh > pq;
/**/
bool chk(string s,string s1)
{
    int i,j,k;
    i = 0;
    while(s1[i])
    {
        if(s1[i] == s[0])
        {
            j = 0;
            k = i;
            while(s[j] && s1[k])
            {
                if(s[j] != s1[k])
                    break;
                j++;
                k++;
            }
            if(!s[j])
                return true;
        }
        i++;
    }
    return false;
}
/**/
void input()
{
    word tmp;
    int i,j,k;
    int pos;
    int n;
    long m;
    string s;
    scanf("%d",&n);
    
    while(!pq.empty())
        pq.pop();
    
    for(i=1;i<=n;i++)
    {
        cin >> tmp.str;
        tmp.l = tmp.str.length();
        tmp.id = i;
        pq.push(tmp);
    }
    i = 1;
    while(!pq.empty())
    {
        dic[i] = pq.top();
        pq.pop();
        i++;
    }
    scanf("%ld",&m);
    
    for(i=0;i<m;i++)
    {
        cin >> s;
        k = 0;
        for(j=1;j<=n;j++)
        {
            pos = dic[j].str.find(s);
            if(pos != -1)
            {
                if(!k)   
                    printf("%d",dic[j].id);
                else
                    printf(" %d",dic[j].id);
                k++;
                if(k == 10)
                    break;
            }
        }
        if(!k)
            printf("-1");
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
