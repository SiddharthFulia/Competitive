#include <bits/stdc++.h>
using namespace std;
// using namespace std::chrono;
// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
//if RE then remove above 3 lines
#define FastIO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long 
#define ull unsigned long long 
#define ld long double
#define vt vector
#define ml multiset
#define pb push_back
#define mp make_pair
#define pob pop_back
#define all(c) c.begin(),c.end()
#define each(x,a) for(auto x:a)
#define sz(x) (ll)(x).size()
// const ll N=(ll)(2e7)+10;
// const ll N1=INT_MAX;
// const ll M=(ll)(1e9)+7;
// const ll M=998244353;
// ll bit_arr[32];

// bool vector_second_sort(const pair<ll,ll> &a,const pair<ll,ll> &b){
//     return (a.second<b.second);
// }

// vt<ll> to_binary(vt<ll> v,ll x){
//    while(x){
//       v.pb(x%2);
//       x/=2;
//    }
//    return v;
//    //Not reversed
// }

// ll to_decimal(vt<ll>v){
//    ll x=0,i;
//    for(i=0;i<sz(v);i++){
//       if(v[i]==1){
//          x+=pow(2,i);
//       }
//    }
//    return x;
//    //Ascending order vector
// }

// ll euler_totient_function(ll z){
//    ll i=2;
//    set <ll> s;
//    ll y=z;
//    while(y!=1){
//       if(y%i==0){
//          y/=i;
//          s.insert(i);
//          i=2;
//       }
//       else{
//       i++;
//       }
//    }
//    each(x,s){
//       z=z*(x-1)/x;
//    }
//    return z;
// }

// ll take_mod(ll a,ll b=1){
//     return ((a%M)*(b%M))%M;
// }

// ll binary_multiplication(ll a,ll b){
//     ll ans=0;
//     while(b>0){
//         if(b&1){
//             ans=(ans+a)%M;
//         }
//         a=(a+a)%M;
//         b>>=1;
//     }
//     return ans;
// }

// ll binary_exponential_iterative(ll a,ll b){
//    //remove %M if not given in question
//    ll ans=1;
//    while(b){
//       if(b&1){
//          ans*=a;
//          ans%=M;
//       }
//       a=(a*a)%M;
//       b>>=1;//right shift
//    }
//    return ans;
// }

// ll large_exponential_iterative(ll a,ll b,ll m){
//     /*INPUT CODE
//     ll a,b,c;
//     cin>>a>>b>>c;
//     cout<<large_exponential_iterative(a,large_exponential_iterative(b,c,M-1),M);//replace M-1 with ETF(Euler's totient  function) in case M is non-prime
//     */
//     //a^b^c
//     //When b>>10^18 here(b=b^c) to represent in form of a^b
//    ll ans=1;
//    while(b){
//       if(b&1){
//          ans=ans*a%m;
//       }
//       a=a*a%m;
//       b>>=1;//right shift
//    }
//    return ans;
// }

// ll mod_inverse(ll x,ll m=M){
//     return binary_exponential_iterative(x,m-2);
// }

// ll a[N],b[N];
// ll global_array(){
//     ll i=1;
//     a[0]=1,b[0]=1;
//     for(;i<N;i++){
//         a[i]=binary_multiplication(a[i-1],i);
//         b[i]=binary_multiplication(b[i-1],binary_exponential_iterative(i,M-2));
//     }
//     return 0;
// }

// vt<ll> next_greatest_element(vt<ll> v){
//     /*INPUT CODE
//     vt<ll> nge(n);
//     nge=next_greatest_element(a);
//     for(i=0;i<n;i++){
//         cout<<a[i]<<" "<<(nge[i]==-1 ? -1 : a[nge[i]])<<"\n";
//     }
//     */
//    //Here nge stores index values and -1 for elements in stack that are left at the end
//    ll i;
//    ll n=sz(v);
//    vt<ll> nge(n);
//    stack <ll> st;
//    for(i=0;i<n;i++){
//       while(!st.empty()&&v[i]>v[st.top()]){
//       nge[st.top()]=i;
//       st.pop();
//       }
//       st.push(i);
//    }
//    while(!st.empty()){
//       nge[st.top()]=-1;
//       st.pop();
//    }
//    return nge;
// }

// ll sumofdigits(ll x){
//     ll sum=0;
//     while(x){
//         sum+=x%10;
//         x/=10;
//     }
//     return sum;
// }
void solve(){
   ll n,i;
   cin>>n;
}
int main(){
    // auto start = high_resolution_clock::now();
    // cout<<fixed<<setprecision(2);
    #ifndef ONLINE_JUDGE
    freopen("ip.txt","r",stdin);
    freopen("op.txt","w",stdout);
    #endif
    FastIO;
    ll t;
    // ll i=1;
    cin>>t;
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