#include <bits/stdc++.h>
using namespace std;
// using namespace std::chrono;
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define ull unsigned long long
#define ld long double
#define vt vector
#define pb push_back
#define pob pop_back
#define all(c) c.begin(),c.end()
#define each(x,a) for(auto x:a)
#define sz(x) (ll)(x).size()
ll mod=1000000007;
ll bit_arr[32];
vt<vt<ll>> all_subsets;
void generate(vt<ll> &subset,ll index,vt<ll> &nums){
  if(index==sz(nums)){
    all_subsets.pb(subset);
    return;
  }
  generate(subset,index+1,nums);
  subset.pb(nums[index]);
  generate(subset,index+1,nums);
  subset.pob();
}
void solve(){
     ll n,i,x;
     cin>>n;
     vt<ll> empty;
     vt<ll> nums;
     for(i=0;i<n;i++){
       cin>>x;
       nums.pb(x);
     }
     generate(empty,0,nums);
     cout<<"The first subset is empty and hence not visible\n";
     cout<<"The subsets generated are:";
     each(x,all_subsets){
       each(element,x){
         cout<<element<<" ";
       }
       cout<<"\n";
     }
}
int main(){
    // auto start = high_resolution_clock::now();
    // #ifdef ONLINE_JUDGE
    // freopen("ip.txt","r",stdin);
    // freopen("op.txt","w",stdout);
    // #endif
    FastIO;
    ll t=1;
    // ll i=1;
    // cin>>t;
    while(t--){
    // cout<<"Case #"<<i<<": ";
    solve();
    // cout<<"\n";
    // i++;
    }
    //  auto stop = high_resolution_clock::now();
    //   auto duration = duration_cast<microseconds>(stop - start);cout << "Time taken by function: "
    //      << duration.count() << " microseconds" << endl;
    return 0;
}
