#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int result=0;
	vector<bool> asal(20000000,true);
	for(long int x=2;x<20000000;x++)
	{
		if(asal[x-1])
		{
			for(long int j=2*x;j<20000000;asal[j-1]=false,j+=x){}
			long int i=0,j=0,k=0,a=20000000,b=15000000,c=5000000;	
			while(a>0)
			{
				i+=a/x;
				a/=x;				
				if(b>0)
				{
					j+=b/x;
					b/=x;
				}
				if(c>0)
				{
					k+=c/x;
					c/=x;
				}
			}
			result+=x*(i-j-k);
		}
	}
	cout<<result;
	getchar();
	return 0;
}
