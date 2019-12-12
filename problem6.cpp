#include <bits/stdc++.h>
using namespace std;
int main()
{
	long int result1=0,result2=0;
	for(int i=1;i<=100;i++)
	{
		result1+=i;
		result2+=i*i;
	}
	cout<<result1*result1-result2;
	getchar();
	return 0;
}
