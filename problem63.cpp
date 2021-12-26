#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int main()
{
	int result=0;
	for(double i=1;i<10;i++)
	{
		double j=1;
		while(trunc(j*log10(i)+1)==j)
		{
			j++;
			result++;
		}
	}
	cout<<result;
	getchar();
	return 0;
}
