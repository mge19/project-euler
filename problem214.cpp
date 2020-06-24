#include <bits/stdc++.h>
using namespace std;
int main()
{
	vector<long int> relprime(40000000,1);
	vector<int> loop(40000000,0);
	loop[0]=1;
	long long int sum=0;
	for(long int i=2;i<=40000000;i++)
	{
		if(relprime[i-1]==1)
		{
			relprime[i-1]=i-1;
			for(long int j=2*i;j<40000000;relprime[j-1]*=i-1,j+=i){}	
		}                   		
	}
	for(long int i=2;i*i<40000000;i++)
	{
		if(relprime[i-1]==i-1)
		{
			for(long int j=i*i;j<40000000;relprime[j-1]=i*relprime[j/i-1],j+=i*i){}
		}
	}
	for(long int i=2;i<40000000;i++)
	{
		if(relprime[i-1]==i-1)
		{
			vector<long int> numbers;
			long int number=i;
			while(loop[number-1]==0)
			{
				numbers.push_back(number);
				number=relprime[number-1];
			}
			for(int j=0;j<numbers.size();j++){loop[numbers[j]-1]+=loop[number-1]+numbers.size()-j;}
			if(loop[i-1]==25){sum+=i;}
		}
	}
	cout<<sum;
	getchar();
	return 0;
}
