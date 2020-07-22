#include <bits/stdc++.h>
using namespace std;
int main()
{
	long int result=0;
	vector<int> divisors(10000000,2);
	for(long int i=2;i<10000000;i++)
	{
		for(long int j=2*i;j<10000000;divisors[j-1]++,j+=i){}
		if(i!=2 && divisors[i-2]==divisors[i-1]){result++;}
	}
	cout<<result;
	getchar();
	return 0;
}
