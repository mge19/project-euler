#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int main()
{
	int result=0;
	ifstream file("p102_triangles.txt");
	while(true)
	{
		string str;
		getline(file,str);
		int i=0,x1,x2,x3,y1,y2,y3,greater=0,smaller=0,equal=0;
		for(;str[i]!=',';i++){}
		if(str.size()==0){break;}
		else if(str[0]=='-')
		{
			stringstream ss(str.substr(1,i-1));
			ss>>x1;
			x1*=-1;
		}
		else
		{
			stringstream ss(str.substr(0,i));
			ss>>x1;
		}
		int j=i+1;
		for(;str[j]!=',';j++){}
		if(str[i+1]=='-')
		{
			stringstream ss(str.substr(i+2,j-1));
			ss>>y1;
			y1*=-1;
		}
		else
		{
			stringstream ss(str.substr(i+1,j-1));
			ss>>y1;
		}
		j+=1;
		i=j;
		for(;str[j]!=',';j++){}
		if(str[i]=='-')
		{
			stringstream ss(str.substr(i+1,j-1));
			ss>>x2;
			x2*=-1;
		}
		else
		{
			stringstream ss(str.substr(i,j-1));
			ss>>x2;			
		}
		j+=1;
		i=j;
		for(;str[j]!=',';j++){}
		if(str[i]=='-')
		{
			stringstream ss(str.substr(i+1,j-1));
			ss>>y2;
			y2*=-1;
		}
		else
		{
			stringstream ss(str.substr(i,j-1));
			ss>>y2;			
		}
		j+=1;
		i=j;
		for(;str[j]!=',';j++){}
		if(str[i]=='-')
		{
			stringstream ss(str.substr(i+1,j-1));
			ss>>x3;
			x3*=-1;
		}
		else
		{
			stringstream ss(str.substr(i,j-1));
			ss>>x3;			
		}
		if(str[j+1]=='-')
		{
			stringstream ss(str.substr(j+2,str.size()));
			ss>>y3;
			y3*=-1;
		}
		else
		{
			stringstream ss(str.substr(j+1,str.size()));
			ss>>y3;			
		}
		int sum=180*(acos((x1*x2+y1*y2)/(sqrt(x1*x1+y1*y1)*sqrt(x2*x2+y2*y2)))+acos((x1*x3+y1*y3)/(sqrt(x1*x1+y1*y1)*sqrt(x3*x3+y3*y3)))+
		acos((x2*x3+y2*y3)/(sqrt(x2*x2+y2*y2)*sqrt(x3*x3+y3*y3))))/3.14159265;
		result+=sum==360;
	}
	cout<<result;
	file.close();
	getchar();
	return 0;
}
