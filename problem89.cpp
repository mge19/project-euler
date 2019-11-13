#include <bits/stdc++.h>
int main()
{
	int result=0;
	std::ifstream file("p089_roman.txt");
	while(!file.eof())
	{
		std::string str;
		file>>str;
		if(str.find("VIIII")!=std::string::npos){result+=3;}
		else if(str.find("IIII")!=std::string::npos){result+=2;}
		if(str.find("LXXXX")!=std::string::npos){result+=3;}
		else if(str.find("XXXX")!=std::string::npos){result+=2;}
		if(str.find("DCCCC")!=std::string::npos){result+=3;}
		else if(str.find("CCCC")!=std::string::npos){result+=2;}
	}
	file.close();
	std::cout<<result;
	getchar();
	return 0;
}
