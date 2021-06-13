#include <bits/stdc++.h>
using namespace std;
int main()
{
	pair<int,long int> matrix[80][80];
	bool traversed[80][80];
	for(int i=0;i<80;i++)
	{
		for(int j=0;j<80;j++){traversed[i][j]=false;}
	}
	ifstream file("p083_matrix.txt");
	for(int i=0;i<80;i++)
	{
		for(int j=0;j<80;j++)
		{
			matrix[i][j].first=0;
			char x=file.get();
			while(!(x==',' || x=='\n' || file.eof()))
			{
				matrix[i][j].first=10*matrix[i][j].first+x-'0';
				x=file.get();
			}
			if(i==0 && j==0){matrix[i][j].second=matrix[i][j].first;}
			else{matrix[i][j].second=99999999;}
		}
	}
	file.close();
	int count=0,min_i=0,min_j=0;
	while(count<6400)
	{
		count++;
		traversed[min_i][min_j]=true;
		if(min_i>0 && matrix[min_i][min_j].second+matrix[min_i-1][min_j].first<matrix[min_i-1][min_j].second)
		{matrix[min_i-1][min_j].second=matrix[min_i][min_j].second+matrix[min_i-1][min_j].first;}
		if(min_i<79 && matrix[min_i][min_j].second+matrix[min_i+1][min_j].first<matrix[min_i+1][min_j].second)
		{matrix[min_i+1][min_j].second=matrix[min_i][min_j].second+matrix[min_i+1][min_j].first;}
		if(min_j>0 && matrix[min_i][min_j].second+matrix[min_i][min_j-1].first<matrix[min_i][min_j-1].second)
		{matrix[min_i][min_j-1].second=matrix[min_i][min_j].second+matrix[min_i][min_j-1].first;}
		if(min_j<79 && matrix[min_i][min_j].second+matrix[min_i][min_j+1].first<matrix[min_i][min_j+1].second)
		{matrix[min_i][min_j+1].second=matrix[min_i][min_j].second+matrix[min_i][min_j+1].first;}
		long int value=999999999;
		for(int i=0;i<80;i++)
		{
			for(int j=0;j<80;j++)
			{
				if(!traversed[i][j] && matrix[i][j].second<value)
				{
					value=matrix[i][j].second;
					min_i=i;
					min_j=j;
				}
			}
		}		
	}
	cout<<matrix[79][79].second;
	getchar();
	return 0;
}
