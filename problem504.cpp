#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n[100][100];
	for(int i=1;i<=100;i++)
	{
		for(int j=1;j<=100;j++)
		{
			n[i-1][j-1]=0;
			for(int x=1;x<i;x++)
			{
				n[i-1][j-1]+=floor(j-j*x/i);
				if(floor(j-j*x/i)==j-j*x/i){n[i-1][j-1]--;}
			}
		}
	}
	long int result=0;
	for(int a=1;a<=100;a++)
	{
		for(int b=1;b<=100;b++)
		{
			for(int c=1;c<=100;c++)
			{
				for(int d=1;d<=100;d++)
				{
					long int lattices=b+d+a+c-3+n[a-1][b-1]+n[c-1][b-1]+n[c-1][d-1]+n[a-1][d-1];  
					if(floor(sqrt(lattices))==sqrt(lattices)){result++;}
				}
			}
		}
	}
	cout<<result;
	getchar();
	return 0;
}
