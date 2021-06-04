#include <bits/stdc++.h>
using namespace std;
int main()
{
	vector<long int> solutions(49999999,0);
	long int result=0;
	for(long int z=1;z<50000000;z++)
	{
		for(long int k=(z/3)+1;(3*k-z)*(k+z)<50000000;solutions[(3*k-z)*(k+z)-1]++,k++){}
	}
	for(long int i=0;i<49999999;result+=(solutions[i]==1),i++){}
	cout<<result;
	getchar();
	return 0;
}
