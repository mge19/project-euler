#include <bits/stdc++.h>
using namespace std;
int main()
{
	vector<int> v[2];
	long long int n[3][10][10][10][10],result=0;
	for(int i=0;i<3;i++)
	{
		for(int a=0;a<10;a++)
		{
			for(int b=0;b<10;b++)
			{
				for(int c=0;c<10;c++)
				{	
					for(int d=0;d<10;d++){n[i][a][b][c][d]=0;}
				}
			}		
		}
	}
	for(int a=0;a<10;a++)
	{
		for(int b=0;a+b<10;b++)
		{
			v[0].push_back(10*a+b);
			for(int c=0;a+b+c<10;c++){v[1].push_back(100*a+10*b+c);}
		}
	}
	for(int i=0;i<v[0].size();i++)
	{
		for(int j=0;j<v[1].size();j++)
		{
			int a=v[0][i]/10,b=v[0][i]%10,c=v[1][j]/100,d=(v[1][j]/10)%10,e=v[1][j]%10;
			if(a+b+c<10 && b+c+d<10){n[0][a][b][d][e]++;}
		}
	}
	for(int i=1;i<3;i++)
	{
		for(int a=0;a<10;a++)
		{
			for(int b=0;b<10;b++)
			{
				for(int c=0;c<10;c++)
				{
					for(int d=0;d<10;d++)
					{
						for(int e=0;e<10;e++)
						{
							for(int f=0;e+f<10;f++)
							{
								for(int g=0;e+f+g<10;g++)
								{
									for(int h=0;f+g+h<10;h++){n[i][a][b][c][d]+=n[i-1][a][b][e][f]*n[i-1][g][h][c][d];}
								}
							}					
						}
						if(i==2 && a!=0){result+=n[2][a][b][c][d];}						
					}					
				}			
			}			
		}
	}
	cout<<result;
	getchar();
	return 0;
}
