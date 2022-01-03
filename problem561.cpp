#include <bits/stdc++.h>
#define c 500000000000
using namespace std;
int main()
{
	long long int result=0,n=2;
	for(int i=1;n<c;n*=2,i++){result+=((c/n)-(c/(2*n)))*i*904962;}
	cout<<result;
	getchar();
	return 0;
}
