#include <bits/stdc++.h>
using namespace std;
int main()
{
	vector<bool> asal(100000000,true);
	vector<long int> asallar,relprimes;
	for(long int i=2;i<=100000000;i++)
	{
		if(asal[i-1])
		{
			asallar.push_back(i);
			long int x=asallar.size();
			for(long int j=0;j<x && asallar[j]*asallar[x-1]<100000000;relprimes.push_back(asallar[j]*asallar[x-1]),j++){}
			for(long int j=2*i;j<=100000000;asal[j-1]=false,j+=i){}
		}
	}
	cout<<relprimes.size();
	getchar();
	return 0;
}
