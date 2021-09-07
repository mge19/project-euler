#include <bits/stdc++.h>
#define c 500000000
using namespace std;
int main()
{
	vector<long long int> relprime(c,1);
	long long int result=1;
	for(long long int i=3;i<=c;i+=2)
	{
		if(relprime[i-1]==1)
		{
			relprime[i-1]=i-1;
			for(long long int j=3*i;j<=c;relprime[j-1]*=i-1,j+=2*i){}
		}
	}
	for(long long int i=3;i<c;i+=2)
	{
		if(i*i<c && relprime[i-1]==i-1)
		{
			for(long long int j=i*i;j<=c;relprime[j-1]=i*relprime[j/i-1],j+=2*i*i){}
		}
		result+=relprime[i-1];
	}
	cout<<result;		
	getchar();
	return 0;
}
