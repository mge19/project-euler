#include <bits/stdc++.h>
using namespace std;
int main()
{
	map<vector<int>,vector<long long int> > m;
	long long int result=1;
	while(true)
	{
		vector<int> v(10,0);
		stringstream ss;
		ss<<result*result*result;
		string str=ss.str();
		for(int i=0;i<str.size();i++){v[str[i]-'0']++;}
		m[v].push_back(result);
		if(m[v].size()==5)
		{
			result=m[v][0];
			break;
		}
		else{result++;}
	}
	cout<<result*result*result;
	getchar();
	return 0;
}
