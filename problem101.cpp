#include <bits/stdc++.h>
using namespace std;
int main()
{
	long double result=1;
	vector<vector<long double> > v1,v2;
	vector<long double> v3;
	v3.push_back(1);
	v3.push_back(1);
	v1.push_back(v3);
	for(int n=2;n<=10;n++)
	{
		v1[0].push_back(1);
		for(int i=1;i<n-1;i++){v1[i].insert(v1[i].begin(),pow(i+1,n-1));}
		v3.clear();
		v3.push_back(1);
		for(int i=0;i<n-1;i++){v3.insert(v3.begin(),n*v3[0]);}
		v3.push_back((pow(n,11)+1)/(n+1));
		v1.push_back(v3);
		v2=v1;
		for(int i=0;i<n-1;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				long double x=v2[j][i]/v2[i][i];
				for(int k=i;k<=n;k++){v2[j][k]-=v2[i][k]*x;}
			}
		}
		for(int i=n-1;i>=0;i--)
		{
			for(int j=n-1;j>i;j--){v2[i][n]-=v2[j][n]*v2[i][j];}
			v2[i][n]/=v2[i][i];
			result+=v2[i][n]*pow(n+1,n-i-1);
		}
	}
	cout<<setprecision(11)<<result;
	getchar();
	return 0;
}
