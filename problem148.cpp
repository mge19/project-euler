#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int a=1,c=1,result=0;
	long int b=1000000000;
	vector<int> base7;
	while(b>0)
	{
		auto it=base7.insert(base7.begin(),b%7);
		b/=7;
		c*=28;
	}
	c/=28;
	for(int i=0;i<base7.size();i++)
	{
		result+=a*c*base7[i]*(base7[i]+1)/2;
		a*=base7[i]+1;
		c/=28;
	}
	cout<<result;
	getchar();
	return 0;
}
