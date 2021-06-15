#include <bits/stdc++.h>
using namespace std;
int main()
{
	ifstream file("p107_network.txt");
	int** graph=new int*[39];
	long int result=0;
	int val[39];
	bool traversed[40];
	for(int i=0;i<40;i++)
	{
		if(i>0)
		{
			graph[i-1]=new int[i];
			val[i-1]=9999;
		}
		traversed[i]=false;
		char x;
		for(int j=0;j<i;j++)
		{
			graph[i-1][j]=0;
			x=file.get();
			while(x!=',')
			{
				if(x=='-'){}
				else{graph[i-1][j]=10*graph[i-1][j]+x-'0';}
				x=file.get();
			}
			result+=graph[i-1][j];
		}
		while(x!='\n' && !file.eof()){x=file.get();}	
	}
	file.close();
	int i=0; 
	for(int count=0;count<40;count++)
	{
		traversed[i]=true;
		for(int j=1;j<i;j++)
		{
			if(graph[i-1][j]!=0 && !traversed[j]){val[j-1]=min(graph[i-1][j],val[j-1]);}
		}
		for(int j=i;j<39;j++)
		{
			if(graph[j][i]!=0 && !traversed[j+1]) {val[j]=min(graph[j][i],val[j]);}
		}
		int value=9999;
		for(int j=0;j<39;j++)
		{
			if(val[j]<value && !traversed[j+1])
			{
				value=val[j];
				i=j+1;
			}
		}
	}
	delete[] graph;
	for(int i=0;i<39;i++){result-=val[i];}
	cout<<result;
	getchar();
	return 0;
}
