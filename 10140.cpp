/*
                                Gamer : Nguyen Minh Duc
                                Quest : Prime distance
*/
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>
#include <string.h>

using namespace std;

#define fi "10140.inp"
#define fo "10140.out"

long dem;
long long l,u;
long long a[100000];
bool d[1000100];

void input();
void output();

void precal()
{
    int i,j;
    
    dem=0;
    
    for(i=2;i<=216;i++)
        if(d[i]==false)
        {
            if(i!=2)
            {
                a[dem]=i;
                dem++;
            }
            for(j=2;;j++)
            {
                if(i*j<=50000)
                    d[i*j]=true;
                else
                    break;
            }
        }
        
    for(i=216;i<=50000;i++)
        if(d[i]==false)
        {
            a[dem]=i;
            dem++;
        }
}

void solve()
{
    long i,j;
    long long minn,maxx,mina,minb,maxa,maxb,t,truoc,flag;
    
    for(i=0;i<=u-l+5;i++)
    {
        if(l+i!=2 && (l+i)%2==0 || l+i==1)
            d[i]=true;
        else
            d[i]=false;
    }
    
    for(i=0;i<dem;i++)
    {
        if(a[i]*a[i]>=u)
            break;
        t=l/a[i];
        while(a[i]*t<l || t<2)
            t++;
            
        for(j=t;;j++)
        {
            if(a[i]*j<=u)
                d[a[i]*j-l]=true;
            else
                break;
        }
    }
    
    truoc=-1;
    flag=0;
    minn=10000000;
    maxx=0;
    
    for(i=0;i<u-l+1;i++)
    {
        if(d[i]==false)
        {
            if(truoc==-1)
                truoc=i;
            else
            {
                if(i-truoc<minn)
                {
                    minn=i-truoc;
                    mina=truoc;
                    minb=i;
                }
                
                if(i-truoc>maxx)
                {
                    maxx=i-truoc;
                    maxa=truoc;
                    maxb=i;
                }
                
                truoc=i;
                flag=1;
            }
        }
    }
    
    if(flag==1)
        printf("%lld,%lld are closest, %lld,%lld are most distant.\n",mina+l,minb+l,maxa+l,maxb+l);
    else
        printf("There are no adjacent primes.\n");
}

void input()
{
    precal();
    while(scanf("%lld %lld",&l,&u)==2)
    {
        solve();
    }
}

int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);

    input();

    fclose(stdin);
    fclose(stdout);
    
    return 0;
}
