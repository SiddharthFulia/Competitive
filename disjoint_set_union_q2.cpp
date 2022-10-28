//https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-campers/
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
multiset<ll> sizes;
void make(ll v){
    parent[v]=v;
    size[v]=1;
    sizes.insert(1);//set size of each node to 1
}
ll find(ll v){
    if(v==parent[v]) return v;
    //finds v node traversing up the tree and also path compression is applied
    return parent[v]=find(parent[v]);
}
void merge(ll a,ll b){
    //dont write size.erase(size[a]) as it will erase all occurences of size[a] whereas here we nees to erase one by one in case of repetition
    sizes.erase(sizes.find(size[a]));
    sizes.erase(sizes.find(size[b]));
    sizes.insert(size[a]+size[b]);
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
        merge(a,b);
        size[a]+=size[b];
    }
}
void solve(){
    ll n,q,i;
    cin>>n>>q;
    for(i=1;i<=n;i++){
        make(i);
    }
    //k is number of queries for union of 2 nodes
    while(q--){
        ll u,v;
        cin>>u>>v;
        Union(u,v);
        if(sz(sizes)==1){
        cout<<0;
        }
        else{
            ll min1=*(sizes.begin());//point at the beggining iterator
            ll max1=*(--sizes.end());//point at the end iterator-1
            cout<<max1-min1;
        }
        cout<<"\n";
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
*/
