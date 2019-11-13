#include <bits/stdc++.h>
int main()
{
	long long int route[21][21];
	for(int i=0;i<=20;i++)
	{
		for(int j=0;j<=20;j++){route[i][j]=(i==0 || j==0)?1:route[i][j-1]+route[i-1][j];}
	}
	std::cout<<route[20][20];
	getchar();
	return 0;
}
