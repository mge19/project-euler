#include <bits/stdc++.h>
using namespace std;
int main()
{
	vector<long long int> powers;
	long long int x=1;
	do{
		powers.push_back(x);
		x=(x*1777)%100000000;
	}while(x!=1);
	long int n=powers[1777];
	for(int i=0;i<1853;i++)
	{
		n=powers[n%powers.size()];
	}
	cout<<n;
	getchar();
	return 0;
}
