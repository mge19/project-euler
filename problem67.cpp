#include <bits/stdc++.h>
using namespace std;
int main()
{
	ifstream file("p067_triangle.txt");
	int result=0,**numbers=new int*[100];
	for(int i=0;i<100;i++)
	{
		numbers[i]=new int[i+1];
		for(int j=0;j<=i;j++)
		{
			file>>numbers[i][j];
			if(i>0 && j==0){numbers[i][j]+=numbers[i-1][j];}
			else if(i>0 && j==i){numbers[i][j]+=numbers[i-1][j-1];}
			else if(!(i==0 && j==0)){numbers[i][j]+=max(numbers[i-1][j-1],numbers[i-1][j]);}
			if(i==99){result=max(numbers[i][j],result);}
		}
	}
	delete[] numbers;
	file.close();
	cout<<result;
	getchar();
	return 0;
}
