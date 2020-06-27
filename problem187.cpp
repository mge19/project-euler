#include <bits/stdc++.h>
using namespace std;
int main()
{
	long int result=0;
	vector<int> relprime(100000000,0);
	for(long int i=2;i<100000000;i++)
	{
		if(relprime[i-1]==0)
		{
			for(long int j=2*i;j<100000000;j+=i)
			{
				if(relprime[j/i-1]==0){relprime[j-1]=1;}
				else{relprime[j-1]=2;}
			}
		}
		else if(relprime[i-1]==1){result++;}
	}
	cout<<result;
	getchar();
	return 0;
}
