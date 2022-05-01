#include <bits/stdc++.h>
using namespace std;
void increase(vector<int>& v)
{
	int i=0;
	while(v[5-i]==9-i){i++;}
	v[5-i]++;
	for(int j=i-1;j>=0;v[5-j]=v[5-i]+i-j,j--){}
}
int main()
{
	int result=0;
	vector<vector<int> > cubes;
	vector<int> v;
	for(int i=0;i<6;v.push_back(i),i++){}
	for(int i=0;i<182;i++)
	{
		cubes.push_back(v);
		increase(v);
	}
	for(int i=0;i<181;i++)
	{
		for(int j=i+1;j<182;j++)
		{
			vector<int> v1=cubes[i],v2=cubes[j];
			vector<bool> contain1(10,false),contain2(10,false);
			for(int k=0;k<6;contain1[v1[k]]=true,contain2[v2[k]]=true,k++){}
			if((contain1[0] && contain2[1]) || (contain2[0] && contain1[1]))
			{
				if((contain1[0] && contain2[4]) || (contain2[0] && contain1[4]))
				{
					if((contain1[0] && (contain2[6] || contain2[9])) || (contain2[0] && (contain1[6] || contain1[9])))
					{
						if((contain1[1] && (contain2[6] || contain2[9])) || (contain2[1] && (contain1[6] || contain1[9])))
						{
							if((contain1[1] && contain2[8]) || (contain2[1] && contain1[8]))
							{
								if((contain1[2] && contain2[5]) || (contain2[2] && contain1[5]))
								{
									if((contain1[3] && (contain2[6] || contain2[9])) || (contain2[3] && (contain1[6] || contain1[9])))
									{
										if((contain1[4] && (contain2[6] || contain2[9])) || (contain2[4] && (contain1[6] || contain1[9]))){result++;}
									}
								}
							}	
						}
					}
				}
			}
		}
	}
	cout<<result;
	getchar();
	return 0;
}
