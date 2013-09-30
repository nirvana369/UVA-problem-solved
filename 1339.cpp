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

#define fi "1339.inp"
#define fo "1339.out"
/**/
using namespace std;
/**/
int c1,c2;
int arr1[110],arr2[110],da[30],db[30];
char a[110],b[110];
/**/
void khoitao()
{
    int i;
    for(i=0;i<26;i++)
        da[i] = db[i] = 0;
}
/**/
bool sapxep()
{
    int i,j;
    int temp;
    
    for(i=0;i<c1;i++)
    {
        for(j=i+1;j<c1;j++)
        {
            if(arr1[i] > arr1[j])
            {
                temp = arr1[i];
                arr1[i] = arr1[j];
                arr1[j] = temp;
            }
            
            if(arr2[i] > arr2[j])
            {
                temp = arr2[i];
                arr2[i] = arr2[j];
                arr2[j] = temp;
            }
        }
        if(arr1[i] != arr2[i])
            return true;
    }
    return false;
}
/**/
void solve()
{
    int i;
    bool diff;
    
    i = 0;
    while(a[i] != 0)
    {
        da[a[i] - 'A']++;
        db[b[i] - 'A']++;
        i++;
    }
    
    c1 = c2 = 0;
    
    for(i=0;i<26;i++)
    {
        if(da[i] != 0)
            arr1[c1++] = da[i];
            
        if(db[i] != 0)
            arr2[c2++] = db[i];
    }
    if(c1 != c2)
        diff = true;
    else
        diff = sapxep();
        
    if(diff)
        printf("NO\n");
    else
        printf("YES\n");
}
/**/
void input()
{
    while(gets(a))
    {
        gets(b);
        khoitao();
        solve();
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
