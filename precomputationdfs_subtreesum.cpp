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
const int N=1e5+10;
vt <int> g[N];
int subtree_sum[N];//For sum of subtree
int even_count[N];//number of even numbers of each node
void dfs(int vertex,int parent=0){
    //Take action on vertex before entering the node
    if(vertex%2==0) even_count[vertex]++;
    subtree_sum[vertex]+=vertex;//Change vertex to value of the given node by val[vertex]
    for(int child:g[vertex]){
        //Take action on child before entering the node
      if(child==parent) continue;
        dfs(child,vertex);
        //Take action on child after entering the node
        subtree_sum[vertex]+=subtree_sum[child];
        even_count[vertex]+=even_count[child];
    }
    //Take action on vertex before exiting the vertex
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("ip.txt","r",stdin);
    freopen("op.txt","w",stdout);
    #endif
    FastIO;
    int i,n,x,y;
    cin>>n;
    for(i=0;i<n-1;i++){
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1); //Because 1 is starting node (change according to question)
    for(i=1;i<=n;i++){
        cout<<"NODE "<<i<<"\n";
        cout<<subtree_sum[i]<<" "<<even_count[i]<<"\n";
    }
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
