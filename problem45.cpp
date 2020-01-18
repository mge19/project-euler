#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int main()
{
	long long int number=166;
	for(;;number++)
	{
		if(sqrt(4*number*(3*number-1)+1)==round(sqrt(4*number*(3*number-1)+1)))
		{
			int x=sqrt(4*number*(3*number-1)+1)-1;
			if(x%4!=0){break;}
		}
	}
	cout<<number*(3*number-1)/2;
}
