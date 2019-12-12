#include <bits/stdc++.h>
using namespace std;
int main()
{
	ifstream file("p081_matrix.txt");
	long int**numbers=new long int*[80];
	for(int i=0;i<80;i++)
	{
		numbers[i]=new long int[80];
		for(int j=0;j<80;j++)
		{
			numbers[i][j]=0;
			char x=file.get();
			while(!(x==',' || x=='\n' || file.eof()))
			{
				numbers[i][j]=10*numbers[i][j]+x-'0';
				x=file.get();
			}
			if(i==0 && j>0){numbers[i][j]+=numbers[i][j-1];}
			else if(i>0 && j==0){numbers[i][j]+=numbers[i-1][j];}
			else if(!(i==0 && j==0)){numbers[i][j]+=min(numbers[i-1][j],numbers[i][j-1]);}
		}
	}
	delete[] numbers;
	file.close();
	cout<<numbers[79][79];
	getchar();
	return 0;
}
