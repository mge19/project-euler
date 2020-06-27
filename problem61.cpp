#include <bits/stdc++.h>
using namespace std;
int main()
{
	vector<vector<int> > numbers;
	for(int i=0;i<6;i++)
	{
		vector<int> v;
		numbers.push_back(v);
	}
	for(int i=1;i*(i+1)/2<10000;i++)
	{
		if(i*(i+1)/2>1000 && (i*(i+1)/2)%100>9)
		{
			numbers[0].push_back(i*(i+1)/2);
			if(i%2==1){numbers[3].push_back(i*(i+1)/2);}
		}	
	}
	for(int i=1;i*i<10000;i++)
	{
		if(i*i>1000 && (i*i)%100>9){numbers[1].push_back(i*i);}
	}
	for(int i=1;i*(3*i-1)/2<10000;i++)
	{
		if(i*(3*i-1)/2>1000 && (i*(3*i-1)/2)%100>9){numbers[2].push_back(i*(3*i-1)/2);}
	}
	for(int i=1;i*(5*i-3)/2<10000;i++)
	{
		if(i*(5*i-3)/2>1000 && (i*(5*i-3)/2)%100>9){numbers[4].push_back(i*(5*i-3)/2);}
	}
	for(int i=1;i*(3*i-2)<10000;i++)
	{
		if(i*(3*i-2)>1000 && (i*(3*i-2))%100>9){numbers[5].push_back(i*(3*i-2));}
	}
	for(int i=0;i<numbers[5].size();i++)
	{
		queue<vector<pair<int,int> > > q;
		vector<pair<int,int> > v;
		v.push_back(make_pair(numbers[5][i],5));
		q.push(v);
		while(!q.empty())
		{
			v=q.front();
			q.pop();
			if(v.size()==6 && v[0].first/100==v[5].first%100)
			{
				int result=v[0].first+v[1].first+v[2].first+v[3].first+v[4].first+v[5].first;
				cout<<v[0].first<<"+"<<v[1].first<<"+"<<v[2].first<<"+"<<v[3].first<<"+"<<v[4].first<<"+"<<v[5].first<<"="<<result;
				getchar();
				exit(1);
			}
			else if(v.size()!=6)
			{
				for(int j=4;j>=0;j--)
				{
					bool found=false;
					for(int k=0;k<v.size() && !found;k++)
					{
						if(v[k].second==j){found=true;}
					}
					if(!found)
					{
						for(int k=0;k<numbers[j].size();k++)
						{
							bool exist=false;
							for(int l=0;l<v.size() && !exist;l++)
							{
								if(v[l].first==numbers[j][k]){exist=true;}
							}							
							if(!exist && v[v.size()-1].first%100==numbers[j][k]/100)
							{
								vector<pair<int,int> > x=v;
								x.push_back(make_pair(numbers[j][k],j));
								q.push(x);
							}
						}	
					}
				}
			}
		}
	}
	return 0;
}
