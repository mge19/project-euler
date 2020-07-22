#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int result=3;
	vector<int> numbers(100000000,0);
	for(long int i=2;i<100000000;i++)
	{
		if(numbers[i-1]==0)
		{
			for(long int j=2*i;j<100000000;j+=i){numbers[j-1]=1;}
	 	}
		else
		{
			for(long int j=1;j<=i/2 && j*(i-j)<100000000;j++){numbers[j*(i-j)-1]=2;}
		}
	}
	for(long int i=2;i<100000000;i++)
	{
		if(numbers[i-1]==1){result+=i;}
	}
	cout<<result;
	getchar();
	return 0;
}
