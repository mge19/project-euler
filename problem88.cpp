#include <bits/stdc++.h>
using namespace std;
int main()
{
	long int result=0;
	vector<long int> k(12000,99999);
	k[0]=0;
	set<int> sums;
	queue<vector<int> > q;
	for(int i=2;i<=round(sqrt(24000));i++)
	{
		vector<int> v;
		v.push_back(i);
		q.push(v);
	}
	while(!q.empty())
	{
		vector<int> v=q.front();
		q.pop();
		int product=1,sum=0;
		for(int i=0;i<v.size();i++)
		{
			product*=v[i];
			sum+=v[i];
		}
		if(v.size()>1 && product<k[product-sum+v.size()-1]){k[product-sum+v.size()-1]=product;}
		for(int i=v.back();;i++)
		{
			vector<int> v1=v;
			v1.push_back(i);
			if(product*i-sum-i+v.size()>12000){break;}
			else{q.push(v1);}
		}
	}
	for(int i=1;i<12000;i++)
	{
		int x=sums.size();
		sums.insert(k[i]);
		int y=sums.size();
		if(x!=y){result+=k[i];}
	}
	cout<<result;
	getchar();
	return 0;
}
