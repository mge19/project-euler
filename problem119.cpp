#include <bits/stdc++.h>
using namespace std;
int main()
{
	map<int,long long int> power;
	int x=0,n=2;
	long long int result,m=10;
	while(x<30)
	{
		for(int i=n;i<=9*n;i++)
		{
			long long int k;
			if(power.count(i)>0){k=power[i];}
			else{k=i;}
			while(k<=10*m)
			{
				if(k>=m)
				{
					long long int u=k;
					int l=0;
					while(u!=0)
					{
						l+=u%10;
						u/=10;
					}
					if(l==i)
					{
						x++;
						result=k;
					}
				}
				k*=i;
			}
			power[i]=k;
		}
		n++;
		m*=10;
	}
	cout<<result;
	getchar();
	return 0;
}
