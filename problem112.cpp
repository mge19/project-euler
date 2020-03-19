#include <bits/stdc++.h>
using namespace std;
bool nonbouncy(long int number)
{
	stringstream ss;
	string str;
	ss<<number;
	ss>>str;
	int i=0,j=0;
	for(;str[i]<=str[i+1] && i<str.size()-1;i++){}
	for(;str[j]>=str[j+1] && j<str.size()-1;j++){}
	return (i==str.size()-1 || j==str.size()-1);
}
int main()
{
	long int result=99,i=100;
	for(;i!=100*result;i++)
	{
		if(nonbouncy(i)){result++;}
	}
	cout<<i;
	getchar();
	return 0;
}
