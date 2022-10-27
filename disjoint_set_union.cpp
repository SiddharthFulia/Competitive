//https://www.codechef.com/SNCKPB17/problems-old/SNSOCIAL
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
ll make(ll v){
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
        size[a]+=b;
    }
}
void solve(){
    ll n,k,i;
    cin>>n>>k;
    for(i=1;i<=n;i++){
        make(i);
    }
    //k is number of queries for union of 2 nodes
    while(k--){
        ll u,v;
        cin>>u>>v;
        Union(u,v);
    }
    ll connected_count=0;
    //nodes which are same as their parent will tell us the number of total parent trees
    //refer attached image
    for(i=1;i<=n;i++){
        if(parent[i]==i){
            connected_count++;
        }
    }
    cout<<connected_count;
    cout<<"\n";
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("ip.txt","r",stdin);
    freopen("op.txt","w",stdout);
    #endif
    FastIO;
    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
/* INPUT
*/
