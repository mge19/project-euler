#include <bits/stdc++.h>
using namespace std;
int main()
{
	vector<int> asallar;
	asallar.push_back(2);
	asallar.push_back(3);
	set<vector<long int> > sets;
	map<long int,bool> isprime;
	isprime[1]=false;
	isprime[2]=true;
	for(int i=6;i<=10000;i+=6)
	{
		int a=i-1,b=i+1,j=0;
		for(;a%asallar[j]!=0 && asallar[j]<=floor(sqrt(a));j++){}
		if(asallar[j]>floor(sqrt(a))){asallar.push_back(a);}
		j=0;
		for(;b%asallar[j]!=0 && asallar[j]<=floor(sqrt(b));j++){}
		if(asallar[j]>floor(sqrt(b))){asallar.push_back(b);}
	}
	long int fact[10];
	fact[0]=1;
	for(int i=1;i<=9;fact[i]=i*fact[i-1],i++){}
	for(long int n=1;n<=fact[9];n++)
	{
		bool used[9];
		vector<int> numbers;
		long int u=0;
		for(int i=0;i<9;used[i]=false,i++){}
		for(int i=0;i<9;i++)
		{
			int j=0,x=0,a;
			while(u+j*fact[8-i]<n){j++;}
			j--;
			u+=j*fact[8-i];
			for(a=0;x<=j;a++)
			{
				if(!used[a]){x++;}
			}
			used[a-1]=true;
			numbers.push_back(a);
		}
		queue<pair<vector<long int>,int> > q;
		u=0;
		for(int i=0;i<8;i++)
		{
			u=10*u+numbers[i];
			if(isprime.count(u)==0)
			{
				int j=0;
				for(;u%asallar[j]!=0 && asallar[j]<sqrt(u);j++){}
				isprime[u]=(asallar[j]>=sqrt(u) && u%asallar[j]!=0)?true:false;
			}
			if(isprime[u])
			{
				vector<long int> v;
				v.push_back(u);
				pair<vector<long int>,int> p;
				p.first=v;
				p.second=i;
				q.push(p);			
			}
		}
		while(!q.empty())
		{
			pair<vector<long int>,int> p=q.front();
			q.pop();
			if(p.second==8)
			{
				vector<long int> v=p.first;
				sort(v.begin(),v.end());
				sets.insert(v);
			}
			else
			{
				u=0;
				for(int i=p.second+1;i<9;i++)
				{
					u=10*u+numbers[i];
					if(isprime.count(u)==0)
					{
						int j=0;
						for(;u%asallar[j]!=0 && asallar[j]<sqrt(u);j++){}
						isprime[u]=(asallar[j]>=sqrt(u) && u%asallar[j]!=0)?true:false;
					}
					if(isprime[u])
					{
						vector<long int> v=p.first;
						v.push_back(u);
						pair<vector<long int>,int> p1;
						p1.first=v;
						p1.second=i;
						q.push(p1);			
					}
				}			
			}			
		}		
	}
	cout<<sets.size();
	getchar();
	return 0;
}
