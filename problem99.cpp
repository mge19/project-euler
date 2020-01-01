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
		char* str2=new char[i],*str3=new char[str.length()-i-1];
		for(int x=0;x<i;x++){str2[x]=str[x];}
		i++;
		for(int j=0;i<str.length();i++,j++){str3[j]=str[i];}
		base=atoi(str2);
		exp=atoi(str3);
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
