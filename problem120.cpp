#include <bits/stdc++.h>
using namespace std;
int main()
{
	long int result=0;
	for(int a=3;a<=1000;a++)
	{
		long int first=2*a,cur=0,maxx=0;
		for(int n=6;first!=cur;n+=4)
		{
			cur=(n*a)%(a*a);
			maxx=max(cur,maxx);
		}
		result+=maxx;
	}
	cout<<result;
	getchar();
	return 0;
}
