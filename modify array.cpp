#include<bits/stdc++.h>
using namespace std;

int main(){
	
	long long int n;
	cin>>n;
	vector<long long int> v(n);
	for(long long int i=0;i<n;i++)
	{
		cin>>v[i];
	}

	priority_queue<int>pq;
	long long int cost1=0,cost2=0;
	pq.push(v[0]);
	for(long long int i=1;i<n;i++)
	{
		if(v[i]<pq.top())
		{
			cost1 += pq.top()-v[i];
			pq.pop();
			pq.push(v[i]);
		}
		pq.push(v[i]);
	}
	//reverse(all(v));
	priority_queue<int,vector<int>,greater<int>>pqq;	
	pqq.push(v[0]);
	for(long long int i=1;i<n;i++)
	{
		pqq.push(v[i]);
		if(v[i]>pqq.top())
		{
			cost2 += v[i]-pqq.top();
			pqq.pop();
			pqq.push(v[i]);
		}
	}
 	cout<<min(cost1,cost2)<<endl;
	return 0;	
}
