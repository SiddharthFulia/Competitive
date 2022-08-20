#include <bits/stdc++.h>
using namespace std;
// using namespace std::chrono;
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
ll wt[105],val[105];
ll dp[105][100005];
ll func(ll ind,ll wt_left){
    if(wt_left==0) return 0;
    if(ind<0) return 0;
    if(dp[ind][wt_left]!=-1) return dp[ind][wt_left];
    //Didnt choose
    ll ans=func(ind-1,wt_left);
    //Choose
    if(wt_left-wt[ind]>=0)
    ans=max(ans,func(ind-1,wt_left-wt[ind])+val[ind]);
    return dp[ind][wt_left]=ans;
}
void solve(){
    memset(dp,-1,sizeof(dp));
     ll n,w,i;
     cin>>n>>w;
     for(i=0;i<n;i++){
         cin>>wt[i]>>val[i];
    }
    cout<<func(n-1,w);
}
int main(){
    // auto start = high_resolution_clock::now();
    // #ifdef ONLINE_JUDGE
    // freopen("ip.txt","r",stdin);
    // freopen("op.txt","w",stdout);
    // #endif
    FastIO;
    int t;
    cin>>t;
    while(t--){
    solve();
    }
    //  auto stop = high_resolution_clock::now();
    //   auto duration = duration_cast<microseconds>(stop - start);cout << "Time taken by function: "
    //      << duration.count() << " microseconds" << endl;
    return 0;
}