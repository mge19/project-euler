#include <bits/stdc++.h>
using namespace std;
int main()
{
	vector<long double> v1;
	v1.push_back(1);
	vector<vector<long double> > v(1000000,v1);
	unsigned long long int result=0;
	for(unsigned long long int i=1;i<=1000000;i++)
	{
		if(i>1 && v[i-1].size()==1)
		{
			for(long int j=i;j<=1000000;j+=i)
			{
				int x=v[j-1].size();
				for(int k=0;k<x;k++)
				{
					v[j-1].push_back(v[j-1][k]*i);
					v[j-1].push_back(v[j-1][k]*i*i);
				}
			}
		}
		for(int j=0;j<v[i-1].size();j++){result+=trunc(1000000000000000000/(i*i*i*v[i-1][j]));}
	}
	cout<<result;
	getchar();
	return 0;
}
