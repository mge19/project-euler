#include <bits/stdc++.h>
using namespace std;
int main()
{
	vector<long long int> tiles2(51,0),tiles3(51,0),tiles4(51,0);
	tiles2[0]=1;tiles3[0]=1;tiles4[0]=1;
	for(int i=1;i<=50;i++)
	{
		tiles2[i]+=tiles2[i-1];
		tiles3[i]+=tiles3[i-1];
		tiles4[i]+=tiles4[i-1];
		if(i>=2){tiles2[i]+=tiles2[i-2];}
		if(i>=3){tiles3[i]+=tiles3[i-3];}
		if(i>=4){tiles4[i]+=tiles4[i-4];}
	}
	cout<<tiles2[50]+tiles3[50]+tiles4[50]-3;
	getchar();
	return 0;
}
