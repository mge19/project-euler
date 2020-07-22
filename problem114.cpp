#include <bits/stdc++.h>
using namespace std;
int main()
{
	vector<long long int> tiles(51,0); 
	for(int i=0;i<=50;i++)
	{
		if(i<3){tiles[i]=1;}
		else
		{
			tiles[i]+=tiles[i-1]+1;
			for(int j=3;j<i;j++){tiles[i]+=tiles[i-j-1];}
		}
	}
	cout<<tiles[50];
	getchar();
	return 0;
}
