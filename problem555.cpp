#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int result=0;
	for(long long int i=1;i<=500000;i++)
	{
		long long int s=(1000000/i)-1;
		result+=s*i*(i+1)/2+1000000*s*i-i*i*s*(s+1)/2;
	}
	cout<<result;
	getchar();
	return 0;
}
