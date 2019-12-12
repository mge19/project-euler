#include <bits/stdc++.h>
using namespace std;
long int calculate(string str)
{
	long int result=0;
	for(int i=0;i<str.length();i++){result+=str[i]-'A'+1;}
	return result;
}
int main()
{
	ifstream file("p022_names.txt");
	long int result=0;
	list<string> names;
	while(!file.eof())
	{
		char x=file.get();
		string str;
		while(x!=',' && !file.eof())
		{
			if(x>='A' && x<='Z'){str.push_back(x);}
			x=file.get();
		}
		names.push_back(str);
	}
        file.close();
	names.sort();
	long int i=1;
	for(list<string>::iterator it=names.begin();it!=names.end();++it,++i){result+=calculate(*it)*i;}
        cout<<result;
	getchar();
	return 0;
}
