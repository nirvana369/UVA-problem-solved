/*
                                                        Hoang Linh
*/
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

#define fi "312.inp"
#define fo "312.out"
/**/
using namespace std;
/**/
struct toado{
                int x,y;
            };
toado h[4] = {-1,0,
                0,1,
                1,0,
                0,-1};
                
int a[30][30];
char out[200][200];
int nhang,ncot,maxhang,maxcot;
/**/
void dfs(int r, int c) 
{
    int i;
    
	if (r < 0 || r < 0 || r > nhang + 1 || c > ncot + 1) 
        return;

	if (a[r][c] != 1) 
        return;
        
    a[r][c] = 2;
    
	for(i=0;i<4;i++)
	   dfs(r+h[i].x, c+h[i].y);
}
/**/
void khoitao()
{
    int i,j;
    maxhang = 3 * nhang + 1;
    maxcot = 5 * ncot + 1;
    for(i=0;i<=maxhang;i++)
        for(j=0;j<=maxcot;j++)
            out[i][j] = ' ';
}
/**/
void input()
{
    int r,c,i,j;
    int dem;
    
    while(scanf("%d %d",&nhang,&ncot) == 2) 
    {
        
		if(!nhang && !ncot) 
            break;
            
        khoitao();
        
		for(i=1;i<=nhang;i++)
		{
            a[i][0] = a[i][ncot+1] = 1;
		    for(j=1;j<=ncot;j++)
			    scanf("%d", &a[i][j]);
        }
        
		for(j=0;j<=ncot+1;j++)
            a[0][j] = a[nhang+1][j] = 1;
		  
        dfs(0,0);
        
		dem = 1;

		for(r=1;r<=nhang;r++)
		  for(c=1;c<=ncot;c++) {
			if(a[r][c] == 1) 
            {
				for(i=0;i<4;i++)
				    for(j=0;j<6;j++)
					   out[3*r+i-3][5*c+j-5] = '+';
			}

		    if(a[r][c])
		      continue;

			for(i=0;i<4;i++)
				out[3*r+i-3][5*c-5] = out[3*r+i-3][5*c+5-5] = '+';
			for(j=0;j<6;j++)
				out[3*r-3][5*c+j-5] = out[3*r+3-3][5*c+j-5] = '+';

			if ((a[r-1][c] && !a[r+1][c]) || (a[r][c-1] && !a[r][c+1])) 
            {
				char s[10];
				sprintf(s,"%03d",dem++);
				for(i=0;i<3;i++)
					out[3*r+1-3][5*c+1+i-5] = s[i];
			}
		}

		for(i=0;i<maxhang;i++)
        {
            j = maxcot;
            while(out[i][j] == ' ')
                j--;
			out[i][j+1] = 0;
			printf("%s\n", out[i]);
		}
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
