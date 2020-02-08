#include <bits/stdc++.h>
using namespace std;
int main()
{
	vector<long long int> numbers;
	numbers.push_back(30);	
	numbers.push_back(70);
	for(int i=0;i<4;i++)
	{
		int n=numbers.size();
		for(int j=0;j<n;j++)
		{
			int u=1,v=100;
			if(i==3)
			{
				u=10;
				v=20;
			}
			for(int k=u;k<v;k++)
			{
				long int s=100;
				for(int a=0;a<i;s*=100,a++){}
				long long int b=s*k+numbers[0];
				string str;
				stringstream ss;
				ss<<b*b;
				str=ss.str();
				if(str.size()>=2*i+5 && str[str.size()-2*i-5]-'0'==8-i && i<3){numbers.push_back(b);}
				if(i==3)
				{
					int x=1;
					for(;str[2*x]-'0'==x+1 && x<5;x++){}
					if(x==5)
					{
						cout<<b;
						exit(1);
					}
				}
			}
			numbers.erase(numbers.begin());
		}
	}
	return 0;
}
