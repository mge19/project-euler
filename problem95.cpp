#include <bits/stdc++.h>
using namespace std;
int main()
{
	int maxloop=0;
	long int result;
	vector<long int> loop(1000000,1);
	vector<bool> visited(1000000,false);
	visited[0]=true;
	for(long int i=2;i<=1000000;i++)
	{
		vector<long int> numbers;
		long int number=i;
		while(visited[number-1]==false)
		{
			numbers.push_back(number);
			visited[number-1]=true;
			number=loop[number-1];
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
