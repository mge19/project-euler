#include <bits/stdc++.h>
using namespace std;
int main()
{
	int x=1,a=2,digits=1;
	double theta=2;
	long int n=10;
	cout<<"2.";
	for(int step=1;x<=24;step++)
	{
		while(true)
		{
			if(a==n)
			{
				x++;
				digits++;
				n*=10;
			}
			double b=theta+a*pow(0.1,x),new_theta=b;
			for(int i=0;i<step;i++){b=floor(b)*(b-floor(b)+1);}
			if(a==floor(b))
			{
				theta=new_theta;
				cout<<a;
				x+=digits;
				break;
			}
			else{a++;}
		}
	}
	getchar();
	return 0;
}
