#include <bits/stdc++.h>
using namespace std;
int main()
{
	int result=0;
	ifstream file("p089_roman.txt");
	while(!file.eof())
	{
		string str;
		file>>str;
		if(str.find("VIIII")!=string::npos){result+=3;}
		else if(str.find("IIII")!=string::npos){result+=2;}
		if(str.find("LXXXX")!=string::npos){result+=3;}
		else if(str.find("XXXX")!=string::npos){result+=2;}
		if(str.find("DCCCC")!=string::npos){result+=3;}
		else if(str.find("CCCC")!=string::npos){result+=2;}
	}
	file.close();
	cout<<result;
	getchar();
	return 0;
}
