#include <bits/stdc++.h>
using namespace std;
int main()
{
	long int fact[10];
	int result=0;
	fact[0]=1;
	for(int i=1;i<10;i++){fact[i]=i*fact[i-1];}
	vector<int> loop(6*fact[9]+1,-1);
	for(long int i=0;i<1000000;i++)
	{
		vector<long int> numbers;
		long int number=i;
		while(loop[number]==-1)
		{
			numbers.push_back(number);
			loop[number]=0;
			long int x=0;
			while(number>0)
			{
				x+=fact[number%10];
				number/=10;
			}
			number=x;
		}
		for(int j=0;j<numbers.size();j++){loop[numbers[j]]+=loop[number]+numbers.size()-j;}
		if(loop[i]==60){result++;}
	}
	cout<<result;
	getchar();
	return 0;
}
