#include <bits/stdc++.h>
using namespace std;
bool asal(int number)
{
	int x=round(sqrt(number));
	for(int i=2;i<=x;i++)
	{
		if(number%i==0){return false;}
	}
	return true;
}
int main()
{
	int u=0,i;
	for(i=2;u<10001;u+=asal(i),i++){}
	cout<<i-1;
	getchar();
	return 0;
}
