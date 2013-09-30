/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
//#include <queue>
#include <vector>
//#include <map>

#define fi "10483.inp"
#define fo "10483.out"
#define maxgt 256000000
/**/
using namespace std;
/**/
int luu[4];
vector<int > a[1000];
int dau,cuoi;
bool match;
/**/
int getnum(char s[])
{
    int i;
    int val;
    
    val = 0;
    i = 0;
    while(s[i])
    {
        if(s[i] == '.')
        {
            i++;
            break;
        }
        val *= 10;
        val += s[i] - 48;
        i++;
    }
    while(s[i])
    {
        val *= 10;
        val += s[i] - 48;
        i++;
    }
    return val;
}
/**/
void op(int val)
{
    int i;
    printf("%d.%02d = ",val/100,val % 100);
    for(i=1;i<4;i++)
        if(!(i-1))
            printf("%d.%02d",luu[i]/100,luu[i]%100);
        else
            printf(" + %d.%02d",luu[i]/100,luu[i]%100);
    printf(" = ");
    for(i=1;i<4;i++)
        if(!(i-1))
            printf("%d.%02d",luu[i]/100,luu[i]%100);
        else
            printf(" * %d.%02d",luu[i]/100,luu[i]%100);
    printf("\n");
}
/**/
bool chk(int val)
{
    while(val != 1)
    {
        if(val % 10)
            return false;
        val /= 10;
    }
    return true;
}
/**/
void solve(long val)
{
    int i,j,k;
    int d;
    long sum,mul,nguyen,tmp;
    
    d = 0;
    tmp = val * 10000;
    for(i=1;i*i*i <= tmp && (i+i+i) <= val;i++)
        if(!(tmp % i))
            for(j=i;i*i*j<= tmp && (i+i+j) <= val;j++)
                if(!(tmp % j) && !(mul / (i*j)))
                {
                            k = mul / (i * j);
                            sum = i + j + k;
                            if(sum == val)
                            {
                                nguyen = mul / sum;
                                if(chk(nguyen))
                                {
                                    /*a[d].clear();
                                    a[d].push_back(i);
                                    a[d].push_back(j);
                                    a[d].push_back(k);*/
                                    luu[1] = i;
                                    luu[2] = j;
                                    luu[3] = k;
                                    mul /= nguyen;
                                    op(sum);
                                    d++;
                                    return;
                                }
                            }
                }
}
/**/
void input()
{
    char s1[10],s2[10];
    
    while(scanf("%s %s",&s1,&s2) == 2)
    {
        dau = getnum(s1);
        cuoi = getnum(s2);
        for(int i=1;i<=25600;i++)
            solve(i);
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
