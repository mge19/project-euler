#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int result=0;
	vector<long int> factors(100000000,0);
	for(long int i=2;i<=100000000;i++)
	{
		if(factors[i-1]==0)
		{
			long int a=i;
			int b=-1;
			for(long long int j=i;j<=100000000;j*=i)
			{
				for(long int k=j;k<=100000000;factors[k-1]=max(factors[k-1],a),k+=j){}
				if(b==-1)
				{
					long int c=a;
					while(c%i==0)
					{
						c/=i;
						b++;
					}
					if(b==0){a+=i;}
				}
				else if(b==0){a+=i;}
				b--;
			}
		}
		result+=factors[i-1];
	}
	cout<<result;
	getchar();
	return 0;
}
