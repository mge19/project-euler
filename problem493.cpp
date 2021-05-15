#include <bits/stdc++.h>
using namespace std;
int main()
{
	long int fact[11];
	fact[0]=1;
	for(int i=1;i<=10;fact[i]=i*fact[i-1],i++){}
	unsigned long long int a=0,b=0;
	queue<vector<int> > q;
	for(int i=0;i<=10;i++)
	{
		vector<int> v;
		v.push_back(i);
		q.push(v);
	}
	while(!q.empty())
	{
		vector<int> v=q.front();
		q.pop();
		int sum=0;
		for(int i=0;i<v.size();i++){sum+=v[i];}
		if(sum==20)
		{
			int c=0;
			unsigned long long int d=1;
			for(int i=0;i<v.size();i++)
			{
				if(v[i]!=0)
				{
					c++;
					d*=fact[10]/(fact[10-v[i]]*fact[v[i]]);
				}
			}
			a+=c*d;
			b+=d;
		}
		else
		{
			if(v.size()<7)
			{
				for(int i=0;i<=20-sum;i++)
				{
					if(i>10){break;}
					vector<int> v1=v;
					v1.push_back(i);
					q.push(v1);
				}
			}
		}
	}
	cout<<setprecision(10)<<(long double)a/(long double)b;
	getchar();
	return 0;
}
