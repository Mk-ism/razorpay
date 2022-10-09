#include<bits/stdc++.h>
using namespace std;
int main()
{
	struct marks
	{
		string s;
		int m;
	};
	int t;
	cin>>t;
	marks a[t];
	for (int i=0;i<t;i++)
	{
		cin>>a[i].s>>a[i].m;
	}
	for (int i=0;i<t-2;i++)
	{
		for (int j=i;j<t-1;j++)
		{
			if(a[j].s>a[j+1].s)
			{
				marks r;
				r=a[j];
				a[j]=a[j+1];
				a[j+1]=r;
			}
		}
	}
	for (int i=0;i<t-2;i++)
	{
		for (int j=i;j<t-1;j++)
		{
			if(a[j].m<a[j+1].m)
			{
				marks r;
				r=a[j];
				a[j]=a[j+1];
				a[j+1]=r;
			}
		}
	}
	for (int i=0;i<t;i++)
	{
		cout<<a[i].s<<" "<<a[i].m<<"\n";
	}
}
