#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int result=0;
	ifstream file("problem8.txt");
	int array[20][50];
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<=50;j++)
		{
			if(j==50){char x=file.get();}
			else{array[i][j]=file.get()-'0';}
		}
	}
	file.close();
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<50;j++)
		{
			long long int temp=1;
			for(int k=0;k<=12;k++){temp*=array[i][j+k];}
			result=max(temp,result);
		}
	}
	cout<<result;
	getchar();
	return 0;
}
