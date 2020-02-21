#include <bits/stdc++.h>
using namespace std;
bool asalmi(int number)
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
	map<int,bool> asal;
	int i;
	for(i=3;;i+=2)
	{
		if(!asalmi(i))
		{
			asal[i]=false;
			int j;
			for(j=1;i>2*j*j && !asal[i-2*j*j];j++){}
			if(i<=2*j*j){break;}
		}		
		else{asal[i]=true;}
	}
	cout<<i;
	getchar();
	return 0;
}
