#include <bits/stdc++.h>
#include <cmath>
using namespace std;
bool asal(long int number)
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
	long int total=0;
	long long int i=2;
	for(;;i+=2)
	{
		total+=asal(i*i-i+1)+asal(i*i+i+1)+asal(i*i+1);
		if(5*total<i){break;}
	}
	cout<<i-1;
	getchar();
	return 0;
}
