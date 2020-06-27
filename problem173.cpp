#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int result=0;
	for(long long int a=3;a<=250001;a++)
	{
		for(long long int b=a-2;a*a-b*b<=1000000 && b>0;b-=2){result++;}
	}
	cout<<result;
	getchar();
	return 0;
}
