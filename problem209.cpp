#include <bits/stdc++.h>
using namespace std;
unsigned long long int combination(int n,int r)
{
	if(r>n/2){r=n-r;}
	unsigned long long int a=1;
	for(int i=0;i<r;i++)
	{
		a*=n-i;
		a/=i+1;
	}
	return a;
}
int main()
{	
	unsigned long long int result=1;
	bool available[64];
	available[0]=false;
	for(int i=1;i<64;i++){available[i]=true;}
	vector<vector<int> > cycles;
	int i=1,traversed=1;
	while(traversed<64)
	{
		int j=i;
		vector<int> v;
		if(available[j])
		{
			while(available[j])
			{
				v.push_back(j);
				traversed++;
				available[j]=false;
				bool a[6];
				int k=1;
				for(int i=0;i<6;i++)
				{
					a[5-i]=(j/k)%2;
					k*=2;
				}
				bool z=a[0]^(a[1]&a[2]);
				for(int i=0;i<5;i++){a[i]=a[i+1];}
				a[5]=z;
				j=0;
				k/=2;
				for(int i=0;i<6;i++)
				{
					j+=k*a[i];
					k/=2;
				}	
			}
			cycles.push_back(v);
		}
		i++;
	}
	for(int i=0;i<cycles.size();i++)
	{
		int a=cycles[i].size();
		unsigned long long int n=a+1;
		for(int r=2;r<=a/2;r++){n+=combination(a-r+1,r)-combination(a-r-1,r-2);}
		result*=n;
	}
	cout<<result;
	getchar();
	return 0;
}
