#include <bits/stdc++.h>
using namespace std;
int main()
{
	int result=0;
	vector<long int> factsums;
	factsums.push_back(1);
	for(int i=1;i<10;factsums.push_back(i*factsums[i-1]),i++){}
	vector<bool> visited(6*factsums[9]+1,false);
	vector<int> loop(6*factsums[9]+1,0);
	for(long int i=10;i<=6*factsums[9];i++)
	{
		factsums.push_back(0);
		long int number=i;
		while(number>0)
		{
			factsums[i]+=factsums[number%10];
			number/=10;
		}		
	}
	for(long int i=0;i<=6*factsums[9];i++)
	{
		long int number=i;
		vector<long int> numbers;
		while(!visited[number])
		{
			numbers.push_back(number);
			visited[number]=true;
			number=factsums[number];
		}
		for(int j=0;j<numbers.size();j++){loop[numbers[j]]=numbers.size()+loop[number]-j;}
		if(loop[i]==60 && i<1000000){result++;}
	}
	cout<<result;
	getchar();
	return 0;
}
