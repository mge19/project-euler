#include <bits/stdc++.h>
using namespace std;
int main()
{
	unsigned long long int result=4;
	for(int i=4;i<=16;i++)
	{
		unsigned long long a=1,b=1,c=1,d=13;
		for(int j=0;j<i-1;j++)
		{
			a*=16;
			b*=15;
			c*=14;
			d*=13;
		}
		result+=15*a-43*b+41*c-d;
	}
	cout<<hex<<uppercase<<result;
	getchar();
	return 0;
}
