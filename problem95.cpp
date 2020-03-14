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
		if(loop[i-1]==1){visited[i-1]=true;}
		for(long int j=2*i;j<=1000000;loop[j-1]+=i,j+=i){}
	}
	for(long int i=2;i<=1000000;i++)
	{
		vector<long int> numbers;
		long int number=i;
		while(number<=1000000 && !visited[number-1])
		{
			numbers.push_back(number);
			visited[number-1]=true;
			number=loop[number-1];
		}
		if(number<=1000000)
		{
			for(int j=0;j<numbers.size();j++)
			{
				if(numbers[j]==number && numbers.size()-j>maxloop)
				{
					maxloop=numbers.size()-j;
					result=numbers[j];
				}
			}
		}
	}
	cout<<result;
	getchar();
	return 0;
}
