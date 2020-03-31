#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll coinchange(ll arr2[],ll m,ll n)
{
	ll arr[m+1][n+1];
	for(ll i=0;i<m+1;i++)
	{
		arr[i][0]=1;
	}
	for(ll j=0;j<n+1;j++)
	{
		arr[0][j]=0;
	}
	for(ll i=1;i<m+1;i++)
	{
		for(ll j=1;j<n+1;j++)
		{
			if(arr2[i-1]>j)
			{
				arr[i][j]=arr[i-1][j];
			}
			else
			{
				arr[i][j]=(arr[i-1][j]+arr[i][j-arr2[i-1]]);
			}
		}
	}
return arr[m][n];
}
int main()
{
	ll n;
	cin>>n;
	ll m;
	cin>>m;

	ll arr[m];
	for(ll i=0;i<m;i++)
		cin>>arr[i];
	cout<<coinchange(arr,m,n);
}
