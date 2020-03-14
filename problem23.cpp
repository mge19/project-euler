#include <bits/stdc++.h>
using namespace std;
int main()
{
	vector<int> sum(28123,1);
	bool can_be_written[28123];
	long int result=0;
	for(int i=2;i<=28123;i++)
	{
		for(long int j=2*i;j<=28123;sum[j-1]+=i,j+=i){}
	}
	for(int i=1;i<=28123;i++)
	{
		for(int j=i;i+j<=28123;j++)
		{
			if(sum[i-1]>i && sum[j-1]>j){can_be_written[i+j-1]=true;}
		}
	}
	for(int i=1;i<=28123;i++)
	{
		if(!can_be_written[i-1]){result+=i;}
	}
	cout<<result;
	getchar();
	return 0;
}
