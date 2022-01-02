#include <bits/stdc++.h>
using namespace std;
int main()
{
	unsigned long long int result=1;
	set<unsigned long long int> numbers;
	for(int i=2;i<=50;i++)
	{
		unsigned long long int a=1;
		for(int j=0;j<i/2;j++)
		{
			a=a*(i-j)/(j+1);
			numbers.insert(a);
		}
	}
	for(set<unsigned long long int>::iterator it=numbers.begin();it!=numbers.end();++it)
	{
		unsigned long long int y=2;
		for(;y<=trunc(sqrt(*it)) && (*it)%(y*y)!=0;y++){}
		if(y>trunc(sqrt(*it))){result+=(*it);}
	}
	cout<<result;
	getchar();
	return 0;
} 
