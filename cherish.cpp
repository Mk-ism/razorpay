#include<bits/stdc++.h>
using namespace std;
struct edges
{
    long long int src;
    long long int dest;
    long long int w;
};
struct sub
{
    long long int parent;
    long long int rank;
};
bool comp(edges e1,edges e2)
{
    return e1.w<e2.w;
}
long long int find(vector<sub> &subset,long long int i)
{
    if(subset[i].parent!=i)
    {
        subset[i].parent=find(subset,subset[i].parent);
    }
    return subset[i].parent;
}
void Union(vector<sub> &subset,long long int x,long long int y)
{
    long long int xr=find(subset,x);
    long long int yr=find(subset,y);
    if(subset[xr].rank<subset[yr].rank)
    {
        subset[xr].parent=yr;
    }
    else if(subset[xr].rank>subset[yr].rank)
    {
        subset[yr].parent=xr;
    }
    else
    {
        subset[yr].parent=xr;
        subset[xr].rank+=1;
    }
}
long long int mst(vector<edges> &v,long long int n,long long int m)
{
    sort(v.begin(),v.end(),comp);
    vector<sub> subset(n+1);
    long long int e=0,i=0,ans=0;
    for(long long int j=1;j<=n;j++)
    {
        subset[j].parent=j;
        subset[j].rank=0;
    }
    while(e<n-1 && i<v.size())
    {
        edges next=v[i];
        i++;
        long long int x=find(subset,next.src);
        long long int y=find(subset,next.dest);
        if(x!=y)
        {
            ans+=next.w;
            e++;
            Union(subset,x,y);
        }
    }
    return ans;
}
int main()
{
    long long int t;
    cin>>t;
    long long int z=1;
    while(t--)
    {
    	long long int m,n;
        cin>>n>>m;
        vector<edges> v;
        set<pair<long long int,long long int> > s;
        for(long long int i=0;i<m;i++)
        {
            long long int x,y;
            cin>>x>>y;
            edges e;
            e.src=x;
            e.dest=y;
            e.w=1;
            v.push_back(e);
            s.insert(make_pair(x,y));
        }
        for(long long int i=1;i<=n;i++)
        {
            for(long long int j=i+1;j<=n;j++)
            {
                if(s.find(make_pair(i,j))==s.end())
                {
                    edges e;
                    e.src=i;
                    e.dest=j;
                    e.w=2;
                    v.push_back(e);
                    s.insert(make_pair(i,j));
                }
            }
        }
        cout<<"Case #"<<z<<": "<<mst(v,n,m);
        cout<<'\n';
        z++;
    }
}
