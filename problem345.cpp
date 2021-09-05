#include <bits/stdc++.h>
using namespace std;
class Number{
	public:
		int first,second,status=0;
};
int main()
{
	Number matrix[15][15];
	int val[15],result=0;
	ifstream file("problem345.txt");
	for(int i=0;i<15;i++)
	{
		val[i]=0;
		for(int j=0;j<15;j++)
		{
			matrix[i][j].first=0;
			for(int k=0;k<3;k++)
			{
				char x=file.get();
				if(x!=' '){matrix[i][j].first=10*matrix[i][j].first+x-'0';}
			}
			val[i]=max(val[i],matrix[i][j].first);
			if(j<14){file.get();}
		}
		if(i<14){file.get();}
	}
	file.close();
	for(int i=0;i<15;i++)
	{
		for(int j=0;j<15;j++){matrix[i][j].second=val[i]-matrix[i][j].first;}
	}
	for(int i=0;i<15;i++)
	{
		val[i]=999;
		for(int j=0;j<15;j++){val[i]=min(val[i],matrix[j][i].second);}
	}
	for(int i=0;i<15;i++)
	{
		for(int j=0;j<15;j++){matrix[j][i].second=matrix[j][i].second-val[i];}
	}
	while(true)
	{
		int number_of_assignments=0;
		for(int i=0;i<15;i++)
		{
			int number_of_zeroes=0,col=0;
			for(int j=0;j<15 && number_of_zeroes<2;j++)
			{
				if(matrix[i][j].second==0 && matrix[i][j].status==0)
				{
					number_of_zeroes++;
					col=j;
				}
			}
			if(number_of_zeroes==1)
			{
				number_of_assignments++;
				matrix[i][col].status=1;
				for(int k=0;k<15;k++)
				{
					if(matrix[k][col].second==0 && matrix[k][col].status==0){matrix[k][col].status=2;}
				}
			}
		}
		for(int i=0;i<15;i++)
		{
			int number_of_zeroes=0,row=0;
			for(int j=0;j<15 && number_of_zeroes<2;j++)
			{
				if(matrix[j][i].second==0 && matrix[j][i].status==0)
				{
					number_of_zeroes++;
					row=j;
				}
			}
			if(number_of_zeroes==1)
			{
				number_of_assignments++;
				matrix[row][i].status=1;
				for(int k=0;k<15;k++)
				{
					if(matrix[row][k].second==0 && matrix[row][k].status==0){matrix[row][k].status=2;}
				}
			}
		}
		if(number_of_assignments==15)
		{
			for(int i=0;i<15;i++)
			{
				for(int j=0;j<15;j++)
				{
					if(matrix[i][j].status==1){result+=matrix[i][j].first;}
				}
			}
			break;
		}
		else
		{
			bool marked_rows[15],marked_cols[15],marked;
			for(int i=0;i<15;i++)
			{
				marked_rows[i]=false;
				marked_cols[i]=false;
			}
			for(int i=0;i<15;i++)
			{
				int j=0;
				for(;j<15 && matrix[i][j].status!=1;j++){}
				if(j==15)
				{
					marked_rows[i]=true;
					marked=true;
				}	
			}
			do
			{
				marked=false;
				for(int i=0;i<15;i++)
				{
					if(marked_rows[i])
					{
						for(int j=0;j<15;j++)
						{
							if(matrix[i][j].second==0 && !marked_cols[j])
							{
								marked_cols[j]=true;
								marked=true;
							}
						}
					}
				}
				if(marked)
				{
					for(int i=0;i<15;i++)
					{
						if(marked_cols[i])
						{
							for(int j=0;j<15;j++)
							{
								if(matrix[j][i].status==1)
								{
									marked_rows[j]=true;					
								}
							}
						}
					}					
				}		
			}while(marked);
			int min_element=999;
			for(int i=0;i<15;i++)
			{
				for(int j=0;j<15;j++)
				{
					if(marked_rows[i] && !marked_cols[j]){min_element=min(min_element,matrix[i][j].second);}
					matrix[i][j].status=0;
				}
			}
			for(int i=0;i<15;i++)
			{
				for(int j=0;j<15;j++)
				{
					if(marked_rows[i] && !marked_cols[j]){matrix[i][j].second-=min_element;}
					else if(!marked_rows[i] && marked_cols[j]){matrix[i][j].second+=min_element;}
				}
			}				
		}
	}
	cout<<result;
	getchar();
	return 0;
}
