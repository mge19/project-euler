#include <bits/stdc++.h>
using namespace std;
int main()
{
	unsigned long long int result=0,limit=999966663333;
	vector<unsigned long long int> asallar;
	asallar.push_back(2);
	asallar.push_back(3);
	for(long int i=6;i<=1000000;i+=6)
	{
		unsigned long long int a=i-1,b=i+1,j=0;
		for(;a%asallar[j]!=0 && asallar[j]<=floor(sqrt(a));j++){}
		if(asallar[j]>floor(sqrt(a))){asallar.push_back(a);}
		j=0;
		for(;b%asallar[j]!=0 && asallar[j]<=floor(sqrt(b));j++){}
		if(asallar[j]>floor(sqrt(b))){asallar.push_back(b);}
	}
	for(long int i=0;asallar[i]*asallar[i]<limit && i<asallar.size()-1;i++)
	{
		unsigned long long int a=min(limit,asallar[i+1]*asallar[i+1])/asallar[i],b=asallar[i]*asallar[i]/asallar[i+1],
		c=min(limit/asallar[i+1],asallar[i+1]-1);
		result+=asallar[i]*(a*(a+1)-asallar[i]*(asallar[i]+1))/2+asallar[i+1]*(c*(c+1)-b*(b+1))/2;
		if(asallar[i]*asallar[i+1]<=limit){result-=2*asallar[i]*asallar[i+1];}
	}
	cout<<result;
	getchar();
	return 0;
}
