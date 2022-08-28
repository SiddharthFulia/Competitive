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
#define sz(x) (ll)(x).size()
const ll N=1e5+10;
vt <ll> g[N];
ll depth[N];
void dfs(ll vertex,ll parent=0){
    //Take action on vertex before entering the node
    for(ll child:g[vertex]){
        //Take action on child before entering the node
      if(child==parent) continue;
      depth[child]=depth[vertex]+1;
        dfs(child,vertex);
        //Take action on child after entering the node
    }
    //Take action on vertex before exiting the vertex
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("ip.txt","r",stdin);
    freopen("op.txt","w",stdout);
    #endif
    FastIO;
    ll i,n,x,y;
    cin>>n;
    for(i=0;i<n-1;i++){
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1); //Because 1 is starting node (change according to question)
    ll max_depth=-1;
    ll max_depth_node;
    //finding the node with max depth
    for(i=1;i<=n;i++){
        if(max_depth<depth[i]){
            max_depth=depth[i];
            max_depth_node=i;
        }
    }
    //resetting the depth array to 0
    for(i=1;i<=n;i++){
       depth[i]=0;
    }
    dfs(max_depth_node);
    max_depth=-1;
    //finding the diameter of tree by finding the dfs(max_depth_node) this makes the time complexity from O(N^2) to O(N) as in O(N^2) approach we have to find dfs in for loop
    for(i=1;i<=n;i++){
        if(max_depth<depth[i]){
            max_depth=depth[i];
            max_depth_node=i;
        }
    }
    cout<<max_depth;
    return 0;
}
/* INPUT
13
1 3
1 2
1 13
2 5
3 4
5 6
5 7
5 8
8 12
4 9 
4 10
10 11
*/
