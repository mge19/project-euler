#include <bits/stdc++.h>
#include <cmath>
#include <cstdlib>
using namespace std;
int main()
{
	int max_id,max=0;
	ifstream file("p099_base_exp.txt");
	int id=1;
	while(!file.eof())
	{
		string str;
		getline(file,str);
		unsigned long long int base,exp;
		int i=0;
		for(;str[i]!=',';i++){}
		char* str2=new char[i];
		for(int x=0;x<i;x++){str2[x]=str[x];}
		i++;
		base=atoi(str2);
		str2=new char[str.length()-i];
		for(int j=0;i<str.length();i++,j++){str2[j]=str[i];}
		exp=atoi(str2);
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
