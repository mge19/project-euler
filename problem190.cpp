#include <bits/stdc++.h>
using namespace std;
int main()
{
	int result=1;
	for(int m=3;m<=15;m++)
	{
		double matrix[m-1][m],value=1,first=m;
		for(int i=0;i<m-1;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(i==j){matrix[i][j]=i+3;}
				else if(j==m-1){matrix[i][j]=m*(i+2);}
				else{matrix[i][j]=i+2;}
			}
		}
		for(int i=0;i<m-2;i++)
		{
			for(int j=i+1;j<m-1;j++)
			{
				double x=matrix[j][i];
				for(int k=i;k<m;k++){matrix[j][k]-=matrix[i][k]*x/matrix[i][i];}
			}
		}
		for(int i=m-1;i>=0;i--)
		{
			for(int j=m-2;j>=i;j--)
			{
				if(j==i){matrix[i][m-1]/=matrix[i][j];}
				else{matrix[i][m-1]-=matrix[i][j]*matrix[j][m-1];}
			}
		}
		for(int i=0;i<m-1;i++)
		{
			value*=pow(matrix[i][m-1],i+2);
			first-=matrix[i][m-1];
		}
		result+=trunc(value*first);
	}
	cout<<result;
	getchar();
	return 0;
}
