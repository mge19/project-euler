#include <bits/stdc++.h>
using namespace std;
int main()
{
	for(long double a=1;;a++)
	{
		for(long double b=floor(a*sqrt(2));b>a;b--)
		{
			long long int c=2*a-b,d=2*a*a-b*b;
			
			if(c<d){break;}
			else if(c%d==0)
			{
				if(b*c/d>1.0e+12)
				{
					cout<<setprecision(12)<<a*c/d;
					exit(1);
				}
			}
		}
	}
	return 0;
}
