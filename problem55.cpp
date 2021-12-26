#include <bits/stdc++.h>
using namespace std;
unsigned long long int plus_reverse(unsigned long long int i)
{
	unsigned long long int n=i,m=0;
	while(n>0)
	{
		m=10*m+n%10;
		n/=10;
	}
	return m+i;
}
bool palindromic(unsigned long long int x)
{
	unsigned long long int y=1,n=x;
	while(n!=0)
	{
		y*=10;
		n/=10;
	}
	y/=10;
	n=10;
	while(true)
	{
		if((x/y)%10!=(x%n)/(n/10)){return false;}
		if(y<=n){return true;}
		y/=10;
		n*=10;
	}
}
int main()
{
	int result=0;
	for(int i=1;i<10000;i++)
	{
		unsigned long long int number=i;
		int x=0;
		while(x<50)
		{
			number=plus_reverse(number);
			x++;
			if(palindromic(number)){break;}
			if(x==50 && !palindromic(number)){result++;}
		}
	}
	cout<<result;
	getchar();
	return 0;
}
