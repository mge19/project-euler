#include <bits/stdc++.h>
using namespace std;
bool hcf(int n,int d)
{
	while(n!=d)
	{
		if(n>d){n-=d;}
		else{d-=n;}
	}
	return n==1;
}
int main()
{
	long int result=0;
	for(int n=2;n<6000;n++)
	{
		for(int d=2*n+1;d<3*n && d<=12000;)
		{
			result+=hcf(n,d);
			if(n%2==0){d+=2;}
			else{d++;}
		}
	}
	cout<<result;
	getchar();
	return 0;
}
