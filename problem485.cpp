#include <bits/stdc++.h>
using namespace std;
int main()
{
	long int limit=100000000,step=100000;
	vector<long int> d(limit,1);
	long long int result=0;
	for(long int i=2;i<limit;i++)
	{
		if(d[i-1]==1)
		{
			for(long int j=i;j<=limit;j+=i)
			{
				int x=1;
				long int y=j;
				while(y%i==0)
				{
					x++;
					y/=i;
				}
				d[j-1]*=x;
			}
		}
	}
	for(long int i=0;i<limit/step;i++)
	{
		vector<long int> v(2*step-1,0);
		for(long int j=step-1;j>=0;j--)
		{
			v[j]=(j==step-1)?d[i*step+j]:max(d[i*step+j],v[j+1]);
		}	
		result+=v[0];
		if(i<limit/step-1)
		{
			for(long int j=0;j<step-1;j++)
			{
				v[step+j]=(j==0)?d[(i+1)*step+j]:max(v[step+j-1],d[(i+1)*step+j]);
				result+=max(v[step+j],v[j+1]);
			}
		}
	}
	cout<<result;
	getchar();
	return 0;
}
