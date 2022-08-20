#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define rep(i,x,y) for(int i=x; i<y; i++)
#define pii pair<int,int>
#define vii vector<pair<int,int>>
#define vi vector<int>
#define setbits(x) __builtin_popcountll(x)
#define prevzeros(x) __builtin_clzll(x)                 //do 64 minus-x
#define afterzeros(x) __builtin_ctzll(x)
#define mp make_pair
const int mod = 1e9 + 7;
const int mod1 = 998244353;
typedef long double ld;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// ////using namespace std;
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
int inv(int i)
{
    if (i == 1) return 1;
    return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;
}
//-----------------------------------------------------//
int power(int a, int b, int p)
{
    if (a == 0)
        return 0;
    int res = 1;
    a %= p;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % p;
        b >>= 1;
        a = (a * a) % p;
    }
    return res;
}
//-----------------------------------------------------//
int fact(int n, int m)
{

    int p = 1;
    if (n == 0)
        return 1;
    else
    {
        for (int i = 1; i <= n; i++)
        {
            p *= i;
            p = p % m;
        }
        return p;
    }
}
//-----------------------------------------------------//

// int ncr(int n, int r)
// {
//     int ans = 1;
//     rep(i, n - r + 1, n + 1)
//     {
//         ans *= i;
//     }
//     rep(i, 1, r + 1)
//     {
//         ans /= i;
//     }
//     return ans;
// }
//-----------------------------------------------------//

// int findXOR(int n)
// {
//     int mod = n % 4;

//     if (mod == 0)
//         return n;

//     else if (mod == 1)
//         return 1;

//     else if (mod == 2)
//         return n + 1;

//     else if (mod == 3)
//         return 0;
//     return 0;
// }
// int findXOR(int l, int r)
// {
//     return (findXOR(l - 1) ^ findXOR(r));
// }
//-----------------------------------------------------//

int powe(int a, int b)
{
    if (a == 0)
        return 0;
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) ;
        b >>= 1;
        a *= a ;
    }
    return res;
}
//-----------------------------------------------------//

// const int N = 200001;
// int f[N];
// int invf[N];
// int ncr(int n, int r)
// {
//     if (n < 0 || r < 0 || n < r)
//         return 0;
//     int ans = f[n];
//     ans = (ans * invf[n - r]) % mod;
//     ans = (ans * invf[r]) % mod;
//     return ans;
// }


// f[0] = 1;
// for (int i = 1; i <= N; i++)
//     f[i] = (f[i - 1] * i) % mod;
// for (int i = 0; i <= N; i++)
//     invf[i] = inv(f[i]);


//-----------------------------------------------------//
int inverse(int a, int p)
{
    return power(a, p - 2, p);
}
int nCrmod(int n, int r)
{
    if (n < 0 || r < 0 || r > n)
        return 0;
    if (r == 0)return 1;
    return (((n * nCrmod(n - 1, r - 1)) % mod) * inv(r)) % mod;
}
///////////
// int spf[10000007];
// void spfcalc()
// {
//     for (int i = 0; i <= 1e7; i++) {
//         spf[i] = i;
//     }
//     for (int i = 2; i * i <= 1e7; i++) {
//         if (spf[i] == i) {
//             for (int j = i * i; j <= 1e7; j += i) {
//                 if (spf[j] == j) {
//                     spf[j] = i;
//                 }
//             }
//         }
//     }
// }
// vi primes;
// void primefind()
// {
//     int N = 10001;
//     bool isprime[N];

//     rep(i, 0, N)
//     {
//         isprime[i] = true;
//     }
//     isprime[0] = false;
//     isprime[1] = false;
//     for (int i = 2; i * i <= N; i++)
//     {
//         if (isprime[i])
//         {
//             for (int j = i * i; j <= N; j += i)
//             {
//                 isprime[j] = false;
//             }
//         }
//     }
//     for (int i = 2; i < N; i++)
//     {
//         if (isprime[i])primes.pb(i);
//     }
// }

vector<vi>tree;
vector<int>calc;
vector<int>par;
vi a;

void func(int i)
{
    //cout << i << " ";
    for (auto x : tree[i])
    {
        if (par[x] == 0)
        {
            par[x] = i + 1;
            func(x);
        }
    }
}



int func1(int i)
{
    int curr = 0;
    for (auto x : tree[i])
    {
        if (par[i] - 1 == x)continue;
        curr += func1(x);
        // if (a[x] == 0)curr++;
        // else curr--;
    }
    if (a[i] == 0)curr++;
    else curr--;
    calc[i] = curr;
    return curr;
}


multiset<pii>ml;


void erasing(int i)
{
    for (auto x : tree[i])
    {
        if (par[i] - 1 != x)
        {
            ml.erase({calc[x], x + 1});
            erasing(x);
        }
    }
}


int32_t main()
{

#ifndef ONLINE_JUDGE
    freopen("debug.txt", "w" , stderr);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--)
    {
        tree.clear();
        calc.clear();
        par.clear();
        a.clear();
        int n;
        cin >> n;
        a.resize(n);
        rep(i, 0, n)cin >> a[i];
        tree.resize(n);
        par.resize(n);
        calc.resize(n);
        rep(i, 0, n - 1)
        {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            tree[u].pb(v);
            tree[v].pb(u);
        }
        int zeros = 0;
        rep(i, 0, n)if (a[i] == 0)zeros++;

        int diff = zeros - (n - zeros);
        //cout << diff;
        diff /= 2;
        if (diff == 0)
        {
            cout << 0 << '\n';
            continue;
        }
        par[0] = -1;

        func(0);//par calc right with 1 indexing
        func1(0);//extra 0 calc right;




        // for (int i = 0; i < n; i++)
        // {
        //     cout << calc[i] << " ";
        // }

        int poss = 0;
        for (int i = 0; i < n; i++)
        {
            if (calc[i] == diff)
            {
                poss = 1;
                cout << 1 << '\n';
                cout << i + 1 << '\n';
                break;
            }
        }
        if (poss)continue;
        for (int i = 0; i < n; i++)
        {
            int curr = i + 1;
            ml.clear();
            for (int j = 0; j < n; j++)
            {
                ml.insert({calc[j], j + 1});
            }
            int xx = i;
            //ml.erase({calc[i], i + 1});
            while (par[xx] != -1)
            {
                ml.erase({calc[xx], xx + 1});
                xx = par[xx] - 1;
            }
            if(ml.find({calc[0],1})!=ml.end())ml.erase({calc[0],1});


            erasing(i);
            if (ml.size() == 0)continue;

            // for (auto x : ml)
            // {
            //     //cout << x.ff << " ";
            // }
            // cout << '\n';




            int done = 0;
            for (auto x : ml)
            {
                if (x.ff == diff - calc[i])
                {
                    cout << 2 << '\n';
                    cout << i + 1 << " " << x.ss << " " << '\n';
                    done = 1;
                    break;
                }
            }
            if (done)break;



        }
    }
    return 0;
}