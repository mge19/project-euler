#include <bits/stdc++.h>
using namespace std;
bool asalmi(long int number)
{
	int x=sqrt(number);
	for(int i=3;i<=x;i+=2)
	{
		if(number%i==0){return false;}
	}
	return true;
}
int main()
{
	vector<bool> asal(10000000,true);
	vector<long int> asallar;
	long int result=999999;
	queue<vector<long int> > q;
	for(long int i=2;i<10000000;i++)
	{
		if(asal[i-1])
		{
			if(i<10000 && i!=2 && i!=5)
			{
				asallar.push_back(i);
				vector<long int> v;
				v.push_back(i);
				q.push(v);
			}
			for(long int j=2*i;j<10000000;asal[j-1]=false,j+=i){}
		}
	}
	while(!q.empty())
	{
		vector<long int> v=q.front();
		q.pop();
		for(int i=0;i<v.size();i++){cout<<v[i]<<" ";}
		cout<<endl;
		if(v.size()==5){result=min(result,v[0]+v[1]+v[2]+v[3]+v[4]);}
		else
		{	
			for(int i=0;i<asallar.size();i++)
			{
				if(asallar[i]>v[v.size()-1])
				{
					stringstream ss1;
					ss1<<asallar[i];
					string str1=ss1.str();
					int j=0;
					for(;j<v.size();j++)
					{
						stringstream ss2;
						ss2<<v[j];
						string str2=ss2.str();
						long int x=atoi((str1+str2).c_str()),y=atoi((str2+str1).c_str());
						if(x<10000000)
						{
							if(!asal[x-1]){break;}
						}
						else
						{
							if(!asalmi(x)){break;}
						}
						if(y<10000000)
						{
							if(!asal[y-1]){break;}
						}
						else
						{
							if(!asalmi(y)){break;}
						}
					}
					if(j==v.size())
					{
						vector<long int> v1=v;
						v1.push_back(asallar[i]);
						q.push(v1);
					}
				}
			}
		}
	}
	cout<<result;
	getchar();
	return 0;
}
