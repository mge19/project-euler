#include <bits/stdc++.h>
using namespace std;
int main()
{
	vector<int> t(1000000,0);
	long int result=0;
	for(long long int a=3;a<=250001;a++)
	{
		for(long long int b=a-2;a*a-b*b<=1000000 && b>0;b-=2)
		{
			if(t[a*a-b*b-1]<11){t[a*a-b*b-1]++;}
		}
	}
	for(int i=0;i<1000000;i++){result+=(t[i]<11 && t[i]>0);}
	cout<<result;
	getchar();
	return 0;
}
