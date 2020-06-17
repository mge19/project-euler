#include <bits/stdc++.h>
using namespace std;
bool palindromic(long int number)
{
	stringstream ss;
	ss<<number;
	string str=ss.str();
	int x=str.size();
	for(int i=0;i<x/2;i++)
	{
		if(str[i]!=str[x-1-i]){return false;}
	}
	return true;
}
int main()
{
	unsigned long int result=0;
	set<long int> numbers;
	for(int i=1;i<10000;i++)
	{
		long int j=i*i;
		for(int x=i+1;j<100000000;x++)
		{
			j+=x*x;
			if(palindromic(j)){numbers.insert(j);}
		}
	}
	for(set<long int>::iterator it=numbers.begin();it!=numbers.end();++it){result+=(*it);}
	cout<<result;
	getchar();
	return 0;
}
