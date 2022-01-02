#include <bits/stdc++.h>
#include <cmath>
#define pi 3.14159265
using namespace std;
int main()
{
	double n=1;
	while(50*(1+((n+1-sqrt(2*n))*(n-1)/(n*n+1))-pi/4-atan((n-1)/sqrt(2*n))+atan((n-1)/(n+1)))/(1-pi/4)<=99.9){n++;}
	cout<<n;
	getchar();
	return 0;	
}

