/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <queue>
//#include <vector>
#include <map>

#define fi "390.inp"
#define fo "390.out"
/**/
using namespace std;
/**/
struct data{
                string str;
                int f;
            };
            
class sosanh{
public:
    bool operator()(data t1,data t2)    
    {
        if(t1.f < t2.f)
            return true;
        if(t1.f == t2.f)
            if(t1.str.compare(t2.str) > 0)
                return true;
        return false;
    }
};
map<string, int > mmap[6];
priority_queue<data, vector<data> , sosanh > pq;
char word[1000000];
/**/
void solve()
{
    int i,j,j1,l;
    int len;
    char tmp[7];
    
    len = strlen(word);
    
    for(i=0;i<len;i++)
        for(l=0;l<5;l++)
        {
            if(l + i >= len)
                break;
            if(word[i+l] >= 'A' && word[i+l] <= 'Z')
                tmp[l] = word[i+l];
            else if(word[i+l] >= 'a' && word[i+l] <= 'z')
                tmp[l] = word[i+l] - 32;
            else
                break;
            tmp[l+1] = 0;
            mmap[l+1][tmp]++;
        }
}
/**/
void report()
{
    int i,k;
    data t;
    
    map<string , int >::iterator j;
    
    for(i=1;i<6;i++)
    {
        for(j=mmap[i].begin();j!=mmap[i].end();j++)
        {
            t.str = j -> first;
            t.f = j -> second;
            pq.push(t);            
        }
        if(pq.empty())
            break;
        
        if(i != 1)
            printf("\n");
                
        printf("Analysis for Letter Sequences of Length %d\n",i);
        printf("-----------------------------------------\n");
        k = 0;
        while(!pq.empty() && k < 5)
        {
            t = pq.top();
            cout << "Frequency = "<< t.f <<", Sequence(s) = (" << t.str;
            k++;
            
            pq.pop();
            while(!pq.empty() && pq.top().f == t.f)
            {
                cout << "," << pq.top().str;
                pq.pop();
            }
            cout << ")" << endl;
        }
        while(!pq.empty())
            pq.pop();
    }
    
    for(i=1;i<6;i++)
        mmap[i].clear();
}
/**/
void input()
{
    int i;
    
    for(i=1;i<6;i++)
        mmap[i].clear();
        
    while(scanf("%s",&word) == 1)
        solve();
    report();
}
/**/
int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
    input();
    return 0;
}
