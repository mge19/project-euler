#include <bits/stdc++.h>
using namespace std;
int main()
{
	vector<unsigned long long int> sums(64000000,1);
	long int result=1;
	for(unsigned long long int x=2;x<=64000000;x++)
	{
		for(long int y=x;y<=64000000;sums[y-1]+=x*x,y+=x){}
		if(round(sqrt(sums[x-1]))==sqrt(sums[x-1])){result+=x;}
	}
	cout<<result;
	getchar();
	return 0;
}
