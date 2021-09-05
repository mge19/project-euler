#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int result=0;
	for(int i=1;i<=1000;i++)
	{
		long long int m=1;
		for(int j=1;j<=i;j++)
		{
			m=(m*i)%10000000000;
		}
		result=(result+m)%10000000000;
	}
	cout<<result;
	getchar();
	return 0;
}
