#include <bits/stdc++.h>
using namespace std;
int main()
{
	int result=0;
	vector<bool> visited(99,false);	
	for(int i=2;i<=100;i++)
	{
		if(!visited[i-2])
		{	
			int x=i,k=1;
			for(;x<=100;visited[x-2]=true,x*=i,k++){}
			if(k!=2)
			{
				vector<int> numbers;
				for(int j=1;j<k-1;j++)
				{
					set<int> powers;
					for(int y=j+1;y<k;y++)
					{
						for(int z=j*100+(y-((j*100)%y));z<=(j+1)*100;powers.insert(z),z+=y){}
					}
					numbers.push_back(powers.size());
				}
				for(int j=0;j<k-2;j++){result+=numbers[j];}
			}
			result+=99;
		}
	}
	cout<<result;
	getchar();
	return 0;
}
