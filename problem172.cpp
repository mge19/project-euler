#include <bits/stdc++.h>
using namespace std;
int main()
{
	long int fact[10];
	fact[0]=1;
	for(int i=1;i<10;fact[i]=i*fact[i-1],i++){}
	long long int result=0,m=fact[9];
	for(int i=10;i<=18;m*=i,i++){}
	queue<vector<int> > q;
	vector<int> v;
	for(int i=1;i<=3;i++)
	{
		v.push_back(i);
		q.push(v); 
		v.clear();
	}
	while(!q.empty())
	{
		v=q.front();
		q.pop();
		int sum=0,a=v.size();
		for(int i=0;i<a;sum+=v[i],i++){}
		if(sum==18)
		{
			long long int x=m;
			int n1=0,n2=0,n3=0;
			for(int i=0;i<a;i++)
			{
				x/=fact[v[i]];
				n1+=(v[i]==1);
				n2+=(v[i]==2);
				n3+=(v[i]==3);
			}
			if(a<10)
			{
				long int u=fact[9]/(fact[9-a]*fact[a]),v=fact[a]/(fact[a-n1]*fact[n1]),y=fact[a-n1]/(fact[a-n1-n2]*fact[n2]),
				z=fact[a-n1-n2]/(fact[a-n1-n2-n3]*fact[n3]);
				result+=u*v*x*y*z;
			}
			if(n1>0)
			{
				long int u=fact[9]/(fact[10-a]*fact[a-1]),v=fact[a-1]/(fact[a-n1]*fact[n1-1]),y=fact[a-n1]/(fact[a-n1-n2]*fact[n2]),
				z=fact[a-n1-n2]/(fact[a-n1-n2-n3]*fact[n3]);
				result+=17*u*v*x*y*z/18;
			}
			if(n2>0)
			{
				long int u=fact[9]/(fact[10-a]*fact[a-1]),v=fact[a-1]/(fact[a-n1-1]*fact[n1]),y=fact[a-n1-1]/(fact[a-n1-n2]*fact[n2-1]),
				z=fact[a-n1-n2]/(fact[a-n1-n2-n3]*fact[n3]);
				result+=16*u*v*x*y*z/18;
			}
			if(n3>0)
			{
				long int u=fact[9]/(fact[10-a]*fact[a-1]),v=fact[a-1]/(fact[a-1-n1]*fact[n1]),y=fact[a-1-n1]/(fact[a-1-n1-n2]*fact[n2]),
				z=fact[a-1-n1-n2]/(fact[a-n1-n2-n3]*fact[n3-1]);
				result+=5*u*v*x*y*z/6;
			}
		}
		else if(a<10 && sum<18)
		{
			if(v[a-1]==1)
			{
				vector<int> v1=v;
				v1.push_back(1);
				q.push(v1);
			}
			if(sum<=16 && v[a-1]<=2)
			{
				vector<int> v2=v;
				v2.push_back(2);
				q.push(v2);	
			}
			if(sum<=15 && v[a-1]<=3)
			{
				vector<int> v3=v;
				v3.push_back(3);
				q.push(v3);	
			}
		}
	}
	cout<<result;
	getchar();
	return 0;
}
