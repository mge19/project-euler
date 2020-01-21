#include <bits/stdc++.h>
using namespace std;
int main()
{
	int result;
	long int a=1,diff=2000000;
	for(;a*a*(a+1)*(a+1)/4<2000000;a++)
	{
		long int b=a;
		for(;a*b*(a+1)*(b+1)/4<2000000;b++){}
		if(abs(a*(a+1)*b*(b+1)/4-2000000)<diff)
		{
			result=a*b;
			diff=abs(a*(a+1)*b*(b+1)/4-2000000);
		}
		if(abs(a*(a+1)*b*(b-1)/4-2000000)<diff)
		{
			result=a*(b-1);
			diff=abs(a*(a+1)*b*(b-1)/4-2000000);
		}
	}
	if(abs(a*(a+1)*a*(a+1)/4-2000000)<diff)
	{
		result=a*a;
		diff=abs(a*(a+1)*a*(a+1)/4-2000000);
	}	
	cout<<result;
	getchar();
	return 0;
}
