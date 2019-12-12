#include <bits/stdc++.h>
using namespace std;
int main()
{
	ifstream file("problem11.txt");
	int numbers[20][20];
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<20;file>>numbers[i][j],j++){}
	}
	file.close();
	long int maxnum=0;
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<20;j++)
		{
			long int result;
			if(i<=16)
			{
				result=numbers[i][j]*numbers[i+1][j]*numbers[i+2][j]*numbers[i+3][j];
				maxnum=max(result,maxnum);				
			}
			if(i<=16 && j>=3)
			{
				result=numbers[i][j]*numbers[i+1][j-1]*numbers[i+2][j-2]*numbers[i+3][j-3];	
				maxnum=max(result,maxnum);
			}
			if(j<=16 && i<=16)
			{
				result=numbers[i][j]*numbers[i+1][j+1]*numbers[i+2][j+2]*numbers[i+3][j+3];
				maxnum=max(result,maxnum);
			}
			if(j<=16)
			{
				result=numbers[i][j]*numbers[i][j+1]*numbers[i][j+2]*numbers[i][j+3];
				maxnum=max(result,maxnum);
			}			
		}
	}
	cout<<maxnum;
	getchar();
	return 0;
}
