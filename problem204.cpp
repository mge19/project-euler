#include <bits/stdc++.h>
using namespace std;
int main()
{
	vector<long int> numbers;
	long int result=1;
	numbers.push_back(2);
	numbers.push_back(3);
	for(int i=6;i<100;i+=6)
	{
		int x=i-1,y=i+1,j=0;
		while(x%numbers[j]!=0 && numbers[j]<=floor(sqrt(x))){j++;}
		if(numbers[j]>floor(sqrt(x))){numbers.push_back(x);}
		j=0;
		while(y%numbers[j]!=0 && numbers[j]<=floor(sqrt(y))){j++;}
		if(numbers[j]>floor(sqrt(y))){numbers.push_back(y);}
	}
	queue<vector<long long int> > q;
	vector<long long int> v(numbers.size(),0);
	v.push_back(1);
	q.push(v);
	while(!q.empty())
	{
		v=q.front();
		q.pop();
		int i=v.size()-2;
		while(v[i]==0 && i>=0){i--;}
		for(int j=i+1;j<v.size()-1;j++)
		{
			vector<long long int> v1=v;
			while(true)
			{
				v1[j]+=1;
				v1.back()*=numbers[j];
				if(v1.back()>1000000000 || v1.back()<0){break;}
				q.push(v1);
				result++;
			}
		}
	}
	cout<<result;
	getchar();
	return 0;
}
