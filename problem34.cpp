#include <bits/stdc++.h>
using namespace std;
int main()
{
	vector<long int> fact;
	fact.push_back(1);
	for(int i=1;i<=9;fact.push_back(i*fact[i-1]),i++){}
	long int limit=9,sum=0;
	for(int n=1;limit<n*fact[9];limit=10*limit+9,n++){}
	for(long int i=10;i<=(limit-9)/10;i++)
	{
		long int number=i,result=0;
		while(number>0)
		{
			result+=fact[number%10];
			number/=10;
		}
		if(result==i){sum+=i;}
	}
	cout<<sum;
	getchar();
	return 0;
}
