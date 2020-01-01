#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int main()
{
	int max_id,max=0;
	ifstream file("p099_base_exp.txt");
	int id=1;
	while(!file.eof())
	{
		string str,str2;
		int base,exp;
		stringstream ss;
		getline(file,str);
		unsigned long long int base,exp;
		int i=0;
		for(;str[i]!=',';i++){str2[i]=str[i];}
		ss<str2;
		ss>>base;
		i++;
		str2="";
		for(int j=0;i<str.length();i++,j++){str2[j]=str[i];}
		ss<<str2;
		ss>>exp;
		long double result=exp*log(base);
		if(result>max)
		{
			max=result;
			max_id=id;
		}
		id++;
	}
	cout<<max_id;
	getchar();
	return 0;
}
