#include <bits/stdc++.h>
using namespace std;
int main()
{
	string str="UDDDUdddDDUDDddDdDddDDUDDdUUDd";
	long long int a=1,b=3,d=4;
	int c=2;
	for(int i=1;i<str.size();i++)
	{
		switch(str[i])
		{
			case 'U':
				while(c%3!=1)
				{
					c+=d;
					a+=b;
				}
				d*=4;
				c=(4*c+2)/3;
				break;
			case 'D':
				while(c%3!=0)
				{
					c+=d;
					a+=b;
				}
				c/=3;
				break;
			case 'd':
				while(c%3!=2)
				{
					c+=d;
					a+=b;
				}
				d*=2;
				c=(2*c-1)/3;
				break;
		}
		b*=3;
	}
	while(a<1.0e+15){a+=b;}
	cout<<a;
	getchar();
	return 0;
}
