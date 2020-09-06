#include <bits/stdc++.h>
using namespace std;
class Sort{
	private:
		vector<pair<long int,long int> > radicals;
	public:
		~Sort();
		Sort();
		void mergesort();
		void merge(long int l,long int m,long int r);
};
Sort::~Sort()
{
	cout<<radicals[9999].first;
	getchar();
}
Sort::Sort()
{
	for(long int i=1;i<=100000;radicals.push_back(make_pair(i,1)),i++){}
	for(long int i=2;i<=100000;i++)
	{
		if(radicals[i-1].second==1)
		{
			for(long int j=i;j<=100000;radicals[j-1].second*=i,j+=i){}
		}
	}
	mergesort();
}
void Sort::mergesort()
{
	vector<long int> v;
	v.push_back(100000);
	int i=0;
	long int l=0,m,r;
	while(v[i]>1)
	{
		long int div=v[i]/2;
		v.push_back(div);
		v.push_back(v[i]-div);
		i++;
	}
	for(int j=v.size()-1;j>=0;j--)
	{
		if(v[j]!=1)
		{
			if(v[j]%2!=0){m=l+((v[j]+1)/2);}
			else{m=l+(v[j]/2);}
			r=l+v[j]-1;
			merge(l,m,r);
		}
		if(l+v[j]>99999){l=0;}
		else{l+=v[j];}
	}
}
void Sort::merge(long int l,long int m,long int r)
{
	long int i=0,j=0,k=l,a=m-l,b=r-m+1;
	vector<pair<long int,long int> > left,right;
	while(i<a || j<b)
	{
		if(i<a)
		{
			left.push_back(radicals[l+i]);
			i++;
		}
		if(j<b)
		{
			right.push_back(radicals[m+j]);
			j++;
		}
	}
	i=0,j=0;
	while(i<a || j<b)
	{
		if(i<a && j<b)
		{
			if((left[i].second<right[j].second) || (left[i].second==right[j].second && left[i].first<right[j].first))
			{
				radicals[k]=left[i];
				i++;
			}
			else
			{
				radicals[k]=right[j];
				j++;
			}
		}
		else if(i<a)
		{
			radicals[k]=left[i];
			i++;
		}
		else
		{
			radicals[k]=right[j];
			j++;
		}
		k++;
	}
}
int main()
{
	Sort s;
	return 0;
}
