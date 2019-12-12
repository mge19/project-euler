#include <bits/stdc++.h>
using namespace std;
int main()
{
	long int n=1,i=1;
	for(int bolensayisi=1;bolensayisi<500;i++,n+=i)
	{
		bolensayisi=1;
		for(long int x=n,j=2;x!=1;j++)
		{
			int u=1;
			for(;x%j==0;x/=j,u++){}
			bolensayisi*=u;
		}
	}
	cout<<n-i;
	getchar();
	return 0;
}
