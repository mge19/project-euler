#include <bits/stdc++.h>
using namespace std;
int main()
{
	int fibonacci[1000],fibonacci2[1000],a=2;
	for(int i=0;i<999;i++)
	{
		fibonacci[i]=0;
		fibonacci2[i]=0;
	}
	fibonacci[999]=1;
	fibonacci2[999]=1;
	for(;fibonacci2[0]==0;a++)
	{
		bool carry=false;
		int k=0;
		for(;fibonacci[k]==0 && fibonacci2[k]==0;k++){}	
		for(int i=999;i>=k-1;i--)
		{
			int temp=fibonacci[i];
			fibonacci[i]=fibonacci2[i];
			fibonacci2[i]+=temp+carry;
			carry=fibonacci2[i]/10;
			fibonacci2[i]%=10;
		}
	}
	cout<<a;
	getchar();
	return 0;
}
