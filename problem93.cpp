#include <bits/stdc++.h>
using namespace std;
int main()
{
	int result,maxlimit=0;
	for(double a=1;a<=6;a++)
	{
		for(double b=a+1;b<=7;b++)
		{
			for(double c=b+1;c<=8;c++)
			{
				for(double d=c+1;d<=9;d++)
				{
					vector<vector<double> > numbers;
					double n[4]={a,b,c,d};
					map<double,bool> calculated;
					for(int i=0;i<4;i++)
					{
						for(int j=i+1;j<4;j++)
						{
							vector<double> values;
							values.push_back(n[i]+n[j]);
							values.push_back(n[i]-n[j]);
							values.push_back(n[j]-n[i]);
							values.push_back(n[i]*n[j]);
							values.push_back(n[i]/n[j]);
							if(n[i]!=1){values.push_back(n[j]/n[i]);}
							numbers.push_back(values);
						}
					}
					vector<double> values[4];
					for(int i=0;i<6;i++)
					{
						for(int j=0;j<numbers[i].size();j++)
						{
							for(int k=0;k<numbers[5-i].size();k++)
							{
								double x=numbers[i][j]*numbers[5-i][k];
								if(x>0 && x-trunc(x)==0){calculated[x]=true;}
								x=numbers[i][j]+numbers[5-i][k];
								if(x>0 && x-trunc(x)==0){calculated[x]=true;}
								x=numbers[i][j]-numbers[5-i][k];
								if(x>0 && x-trunc(x)==0){calculated[x]=true;}
								x=numbers[i][j]/numbers[5-i][k];
								if(x>0 && x-trunc(x)==0){calculated[x]=true;}
								x=numbers[5-i][k]-numbers[i][j];
								if(x>0 && x-trunc(x)==0){calculated[x]=true;}	
								x=numbers[5-i][k]/numbers[i][j];
								if(x>0 && x-trunc(x)==0){calculated[x]=true;}											
							}
						}
						if(i>2)
						{
							for(int j=0;j<numbers[i].size();j++)
							{
								if(i==3)
								{
									values[3].push_back(numbers[i][j]+n[0]);
									values[3].push_back(numbers[i][j]-n[0]);
									values[3].push_back(n[0]-numbers[i][j]);
									values[3].push_back(numbers[i][j]*n[0]);
									values[3].push_back(numbers[i][j]/n[0]);
									values[3].push_back(n[0]/numbers[i][j]);
								}
								else if(i==4)
								{
									values[2].push_back(numbers[i][j]+n[0]);
									values[2].push_back(numbers[i][j]-n[0]);
									values[2].push_back(n[0]-numbers[i][j]);
									values[2].push_back(numbers[i][j]*n[0]);
									values[2].push_back(numbers[i][j]/n[0]);	
									values[2].push_back(n[0]/numbers[i][j]);								
								}
								else
								{
									values[1].push_back(numbers[i][j]+n[0]);
									values[1].push_back(numbers[i][j]-n[0]);
									values[1].push_back(n[0]-numbers[i][j]);
									values[1].push_back(numbers[i][j]*n[0]);
									values[1].push_back(numbers[i][j]/n[0]);
									values[1].push_back(n[0]/numbers[i][j]);										
								}
							}
						}
						if(i==1 || i==2 || i==5)
						{
							for(int j=0;j<numbers[i].size();j++)
							{
								if(i==1)
								{
									values[3].push_back(numbers[i][j]+n[1]);
									values[3].push_back(numbers[i][j]-n[1]);
									values[3].push_back(n[1]-numbers[i][j]);
									values[3].push_back(numbers[i][j]*n[1]);
									values[3].push_back(numbers[i][j]/n[1]);
									values[3].push_back(n[1]/numbers[i][j]);
								}
								else if(i==2)
								{
									values[2].push_back(numbers[i][j]+n[1]);
									values[2].push_back(numbers[i][j]-n[1]);
									values[2].push_back(n[1]-numbers[i][j]);
									values[2].push_back(numbers[i][j]*n[1]);
									values[2].push_back(numbers[i][j]/n[1]);	
									values[2].push_back(n[1]/numbers[i][j]);								
								}
								else
								{
									values[0].push_back(numbers[i][j]+n[1]);
									values[0].push_back(numbers[i][j]-n[1]);
									values[0].push_back(n[1]-numbers[i][j]);
									values[0].push_back(numbers[i][j]*n[1]);
									values[0].push_back(numbers[i][j]/n[1]);	
									values[0].push_back(n[1]/numbers[i][j]);										
								}
							}							
						}
						if(i==0 || i==2 || i==4)
						{
							for(int j=0;j<numbers[i].size();j++)
							{
								if(i==0)
								{
									values[3].push_back(numbers[i][j]+n[2]);
									values[3].push_back(numbers[i][j]-n[2]);
									values[3].push_back(n[2]-numbers[i][j]);
									values[3].push_back(numbers[i][j]*n[2]);
									values[3].push_back(numbers[i][j]/n[2]);
									values[3].push_back(n[2]/numbers[i][j]);
								}
								else if(i==2)
								{
									values[1].push_back(numbers[i][j]+n[2]);
									values[1].push_back(numbers[i][j]-n[2]);
									values[1].push_back(n[2]-numbers[i][j]);
									values[1].push_back(numbers[i][j]*n[2]);
									values[1].push_back(numbers[i][j]/n[2]);	
									values[1].push_back(n[2]/numbers[i][j]);								
								}
								else
								{
									values[0].push_back(numbers[i][j]+n[2]);
									values[0].push_back(numbers[i][j]-n[2]);
									values[0].push_back(n[2]-numbers[i][j]);
									values[0].push_back(numbers[i][j]*n[2]);
									values[0].push_back(numbers[i][j]/n[2]);
									values[0].push_back(n[2]/numbers[i][j]);										
								}
							}							
						}
						if(i==0 || i==1 || i==3)
						{
							for(int j=0;j<numbers[i].size();j++)
							{
								if(i==0)
								{
									values[2].push_back(numbers[i][j]+n[3]);
									values[2].push_back(numbers[i][j]-n[3]);
									values[2].push_back(n[3]-numbers[i][j]);
									values[2].push_back(numbers[i][j]*n[3]);
									values[2].push_back(numbers[i][j]/n[3]);
									values[2].push_back(n[3]/numbers[i][j]);
								}
								else if(i==1)
								{
									values[1].push_back(numbers[i][j]+n[3]);
									values[1].push_back(numbers[i][j]-n[3]);
									values[1].push_back(n[3]-numbers[i][j]);
									values[1].push_back(numbers[i][j]*n[3]);
									values[1].push_back(numbers[i][j]/n[3]);
									values[1].push_back(n[3]/numbers[i][j]);								
								}
								else
								{
									values[0].push_back(numbers[i][j]+n[3]);
									values[0].push_back(numbers[i][j]-n[3]);
									values[0].push_back(n[3]-numbers[i][j]);
									values[0].push_back(numbers[i][j]*n[3]);
									values[0].push_back(numbers[i][j]/n[3]);
									values[0].push_back(n[3]/numbers[i][j]);										
								}
							}							
						}
					}
					for(int j=0;j<4;j++)
					{
						for(int i=0;i<values[j].size();i++)
						{
							double x=values[j][i]*n[j];
							if(x>0 && x-trunc(x)==0){calculated[x]=true;}
							x=values[j][i]+n[j];
							if(x>0 && x-trunc(x)==0){calculated[x]=true;}
							x=values[j][i]-n[j];
							if(x>0 && x-trunc(x)==0){calculated[x]=true;}
							x=values[j][i]/n[j];
							if(x>0 && x-trunc(x)==0){calculated[x]=true;}
							x=n[j]-values[j][i];
							if(x>0 && x-trunc(x)==0){calculated[x]=true;}
							x=n[j]/values[j][i];
							if(x>0 && x-trunc(x)==0){calculated[x]=true;}
						}
					}
					int limit=1;
					while(calculated.count(limit)>0){limit++;}
					if(limit>=maxlimit)
					{
						maxlimit=limit;
						result=1000*a+100*b+10*c+d;
					}
				}
			}
		}
	}
	cout<<result;
	getchar();
	return 0;
}
