#include <bits/stdc++.h>
using namespace std;
int main()
{
	ifstream file("p082_matrix.txt");
	long int array[80][80],result=99999999;
	int row=0,col=0;
	array[0][0]=0;
	while(!file.eof())
	{
		char x=file.get();
		if(x==',')
		{
			col++;
			array[row][col]=0;
		}
		else if(x=='\n')
		{
			row++;
			col=0;
			array[row][col]=0;
		}
		else{array[row][col]=10*array[row][col]+x-'0';}
	}
	file.close();
	for(int i=1;i<79;i++)
	{
		long int sums[80];
		for(int j=0;j<80;j++)
		{
			sums[j]=99999999;
			for(int k=0;k<80;k++)
			{
				long int y=array[k][i-1];
				if(k<j)
				{
					for(int l=k;l<j;l++){y+=array[l][i];}
				}
				else if(k>j)
				{
					for(int l=k;l>j;l--){y+=array[l][i];}
				}
				sums[j]=min(sums[j],y);
			}
		}
		for(int j=0;j<80;j++)
		{
			array[j][i]+=sums[j];
			if(i==78){result=min(result,array[j][i]+array[j][i+1]);}
		}
	}
	cout<<result;
	getchar();
	return 0;
}
