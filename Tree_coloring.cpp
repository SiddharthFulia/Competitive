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
ll mod1=1000000007;
ll bit_arr[32];
const ll N = 1e5;
vector<ll> tree[N];
ll don[N], parent_of_node[N],
  child_of_node[N], flag = -1;

void dfs(ll current, ll parent){
  parent_of_node[current] = parent;
  for (ll& child : tree[current]) {

    if (child == parent)
      return;
    dfs(child, current);
  }

  if (don[current] == 1 && current != 1) {

    child_of_node[current] = 0;
    return;
  }

  ll total_child = 0;
  for (auto& child : tree[current]) {
    if (child == parent)
      return;
    else
      ++total_child;
  }
  child_of_node[current] = total_child;
  return;
}
ll find_nPr(ll n, ll R){
  if (R > n) {
    flag = 0;
    return 0;
  }
  ll total = 1;
  for (ll i = n - R + 1; i <= n; ++i) {
    total = total * i;
  }
  return total;
}
ll NoOfWays(ll Nodes, ll colors){
  dfs(1, -1);
  ll ways = 0;
  for (ll i = 1; i <= Nodes; ++i) {
    if (i == 1) {
      ways = ways + colors *
        find_nPr(colors - 1, child_of_node[1]);
    }
    else {
      if (don[i] == 1) {
        continue;
      }
      else {
        ways = ways *
        find_nPr(colors - 2, child_of_node[i]);
      }
    }
  }
  return ways;
}
void Tree(ll n){
    while(n>0){
        ll i,j;
        cin>>i>>j;
        tree[i].push_back(j);
        tree[j].push_back(i);
        don[i]++,don[j]++;
        n--;
    }
}
void solve(){
  ll n,c;
  cin>>n>>c;
  Tree(n-1);
  ll Count = NoOfWays(n, c);
  cout << Count << "\n";
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
    //      << duration.count() << " microseconds" << "\n";
    return 0;
}

