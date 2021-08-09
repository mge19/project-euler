#include <bits/stdc++.h>
using namespace std;
int main()
{
	vector<long long int> v;
	vector<long long int> test;
	long long int x=1000000000000,y=2,result=1;
	for(int i=1;i<32;i++){y*=2;}
	long long int n=1;
	v.push_back(n);
	for(int i=0;i<v.size();i++)
	{
		if(v[i]==1)
		{
			long long int n=v[i];
			while(true)
			{
				n*=5;
				if(n>x){break;}
				result=(result+n)%y;
				v.push_back(n);					
			}
		}
		if(v[i]%2!=0 && v[i]%3!=0)
		{
			long long int n=v[i];
			while(true)
			{
				n*=3;
				if(n>x){break;}
				result=(result+n)%y;
				v.push_back(n);
			}
		}
		if(v[i]%2!=0)
		{
			long long int n=v[i];
			while(true)
			{
				n*=2;
				if(n>x){break;}
				result=(result+n)%y;
				if(n%y!=0){v.push_back(n);}
				test.push_back(n+1);
			}
		}
	}
	test.erase(test.begin(),test.begin()+2);
	sort(test.begin(),test.end());
	test.pop_back();
	long long int max=test[test.size()-1];
	vector<long long int> asallar;
	asallar.push_back(2);
	asallar.push_back(3);
	for(long int i=6;i<=trunc(sqrt(max));i+=6)
	{
		long int a=i-1,b=i+1;
		bool asal=true;
		for(int j=0;j<asallar.size() && asallar[j]<=trunc(sqrt(a));j++)
		{
			if(a%asallar[j]==0)
			{
				asal=false;
				break;
			}
		}
		if(asal){asallar.push_back(a);}
		asal=true;
		for(int j=0;j<asallar.size() && asallar[j]<=trunc(sqrt(b));j++)
		{
			if(b%asallar[j]==0)
			{
				asal=false;
				break;
			}
		}
		if(asal){asallar.push_back(b);}
	}
	for(int i=0;i<test.size();)
	{
		bool asal=true;
		for(int j=0;j<asallar.size() && asallar[j]<=trunc(sqrt(test[i]));j++)
		{
			if(test[i]%asallar[j]==0)
			{
				asal=false;
				break;
			}
		}
		if(!asal){test.erase(test.begin()+i,test.begin()+i+1);}
		else{i++;}
	}
	vector<vector<int> > indexes;
	int z=test.size();
	for(int i=0;i<z;i++)
	{
		vector<int> v1;
		v1.push_back(i);
		indexes.push_back(v1);
	}
	for(int i=0;i<indexes.size();i++)
	{
		for(int j=indexes[i][indexes[i].size()-1]+1;j<z;j++)
		{
			long long int s=1;
			vector<int> v1=indexes[i];
			v1.push_back(j);
			for(int k=0;k<v1.size();k++){s*=test[v1[k]];}
			if(s>x || s<0){break;}
			else
			{
				indexes.push_back(v1);
				test.push_back(s);
			}
		}
	}
	sort(test.begin(),test.end());
	for(int i=0;i<v.size();i++)
	{
		for(int j=0;j<test.size();j++)
		{
			long long int a=v[i]*test[j];
			if(a>x){break;}
			else{result=(result+a)%y;}
		}
	}
	cout<<result;
	getchar();
	return 0;
}
