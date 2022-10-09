#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    long long int t;
    cin>>t;
    for(long long int z=1;z<=t;z++)
    {
        long long int ans=0;
        long long int l,r;
        cin>>l>>r;
        for(long long int i=l;i<=r;i++)
        {
            long long int al=0,bob=0;
            for(long long int j=1;j<=i;j++)
            {
                if(i%j==0)
                {
                    if(j%2==0)
                    {
                        bob++;
                    }
                    else
                    {
                        al++;
                    }
                }
            }
            if(abs(al-bob)<=2)
            {
                ans++;
            }
        }
        cout<<"Case #"<<z<<": "<<ans<<'\n';
    }
}
