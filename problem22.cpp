#include <bits/stdc++.h>
long int calculate(std::string str)
{
	long int result=0;
	for(int i=0;i<str.length();i++){result+=str[i]-'A'+1;}
	return result;
}
int main()
{
	std::ifstream file("p022_names.txt");
	long int result=0;
	std::list<std::string> names;
	while(!file.eof())
	{
		char x=file.get();
		std::string str;
		while(x!=',' && !file.eof())
		{
			if(x>='A' && x<='Z'){str.push_back(x);}
			x=file.get();
		}
		names.push_back(str);
	}
	names.sort();
	long int i=1;
	for(std::list<std::string>::iterator it=names.begin();it!=names.end();++it,++i){result+=calculate(*it)*i;}
	std::cout<<result;
	getchar();
	return 0;
}                                                                                                                                                                                                                                                            
