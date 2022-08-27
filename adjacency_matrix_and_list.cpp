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
#define each(x,a) for(auto &x:a)
#define sz(x) (ll)(x).size()
ll mod1=1000000007;
ll bit_arr[32];
const ll N=1e3;
vt <pair<ll,ll>> graph2[N];
void solve(){
    //n-->number of nodes m-->number of edges wt-->weight of each edge
     ll n,m,wt,v1,v2,i;
     cin>>n>>m;
     for(i=0;i<m;i++){
        cin>>v1>>v2>>wt;
        //adjacency list
        graph2[v1].pb(make_pair(v2,wt));
        graph2[v2].pb(make_pair(v1,wt));
     }
     each(child,graph2){
        each(child1,child){
            cout<<child1.first<<" "<<child1.second<<"\n";
        }
     }
}
int main(){
    // auto start = high_resolution_clock::now();
    #ifndef ONLINE_JUDGE
    freopen("ip.txt","r",stdin);
    freopen("op.txt","w",stdout);
    #endif
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
