#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main()
{
	long int result=0;
	ifstream file("p105_sets.txt");
	while(!file.eof())
	{
		char x=' ';
		set<int> sums;
		vector<int> numbers;
		while(x!='\n' && !file.eof())
		{
			int n=0;
			x=file.get();
			while(x!=',' && x!='\n' && !file.eof())
			{
				n=10*n+x-'0';
				x=file.get();
			}
			numbers.push_back(n);
		}
		sort(numbers.begin(),numbers.end());
		vector<vector<int> > indexes;
		for(int i=0;i<numbers.size();i++)
		{
			vector<int> index;
			index.push_back(i);
			indexes.push_back(index);
		}
		for(int i=0;indexes[i].size()!=numbers.size();i++)
		{
			for(int j=indexes[i][indexes[i].size()-1]+1;j<numbers.size();j++)
			{
				vector<int> index=indexes[i];
				index.push_back(j);
				indexes.push_back(index);
			}
		}
		for(int i=0;i<numbers.size();indexes.erase(indexes.begin()),i++){}
		int prev_size=1,prev_sum=numbers[numbers.size()-1],sum;
		bool valid=true;
		for(int i=0;i<indexes.size();i++)
		{
			int next_size=indexes[i].size(),n=sums.size();
			sum=0;
			for(int j=0;j<next_size;sum+=numbers[indexes[i][j]],j++){}
			sums.insert(sum);
			int m=sums.size();
			if(n==m){valid=false;}
			if(!valid){break;}
			if(next_size!=prev_size && prev_sum>=sum){valid=false;}
			if(!valid){break;}
			prev_size=next_size;
			prev_sum=sum;
		}
		if(valid){result+=sum;}
	}
	file.close();
	cout<<result;
	getchar();
	return 0;
}
