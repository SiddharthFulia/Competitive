//https://www.codechef.com/problems/PWMUL
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }


template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

int highest_bit(uint64_t x) {
    return x == 0 ? -1 : 63 - __builtin_clzll(x);
}

// Prime factorizes n in worst case O(sqrt n).
vector<pair<int64_t, int>> prime_factorize(int64_t n) {
    assert(n >= 1);
    vector<pair<int64_t, int>> result;

    auto extract = [&](int64_t p) {
        if (n % p == 0) {
            result.emplace_back(p, 0);

            do {
                n /= p;
                result.back().second++;
            } while (n % p == 0);
        }
    };

    for (int64_t p = 2; p * p <= n; p += p % 2 + 1)
        extract(p);

    if (n > 1)
        result.emplace_back(n, 1);

    return result;
}

vector<int64_t> generate_factors(const vector<pair<int64_t, int>> &prime_factors, bool sorted = false) {
    // See http://oeis.org/A066150 and http://oeis.org/A036451 for upper bounds on number of factors.
    static vector<int64_t> buffer;
    int product = 1;

    for (auto &pf : prime_factors)
        product *= pf.second + 1;

    vector<int64_t> factors = {1};
    factors.reserve(product);

    if (sorted)
        buffer.resize(product);

    for (auto &pf : prime_factors) {
        int64_t p = pf.first;
        int exponent = pf.second;
        int before_size = int(factors.size());

        for (int i = 0; i < exponent * before_size; i++)
            factors.push_back(factors[factors.size() - before_size] * p);

        if (sorted && factors[before_size - 1] > p)
            for (int section = before_size; section < int(factors.size()); section *= 2)
                for (int i = 0; i + section < int(factors.size()); i += 2 * section) {
                    int length = min(2 * section, int(factors.size()) - i);
                    merge(factors.begin() + i, factors.begin() + i + section,
                          factors.begin() + i + section, factors.begin() + i + length,
                          buffer.begin());
                    copy(buffer.begin(), buffer.begin() + length, factors.begin() + i);
                }
    }

    assert(int(factors.size()) == product);
    return factors;
}

uint64_t mod_mul64(uint64_t a, uint64_t b, uint64_t mod) {
    assert(a < mod && b < mod);

    if (mod <= 1LLU << 32)
        return a * b % mod;

    uint64_t q = uint64_t((long double) a * b / mod);
    uint64_t result = a * b - q * mod;

    if (result > 1LLU << 63)
        result += mod;
    else if (result >= mod)
        result -= mod;

    return result;
}

uint64_t mod_pow64(uint64_t a, uint64_t p, uint64_t mod) {
    uint64_t result = 1;

    while (p > 0) {
        if (p & 1)
            result = mod_mul64(result, a, mod);

        p >>= 1;

        if (p > 0)
            a = mod_mul64(a, a, mod);
    }

    return result;
}

uint64_t inv_mod64(uint64_t a, uint64_t m) {
    // https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm#Example
    // https://www.di-mgt.com.au/euclidean.html#code-modinv
    uint64_t g = m, r = a, x = 0, y = 1;
    int sign = -1;

    while (r != 0) {
        uint64_t q = g / r;
        g %= r; swap(g, r);
        x += q * y; swap(x, y);
        sign = -sign;
    }

    assert(g == 1);
    assert(y == m);
    return sign > 0 ? x : m - x;
}


int main() {
    int64_t P, A, B;
    cin >> P >> A >> B;
    vector<pair<int64_t, int>> p1_prime_factors = prime_factorize(P - 1);
    vector<int64_t> p1_factors = generate_factors(p1_prime_factors, true);
    int64_t K = -1;

    for (int64_t f : p1_factors)
        if (mod_pow64(A, f, P) == 1) {
            K = f;
            break;
        }

    if (K < 7 * P / K * (highest_bit(K) + 1)) {
        int64_t current = B, minimum = P;

        for (int64_t t = 0; t < K; t++) {
            minimum = min(minimum, current);
            current = mod_mul64(current, A, P);
        }

        cout << minimum << '\n';
        assert(current == B);
    } else {
        int64_t B_inv = inv_mod64(B, P), current = 0;

        for (int64_t x = 1; x < P; x++) {
            current = (current + B_inv) % P;

            if (mod_pow64(current, K, P) == 1) {
                cout << x << '\n';
                break;
            }
        }
    }
}
