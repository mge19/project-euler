#include <bits/stdc++.h>
using namespace std;
class Sudoku{
	public:
		int table[9][9];
		bool available[9][9][9];
		Sudoku();
		bool solve();
		void print();
		vector<int> find_minimum();
		bool correct();
};
Sudoku::Sudoku(){}
void Sudoku::print()
{
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++){cout<<table[i][j];}
		cout<<endl;
	}
	cout<<endl;
}
bool Sudoku::solve()
{
	bool filled,retval;
	do
	{
		filled=false;
		retval=true;
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				if(table[i][j]==0)
				{
					retval=false;
					int x_begin=1,x_end=2,y_begin=1,y_end=2;
					if(i%3==1)
					{
						x_begin=-1;
						x_end=1;
					}
					else if(i%3==2)
					{
						x_begin=-2;
						x_end=-1;
					}
					if(j%3==1)
					{
						y_begin=-1;
						y_end=1;
					}
					else if(j%3==2)
					{
						y_begin=-2;
						y_end=-1;
					}						
					if(table[i+x_begin][j+y_begin]!=0){available[i][j][table[i+x_begin][j+y_begin]-1]=false;}
					if(table[i+x_begin][j+y_end]!=0){available[i][j][table[i+x_begin][j+y_end]-1]=false;}
					if(table[i+x_end][j+y_begin]!=0){available[i][j][table[i+x_end][j+y_begin]-1]=false;}
					if(table[i+x_end][j+y_end]!=0){available[i][j][table[i+x_end][j+y_end]-1]=false;}
					for(int k=0;k<9;k++)
					{
						if(table[i][k]!=0){available[i][j][table[i][k]-1]=false;}
						if(table[k][j]!=0){available[i][j][table[k][j]-1]=false;}						
					}
					int num=0,x=0;
					for(int k=0;k<9;k++)
					{
						if(available[i][j][k])
						{
							num++;
							x=k+1;
						}
					}
					if(num==1)
					{
						table[i][j]=x;
						filled=true;
					}
				}
			}
		}
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
			{
				if(table[i][j]==0)
				{
					int x_begin=1,x_end=2,y_begin=1,y_end=2;
					if(i%3==1)
					{
						x_begin=-1;
						x_end=1;
					}
					else if(i%3==2)
					{
						x_begin=-2;
						x_end=-1;
					}			
					if(j%3==1)
					{
						y_begin=-1;
						y_end=1;
					}
					else if(j%3==2)
					{
						y_begin=-2;
						y_end=-1;
					}
					for(int k=0;k<9;k++)
					{
						if(available[i][j][k])
						{
							if(!available[i][j+y_begin][k] && !available[i][j+y_end][k] && !available[i+x_begin][j][k] && !available[i+x_end][j][k] && 
							!available[i+x_begin][j+y_begin][k] && !available[i+x_begin][j+y_end][k] && !available[i+x_end][j+y_begin][k] && 
							!available[i+x_end][j+y_end][k]){table[i][j]=k+1;}
							else
							{
								int x=0,y=0;
								for(;x<9;x++)
								{
									if(x!=i && available[x][j][k]){break;}
								}
								for(;y<9;y++)
								{
									if(y!=j && available[i][y][k]){break;}
								}
								if(x==9 || y==9){table[i][j]=k+1;}
							}
							if(table[i][j]==k+1)
							{
								filled=true;
								for(int l=0;l<9;l++)
								{
									if(k!=l){available[i][j][l]=false;}
								}
							}
						}
					}
				}
				//cout<<table[i][j];
			}
			//cout<<endl;
		}
		//cout<<endl;
	}while(filled);
	return retval;	
}
bool Sudoku::correct()
{
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			int num=0;
			for(int k=0;k<9;k++){num+=available[i][j][k];}
			if(num==0){return false;}
		}
	}
	return true;
}
vector<int> Sudoku::find_minimum()
{
	vector<int> v;
	int min=11;
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			if(table[i][j]==0)
			{
				vector<int> cur;
				cur.push_back(i);
				cur.push_back(j);
				for(int k=0;k<9;k++)
				{
					if(available[i][j][k]){cur.push_back(k);}
				}
				if(cur.size()<min)
				{
					min=cur.size();
					v=cur;
				}
				if(cur.size()==4){break;}
			}
		}
	}
	return v;
}
int main()
{
	ifstream file("p096_sudoku.txt");
	long int result=0;
	while(!file.eof())
	{
		Sudoku s;
		string str;
		for(int i=-1;i<9;i++)
		{
			if(i==-1)
			{
				for(char x=' ';x!='\n';x=file.get(),str+=x){;}
			}
			else
			{
				for(int j=0;j<9;j++)
				{
					s.table[i][j]=file.get()-'0';
					for(int k=0;k<9;k++)
					{
						if(s.table[i][j]!=0 && k!=s.table[i][j]-1){s.available[i][j][k]=false;}
						else{s.available[i][j][k]=true;}
					}
				}
				file.get();
			}
		}
		queue<Sudoku> q;
		q.push(s);
		while(true)
		{
			s=q.front();
			q.pop();
			if(s.solve())
			{
				cout<<str;
				s.print();
				break;
			}
			else if(s.correct())
			{
				vector<int> v=s.find_minimum();
				int x=v[0],y=v[1];
				for(int i=2;i<v.size();i++)
				{
					Sudoku a=s;
					a.table[x][y]=v[i]+1;
					for(int j=0;j<9;j++)
					{
						if(j!=v[i]){a.available[x][y][j]=false;}
					}
					q.push(a);
				}	
			}
		}
		result+=100*s.table[0][0]+10*s.table[0][1]+s.table[0][2];
	}
	file.close();
	cout<<result;
	getchar();
	return 0;
}
