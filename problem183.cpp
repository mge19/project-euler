#include <bits/stdc++.h>
#define e 2.71828
int gcd(int a,int b)
{
	if(b==0){return a;}
	return gcd(b,a%b);
}
using namespace std;
int main()
{
	long int result=0;
	for(double i=5;i<=10000;i++)
	{
		int a=round(i/e);
		a/=gcd(i,a);
		while(a%2==0){a/=2;}
		while(a%5==0){a/=5;}
		if(a==1){result-=i;}
		else{result+=i;}
	}
	cout<<result;
	getchar();
	return 0;
}
