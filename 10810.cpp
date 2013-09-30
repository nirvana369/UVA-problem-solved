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
#include <vector>

#define fi "10810.inp"
#define fo "10810.out"
/**/
using namespace std;
/**/
vector<long> a;
long n,xswap;
/**/
vector<long> merge_s(vector<long> arr)
{
    vector<long> l,r;
    long ileft,iright,mleft,mright,i;
    long mid;

    if(arr.size() <= 1)
        return arr;
    mid = arr.size() / 2;
    
    for(i=0;i<mid;i++)
        l.push_back(arr[i]);
        
    for(i=mid;i<arr.size();i++)
        r.push_back(arr[i]);
        
    l = merge_s(l);
    r = merge_s(r);
    
    ileft = 0;
    iright = 0;

    arr.clear();
    while(ileft < l.size() && iright < r.size())
    {
        if(l[ileft] < r[iright])
            arr.push_back(l[ileft++]);
        else
        {
            arr.push_back(r[iright++]);
            xswap += l.size() - ileft;
        }
    }
    
    while(ileft < l.size())
        arr.push_back(l[ileft++]);
    while(iright < r.size())
        arr.push_back(r[iright++]);
    return arr;
}
/**/
void input()
{
    long i;
    long val;
    while(scanf("%ld",&n))
    {
        if(!n)
            break;
        a.clear();
        for(i=0;i<n;i++)
        {
            scanf("%ld",&val);
            a.push_back(val);
        }
        xswap = 0;
        merge_s(a);
        printf("%ld\n",xswap);
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
