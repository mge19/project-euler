#include <bits/stdc++.h>
using namespace std;
int main()
{
	int x=round(sqrt(50000000));
	vector<bool> asal(x,true);
	vector<int> asallar;
	set<long int> numbers;
	for(int i=2;i<=x;i++)
	{
		if(asal[i-1])
		{
			for(int j=2*i;j<=x;asal[j-1]=false,j+=i){}
			asallar.push_back(i);
		}
	}
	for(int i=0;i<asallar.size();i++)
	{
		for(int j=0;j<asallar.size();j++)
		{
			if(asallar[i]*asallar[i]+asallar[j]*asallar[j]*asallar[j]>=50000000){break;}
			for(int k=0;;k++)
			{
				unsigned long long int number=asallar[i]*asallar[i]+asallar[j]*asallar[j]*asallar[j]+asallar[k]*asallar[k]*asallar[k]*asallar[k];
				if(number>=50000000){break;}
				numbers.insert(number);
			}
		}
	}
	cout<<numbers.size();
	getchar();
	return 0;
}
