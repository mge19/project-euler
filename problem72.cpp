#include <bits/stdc++.h>
using namespace std;
int main()
{
	vector<long int> relprime(1000000,1);
	long long int result=0;
	for(long int i=2;i<=1000000;i++)
	{
		if(relprime[i-1]==1)
		{
			relprime[i-1]=i-1;
			for(long int j=2*i;j<1000000;relprime[j-1]*=i-1,j+=i){}	
		}                   		
	}
	for(int i=2;i*i<=1000000;i++)
	{
		if(relprime[i-1]==i-1)
		{
			for(long int j=i*i;j<=1000000;relprime[j-1]=i*relprime[j/i-1],j+=i*i){}
		}
	}
	for(long int i=2;i<=1000000;result+=relprime[i-1],i++){}
	cout<<result;
	getchar();
	return 0;
}
