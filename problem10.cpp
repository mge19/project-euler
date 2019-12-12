#include <bits/stdc++.h>
using namespace std;
int main()
{
	bool asal[2000000];
	for(long int i=0;i<2000000;asal[i]=true,i++){}
	long long int result=0;
 	for(long int i=2;i<=2000000;i++)
	{
		if(asal[i-1])
		{
			for(long int k=2*i;k<2000000;asal[k-1]=false,k+=i){}
			result+=i;
		}
	}
	cout<<result;
	getchar();
	return 0;
}
