#include <bits/stdc++.h>
using namespace std;
int main()
{
	vector<long double> v1,v2;
	v1.push_back(1);
	v2.push_back(1);
	int result=0;
	for(long double i=2;i<=100;i++)
	{
		for(long double j=1;j<=(int)(i/2);j++)
		{
			if((int)i%2==0 && j==i/2)
			{
				v2.push_back(2*v1[j-1]);
				if(v2[j]>1.0e+6){result++;}
			}
			else
			{
				v2[j]=v1[j-1]+v1[j];
				if(v2[j]>1.0e+6){result+=2;}
			}
		}
		v1=v2;
	}
	cout<<result;
	getchar();
	return 0;
}
