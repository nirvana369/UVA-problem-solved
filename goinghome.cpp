#include<iostream>
#include<string>
#include<fstream>
#include<stdio.h>

#define fi "cominghome.inp"
#define fo "cominghome.out"
using namespace std;

void giai(void);
void hienkq(void);
void khoitri(void);
struct toado{
                int x,y;
            };
toado pr[110],pl[110];

int a[101][101];
int dtrai[101], dphai[101];
int trai[101], phai[101];
int fx[101], fy[101];
int tr[101];
int q[101];
int dau,cuoi;
int timduoc;
int xp,dich;
int ntrai,nphai;
int maxint=32767;

void xuly(int hang,char s[])
{
    int i;
    i = 0;
    while(s[i])
    {
        if(s[i] == 'm')
        {
            ++ntrai;
            a[hang][i] = ntrai;
            pl[ntrai].x = hang+1;
            pl[ntrai].y = i+1;
        }
        if(s[i] == 'H')
        {
            ++nphai;
            a[hang][i] = nphai;
            pr[nphai].x = hang+1;
            pr[nphai].y = i+1;
        }
        i++;
    }
}
int _abs(int val)
{
    if(val < 0)
        return -val;
    return val;
}
void docf()
{
	
	int i,j;
	int kc;
	int nhang,ncot;
	char s[110][110];
	while(true)
	{
    	scanf("%d %d",&nhang,&ncot);
    	if(!nhang && !ncot)
    	   break;
    	gets(s[0]);
    	ntrai = 0;
    	nphai = 0;
    	for(i=0;i<nhang;i++)
    	{
            gets(s[i]);
            xuly(i,s[i]);
        }
    	/////////////
    	for (i=1; i<=ntrai;i++)
    		for (j=1; j<=nphai; j++)
    			a[i][j]=maxint;
    			
    	for (i=1; i<=ntrai;i++)
    		for (j=1; j<=nphai; j++)
    		{
                kc = _abs(pl[i].x -pr[j].x) + _abs(pl[i].y - pr[j].y);
    			a[i][j]=kc;
            }
    	khoitri();
    	giai();
    	hienkq();
    }
}

void khoitri()
{
	int i,j;
	int min;


	for (i=1; i<=ntrai; i++)
	{
		fx[i]=0;
		dtrai[i]=0;
		phai[i]=0;
	}
	for (j=1; j<=nphai; j++)
	{
		fy[j]=0;
		dphai[j]=0;
		trai[j]=0;
	}

	for (i=1; i<=ntrai; i++)
	{
		min=maxint;
		for (j=1; j<=nphai; j++)
		{
			if (min > a[i][j])
				min = a[i][j];
		}
		fx[i]=min;
	}
}

bool lacanh(int i, int j)
{
	if (a[i][j] == fx[i] + fy[j])
		return true;
	else
		return false;
}
void timduong()
{
	int i,j;

	for (i=0; i<101; i++)
		q[i]=0;
	for (i=0; i<=ntrai; i++)
		dtrai[i]=0;
	for (j=0; j<=nphai; j++)
		dphai[j]=0;

	dau=-1;
	cuoi=0;
	q[0]=xp;
	while (dau<cuoi)
	{
		dau++;
		i=q[dau];
		dtrai[i]=1;
		for (j=1; j<=nphai; j++)
		{
			if (dphai[j]==0 && lacanh(i,j))
			{
				tr[j]=i;
				dphai[j]=1;
				if (trai[j]==0)
				{
					dich=j;
					timduoc=1;
					return;
				}
				else
				{
					cuoi++;
					q[cuoi]=trai[j];
					
				}
			}
		}
	}
}

void suanhan()
{
	int i,j,min;

	min=maxint;
	for (i=1; i<=ntrai; i++)
		if (dtrai[i]==1)
		{
			for (j=1; j<=nphai; j++)
				if (dphai[j]==0)
				{
					if (min > a[i][j] - fx[i] - fy[j])
					{
						min = a[i][j] - fx[i] - fy[j];
					}
				}
		}
	for (i=1; i<=ntrai; i++)
		if (dtrai[i]==1)
			fx[i] = fx[i]+min;
	for (j=1; j<=nphai; j++)
		if (dphai[j]==1)
			fy[j] = fy[j]-min;
}

void tangduong()
{
	int i,j,tg;

	j=dich;
	do
	{
		i=tr[j];
		tg=phai[i];
		phai[i]=j;
		trai[j]=i;
		j=tg;
	}
	while (i!=xp);
}

void giai()
{

	for (xp=1; xp<=ntrai; xp++)
	{
		timduoc=0;
		while (timduoc==0)
		{
			timduong();
			if (timduoc==0)
				suanhan();
		}
		tangduong();
	}
}

void hienkq()
{
	int i;
	long t;

	t=0;
	for (i=1; i<=ntrai; i++)
		t=t + a[i][phai[i]];
	cout << t;
	cout << endl;
}

int main()
{
    freopen(fi,"r",stdin);
    freopen(fo,"w",stdout);
	docf();
	return 0;
}
