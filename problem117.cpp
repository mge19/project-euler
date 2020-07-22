#include <bits/stdc++.h>
using namespace std;
int main()
{
	vector<long long int> tiles(51,0);
	tiles[0]=1;
	for(int i=1;i<=50;i++)
	{
		tiles[i]+=tiles[i-1];
		if(i>=2){tiles[i]+=tiles[i-2];}
		if(i>=3){tiles[i]+=tiles[i-3];}
		if(i>=4){tiles[i]+=tiles[i-4];}
	}
	cout<<tiles[50];
	getchar();
	return 0;
}
