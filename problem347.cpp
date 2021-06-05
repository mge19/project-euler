#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int result=0;
	vector<long int> numbers;
	numbers.push_back(2);
	numbers.push_back(3);
	long int s=10000000;
	for(long int i=6;i<s/2;i+=6)
	{
		long int a=i-1,b=i+1,j=0;
		for(;a%numbers[j]!=0 && numbers[j]<=floor(sqrt(a));j++){}
		if(numbers[j]>floor(sqrt(a))){numbers.push_back(a);}
		j=0;
		for(;b%numbers[j]!=0 && numbers[j]<=floor(sqrt(b));j++){}
		if(numbers[j]>floor(sqrt(b))){numbers.push_back(b);}		
	}
	for(long int i=0;numbers[i]<=floor(sqrt(s));i++)
	{
		for(long int j=i+1;numbers[j]<=s/numbers[i] && j<numbers.size();j++)
		{
			long int x=numbers[i],y=numbers[j];
			long long int a=x*y;
			set<long long int> n;
			set<long long int>::iterator it=n.begin();
			while(a<=s)
			{
				n.insert(a);
				it++;
				long long int b=(*it)*y;
				if(b<=s){n.insert(b);}
				a=(*it)*x;
			}
			result+=*(n.rbegin());			
		}
	}
	cout<<result;
	getchar();
	return 0;
}
