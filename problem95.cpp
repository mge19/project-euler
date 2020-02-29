#include <bits/stdc++.h>
using namespace std;
int main()
{
	int maxloop=0;
	long long int result;
	vector<bool> visited(1000000,true);
	for(long int i=2;i<=1000000;i++)
	{
		if(visited[i-1])
		{
			for(long int k=2*i;k<1000000;visited[k-1]=false,k+=i){}
		}
	}
	visited[0]=true;
	for(long int i=2;i<=1000000;i++)
	{
		vector<long long int> numbers;
		long long int number=i;
		while(number<=1000000 && visited[number-1]==false)
		{
			numbers.push_back(number);
			visited[number-1]=true;
			long long int a=1;
			for(long long int x=number,j=2;x!=1;j++)
			{
				long long int u=j;
				for(;x%j==0;u*=j,x/=j){}
				a*=(u-1)/(j-1);
			}
			number=a-number;
			cout<<i<<" "<<number<<endl;
		}
		for(int j=0;j<numbers.size();j++)
		{
			if(numbers[j]==number && numbers.size()-j>maxloop)
			{
				maxloop=numbers.size()-j;
				result=numbers[j];
			}
		}
	}
	cout<<result;
	getchar();
	return 0;
}
