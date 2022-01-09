#include <bits/stdc++.h>
using namespace std;
int main()
{
	vector<bool> asal(1000000,true);
	long int result=0;
	for(long int i=2;i<=1000000;i++)
	{
		if(asal[i-1])
		{
			for(long int j=2*i;j<=1000000;asal[j-1]=false,j+=i){}
		}
	}
	for(long int i=2;3*i*(i-1)+1<1000000;i++)
	{
		if(asal[3*i*(i-1)]){result++;}
	}
	cout<<result;
	getchar();
	return 0;
}
