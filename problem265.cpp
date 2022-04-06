#include <bits/stdc++.h>
using namespace std;
class Number{
	public:
		int digits[32];
		bool available[32];
		Number()
		{
			for(int i=0;i<5;i++){digits[i]=0;}
			digits[5]=1;
			for(int i=6;i<31;i++){digits[i]=2;}
			digits[31]=1;
			for(int i=2;i<32;i++){available[i]=false;}
			available[0]=true;
			available[1]=true;
			available[16]=true;
		}
};
int main()
{
	queue<Number> q;
	Number n;
	q.push(n);
	long long int result=0;
	while(!q.empty())
	{
		n=q.front();
		q.pop();
		int i=0;
		while(i<32 && n.digits[i]!=2){i++;}
		if(i==32)
		{
			if(!n.available[2*n.digits[30]+4*n.digits[29]+8*n.digits[28]+16*n.digits[27]+1])
			{
				n.available[2*n.digits[30]+4*n.digits[29]+8*n.digits[28]+16*n.digits[27]+1]=true;
				if(!n.available[4*n.digits[30]+8*n.digits[29]+16*n.digits[28]+2])
				{
					n.available[4*n.digits[30]+8*n.digits[29]+16*n.digits[28]+2]=true;
					if(!n.available[8*n.digits[30]+16*n.digits[29]+4])
					{
						n.available[8*n.digits[30]+16*n.digits[29]+4]=true;
						if(!n.available[16*n.digits[30]+8])
						{
							n.available[16*n.digits[30]+8]=true;
							long int x=1,a=0;
							for(int j=31;j>=5;j--)
							{
								if(n.digits[j]==1){a+=x;}
								x*=2;
							} 
							result+=a;							
						}
					}
				}
			}
		}	
		else
		{
			int j=0;
			for(;n.digits[j]!=2;j++){}
			if(!n.available[1+2*n.digits[j-1]+4*n.digits[j-2]+8*n.digits[j-3]+16*n.digits[j-4]])
			{
				Number n1=n;
				n1.digits[j]=1;
				n1.available[1+2*n.digits[j-1]+4*n.digits[j-2]+8*n.digits[j-3]+16*n.digits[j-4]]=true;
				q.push(n1);
			}
			if(!n.available[2*n.digits[j-1]+4*n.digits[j-2]+8*n.digits[j-3]+16*n.digits[j-4]])
			{
				Number n1=n;
				n1.digits[j]=0;
				n1.available[2*n.digits[j-1]+4*n.digits[j-2]+8*n.digits[j-3]+16*n.digits[j-4]]=true;
				q.push(n1);
			}			
		}
	}
	cout<<result;
	getchar();
	return 0;
}
