#include <bits/stdc++.h>
int main()
{
	std::ifstream file("problem18.txt");
	int result=0,**numbers=new int*[15];
	for(int i=0;i<15;i++)
	{
		numbers[i]=new int[i+1];
		for(int j=0;j<=i;j++)
		{
			file>>numbers[i][j];
			if(i>0 && j==0){numbers[i][j]+=numbers[i-1][j];}
			else if(i>0 && j==i){numbers[i][j]+=numbers[i-1][j-1];}
			else if(!(i==0 && j==0)){numbers[i][j]+=std::max(numbers[i-1][j-1],numbers[i-1][j]);}
			if(i==14){result=std::max(numbers[i][j],result);}
		}
	}
	delete[] numbers;
	file.close();
	std::cout<<result;
	getchar();
	return 0;
}
