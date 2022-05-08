#include <bits/stdc++.h>
using namespace std;
class Grid{
	public:
		int numbers[4][4];
};
int main()
{
	map<int,vector<int> > sum4,sum2;
	long long int result=0;
	for(int i=0;i<10000;i++)
	{
		int a=i/1000,b=(i/100)%10,c=(i/10)%10,d=i%10;
		sum4[a+b+c+d].push_back(i);
		if(i<100){sum2[c+d].push_back(10*c+d);}
	}
	for(int i=0;i<=36;i++)
	{
		for(int j=0;j<sum4[i].size();j++)
		{
			for(int k=0;k<sum4[i].size();k++)
			{
				int v0[4]={sum4[i][j]/1000,(sum4[i][j]/100)%10,(sum4[i][j]/10)%10,sum4[i][j]%10},
				v3[4]={sum4[i][k]/1000,(sum4[i][k]/100)%10,(sum4[i][k]/10)%10,sum4[i][k]%10};
				if(v0[0]+v3[0]<=i && v0[1]+v3[1]<=i && v0[2]+v3[2]<=i && v0[3]+v3[3]<=i && v0[0]+v3[3]<=i && v0[3]+v3[0]<=i)
				{
					queue<Grid> q;
					Grid g;
					for(int a=0;a<4;a++)
					{
						g.numbers[0][a]=v0[a];
						g.numbers[3][a]=v3[a];
					}
					vector<int> x=sum2[i-g.numbers[0][3]-g.numbers[3][0]];
					for(int a=0;a<x.size();a++)
					{
						g.numbers[1][2]=x[a]/10;
						g.numbers[2][1]=x[a]%10;
						g.numbers[2][2]=i-g.numbers[0][2]-g.numbers[1][2]-g.numbers[3][2];
						g.numbers[1][1]=i-g.numbers[0][1]-g.numbers[2][1]-g.numbers[3][1];
						if(g.numbers[0][0]+g.numbers[1][1]+g.numbers[2][2]+g.numbers[3][3]==i && 
						g.numbers[1][1]+g.numbers[1][2]<=i && g.numbers[2][1]+g.numbers[2][2]<=i &&
						g.numbers[2][2]>=0 && g.numbers[1][1]>=0 && g.numbers[2][2]<10 && g.numbers[1][1]<10)
						{q.push(g);}
					}
					while(!q.empty())
					{
						g=q.front();
						q.pop();
						vector<int> y=sum2[i-g.numbers[1][1]-g.numbers[1][2]];
						for(int a=0;a<y.size();a++)
						{
							g.numbers[1][0]=y[a]/10;
							g.numbers[1][3]=y[a]%10;
							g.numbers[2][0]=i-g.numbers[0][0]-g.numbers[1][0]-g.numbers[3][0];
							g.numbers[2][3]=i-g.numbers[0][3]-g.numbers[1][3]-g.numbers[3][3];
							if(g.numbers[2][0]+g.numbers[2][1]+g.numbers[2][2]+g.numbers[2][3]==i 
							&& g.numbers[2][0]>=0 && g.numbers[2][3]>=0 && g.numbers[2][0]<10 && g.numbers[2][3]<10){result++;}
						}
					}
				}
			}
		}
	}
	cout<<result;
	getchar();
	return 0;
}
