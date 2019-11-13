#include <bits/stdc++.h>
int calculate(long int x)
{
	int result=0;
	long int y=x;
	while(y!=0)
	{
		result+=(y%10)*(y%10);
		y/=10;
	}
	return result;
}
int main()
{
	bool correct[567],visited[567];
	long int result=1;
	for(int i=0;i<567;i++)
	{
		visited[i]=false;
		correct[i]=false;
	}
	correct[88]=true;
	visited[0]=true;
	visited[88]=true;
	for(long int i=2;i<10000000;i++)
	{
		if(i<=567)
		{
			int j=i;
			std::vector<int> values;
			while(!visited[j-1])
			{
				visited[j-1]=true;
				values.push_back(j);
				j=calculate(j);
			}
			while(!values.empty())
			{
				correct[values.back()-1]=correct[j-1];
				values.pop_back();
				result+=correct[j-1];
			}
		}
		else
		{result+=correct[calculate(i)-1];}
	}
	std::cout<<result;
	getchar();
	return 0;
}
