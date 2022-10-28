#include <bits/stdc++.h>
using namespace std;
// using namespace std::chrono;
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
#define ld long double
#define vt vector
#define pb push_back
#define all(c) c.begin(),c.end()
#define each(x,a) for(auto x:a)
#define sz(x) (int)(x).size()
const ll N=1e5+10;
const ll M=1e9+7;
ll parent[N];
ll size[N];
void make(ll v){
    parent[v]=v;
    size[v]=1;
}
ll find(ll v){
    if(v==parent[v]) return v;
    //finds v node traversing up the tree and also path compression is applied
    return parent[v]=find(parent[v]);
}
void Union(ll a,ll b){
    a=find(a);
    b=find(b);
    if(a!=b){
        //swap so that always smaller tree is added to bigger tree for time complexity optimization
        if(size[a]<size[b]){
            swap(a,b);
        }
        parent[b]=a;
        size[a]+=size[b];
    }
}
void solve(){
    ll n,m,i;//n-->nodes,m-->edges
    cin>>n>>m;
    //see image for tree
    vt<pair<ll,pair<ll,ll>>> edges;//(weight,node1,node2)
    for(i=0;i<m;i++){
        ll u,v,wt;
        cin>>u>>v>>wt;
        edges.pb({wt,{u,v}});
    }
    for(i=1;i<=n;i++){
        make(i);
    }
    sort(all(edges));
    ll total_cost=0;
    each(edge,edges){
        ll wt=edge.first;
        ll u=edge.second.first;
        ll v=edge.second.second;
        if(find(u)==find(v)) continue;//loops are to be removed
        Union(u,v);
        total_cost+=wt;
    }
    cout<<total_cost;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("ip.txt","r",stdin);
    freopen("op.txt","w",stdout);
    #endif
    FastIO;
    ll t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
/* INPUT
6 9
5 4 9
1 4 1
5 1 4
4 3 5
4 2 3
1 2 2
3 2 3
3 6 8
2 6 7
*/