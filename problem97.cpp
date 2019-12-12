#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int x=65536;
	for(long int i=17;i<=7830457;i++){x=(2*x)%10000000000;}
	cout<<(28433*x+1)%10000000000;
	getchar();
	return 0;
}
