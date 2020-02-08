#include <bits/stdc++.h>
using namespace std;
int main()
{
	vector<long int> sums(101,1);
	for(int i=2;i<100;i++)
	{
		for(int j=0;j<i;j++)
		{
			for(int k=j+i;k<=100;sums[k]+=sums[k-i],k+=i){}
		}
	}
	cout<<sums[100];
	getchar();
	return 0;
}
