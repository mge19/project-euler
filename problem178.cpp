#include <bits/stdc++.h>
using namespace std;
int main()
{
	vector<long long int> step[40][10][10];
	long long int result=0;
	int b=1;
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			for(int k=0;k<1024;k++)
			{
				if(i==j && k==b){step[0][i][j].push_back(1);}
				else{step[0][i][j].push_back(0);}
			}
		}
		b*=2;
	}
	for(int i=1;i<40;i++)
	{
		int x=(i%2==0)?(i-2)/2:(i-1)/2,y=(i%2==0)?i/2:(i-1)/2;
		for(int j=0;j<10;j++)
		{
			for(int k=0;k<10;k++)
			{
				for(int a=0;a<1024;a++){step[i][j][k].push_back(0);}
				for(int a=0;a<10;a++)
				{
					if(a!=0)
					{
						vector<int> v1,v2;
						for(int c=0;c<1024;c++)	
						{
							if(step[x][j][a][c]>0){v1.push_back(c);}
							if(step[y][a-1][k][c]>0){v2.push_back(c);}
						}	
						for(int c=0;c<v1.size();c++)
						{
							for(int d=0;d<v2.size();d++){step[i][j][k][v1[c] | v2[d]]+=step[x][j][a][v1[c]]*step[y][a-1][k][v2[d]];}
						}
					}
					if(a!=9)
					{
						vector<int> v1,v2;
						for(int c=0;c<1024;c++)	
						{
							if(step[x][j][a][c]>0){v1.push_back(c);}
							if(step[y][a+1][k][c]>0){v2.push_back(c);}
						}	
						for(int c=0;c<v1.size();c++)
						{
							for(int d=0;d<v2.size();d++){step[i][j][k][v1[c] | v2[d]]+=step[x][j][a][v1[c]]*step[y][a+1][k][v2[d]];}
						}						
					}
				}
				if(j!=0){result+=step[i][j][k][1023];}
			}
		}
	}
	cout<<result;
	getchar();
	return 0;
}
