#include <bits/stdc++.h>
using namespace std;
int main()
{
	int digits[302],result=0,carry=0;
	for(int i=0;i<297;i++){digits[i]=0;}
	digits[297]=3,digits[298]=2,digits[299]=7,digits[300]=6,digits[301]=8;
	for(int i=16;i<=1000;i++)
	{
		for(int j=301;j>=0;j--)
		{
			digits[j]=2*digits[j]+carry;
			carry=digits[j]/10;
			digits[j]%=10;
		}
	}
	for(int i=0;i<=301;i++){result+=digits[i];}
        cout<<result;
	getchar();
	return 0;
}

