#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define ff first
#define ss second
#define mp make_pair
#define mod 1000000007

lli arr[100010];
int has[10000];
lli dp[1010][9000];
vector<lli> v;
int maxi=0;
int pr[10000];

void prime (){
    for(int i=2;i<=9000;i++ ){
        if(!pr[i]) 
            for(int j=2;j*i<9000;j++){
                pr[j*i]=1;
            }
      
    }
}
 


lli  solve(int idx,int xr){
    if(idx==maxi && xr==0) return 1;
        else if(idx==maxi) return 0; 
    if(dp[idx][xr]!=-1) return dp[idx][xr];
    else{
        int val=v[idx];
        int count=has[val];
        int ev=count/2;
        int odd=count/2;
        if(count%2==1) odd++;
        ev++;
        int xrr=xr xor val;
        dp[idx][xr]=((1ll*(solve(idx+1,xrr)*odd))%mod+((1ll*(solve(idx+1,xr)*ev))%mod))%mod;
        return dp[idx][xr];
   }
}

int main(){
    prime();
    int t;
    cin>>t;
    while(t--){
        memset(has,0,sizeof has);
        memset(dp,-1,sizeof dp);
        int n;
        cin>>n;
    
        v.clear();
        for(int  i=0;i<n;i++){
            cin>>arr[i];
            if(has[arr[i]]==0) v.push_back(arr[i]);
            has[arr[i]]++;
        }
    
        lli ans=0;
        maxi=v.size();
     
        for(int i=2;i<=8192;i++){
            if(!pr[i]){
         //  cout<<" check for "<<i<<endl;
            ans=(ans+solve(0,i))%mod;
            }   
        }
    cout<<ans<<endl;
    }
}
