//https://codeforces.com/contest/1245/problem/D
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
    ll n,i,j;
    cin>>n;
    for(i=1;i<=n;i++){
        make(i);
    }
    vt<pair<ll,ll>> cities(n+1);
    for(i=1;i<=n;i++){
        cin>>cities[i].first>>cities[i].second;
    }
    vt<ll> c(n+1),k(n+1);//c-->generator cost,k-->wire cost
    for(i=1;i<=n;i++){
        cin>>c[i];
    }
    for(i=1;i<=n;i++){
        cin>>k[i];
    }
    vt<pair<ll,pair<ll,ll>>> edges;
    for(i=1;i<=n;i++){
        edges.pb({c[i],{0,i}});//connecting all nodes with 0 node
    }
    //connect all edges to each other
    for(i=1;i<=n;i++){
        for(j=i+1;j<=n;j++){
            ll dist=abs(cities[i].first-cities[j].first)+abs(cities[i].second-cities[j].second);
            ll cost=(k[i]+k[j])*dist;
            edges.pb({cost,{i,j}});
        }
    }
    sort(all(edges));
    //Kruskal
    ll total_cost=0;
    vt<ll> power_stations;
    vt<pair<ll,ll>> connections;
    each(edge,edges){
        ll wt=edge.first;
        ll u=edge.second.first;
        ll v=edge.second.second;
        if(find(u)==find(v)) continue;//loops are to be removed
        Union(u,v);
        if(u==0||v==0){
            power_stations.pb(max(u,v));//powerstation will be in the non-zero node
        }
        else{
            connections.pb({u,v});//if powerstation is not present then it would be a connection
        }
        total_cost+=wt;
    }
    cout<<total_cost<<"\n";
    cout<<sz(power_stations)<<"\n";
    each(station,power_stations){
        cout<<station<<" ";
    }
    cout<<"\n";
    cout<<sz(connections)<<"\n";
    each(connection,connections){
        cout<<connection.first<<" "<<connection.second<<"\n";
    }
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
3
2 3
1 1
3 2
3 2 3
3 2 3
*/