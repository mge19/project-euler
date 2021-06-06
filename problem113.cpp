#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int result=0;
	for(int i=1;i<=100;i++)
	{
		long long int val=1;
		for(int j=1;j<9;j++){val*=(i+j);}
		val/=40320;
		result+=val*(102-i)-9;
	}
	cout<<result;
	getchar();
	return 0;
}
