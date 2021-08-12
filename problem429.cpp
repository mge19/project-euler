#include <bits/stdc++.h>
using namespace std;
int main()
{
	vector<bool> asallar(100000000,true);
	asallar[0]=false;
	long int u=100000000,v=1000000009;
	long long int result=1;
	for(long int i=1;i<u;i++)
	{
		if(asallar[i-1])
		{
			for(long int j=2*i;j<u;j+=i){asallar[j-1]=false;}
			long int s=u,k=0;
			long long int m=1;
			while(s!=0)
			{
				s/=i;
				k+=s;
			}
			k*=2;
			for(long int j=0;j<k;j++){m=(m*i)%v;}
			result=(result*(m+1))%v;
		}
	}
	cout<<result;
	getchar();
	return 0;
}
