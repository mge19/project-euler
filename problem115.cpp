#include <bits/stdc++.h>
using namespace std;
int main()
{
	long int s=1;
	vector<long int> tiles;
	int i=0;
	for(;s<1000000;i++)
	{
		if(i<50){s=1;}
		else
		{
			s=tiles[i-1]+1;
			for(int j=50;j<i;j++){s+=tiles[i-j-1];}
		}
		tiles.push_back(s);
	}
	cout<<i-1;
	getchar();
	return 0;
}
