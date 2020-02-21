#include <bits/stdc++.h>
using namespace std;
bool asalmi(long int number)
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
	map<long int,bool> asal;
	long int i;
	for(i=3;;i+=2)
	{
		if(!asalmi(i))
		{
			asal[i]=false;
			long int j;
			for(j=1;i>2*j*j && !asal[i-2*j*j];j++){}
			if(i<=2*j*j){break;}
		}		
		else{asal[i]=true;}
	}
	cout<<i;
	getchar();
	return 0;
}
