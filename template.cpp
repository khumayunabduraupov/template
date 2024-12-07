/*
    بسم الله الرحمن الرحيم
    
    Author: _moon_lover_
*/

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define len(a) (int)(a.size())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define seea(a, n) for(int i = 0; i < n; ++ i){cin>>a[i];}
#define ff first
#define ss second
#define ll long long

int32_t month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
template<typename T> using matrix = vector<vector<T>>;
template<class T> using vi = vector<T>;
typedef tree<int,null_type, less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set; 


#ifdef run
#include "debug.h"
#else
#define print(x...)
#endif

const ll mod = 1000000007ll;
const ll inf = LLONG_MAX;
const int _inf = INT_MAX;
const double pi = acos(-1);

namespace io{
    template<typename T, typename S>
    ostream& operator << (ostream& out, const pair<T, S> &p){return out << p.ff << ' ' << p.ss;}
    template<typename T, typename S>
    ostream& operator << (ostream& out, const map<T,S> &a){for(auto i : a) out << i << '\n'; return out;}
    template<typename T, typename S>
    ostream& operator << (ostream& out, const unordered_map<T, S> &a){for(auto i : a) out << i << '\n'; return out;}
    template<typename T>
    ostream& operator << (ostream& out, vector<T> &a){
        bool sp = 0;
        for(T i : a){
            if(sp) out << ' ';
            sp = 1;
            out << i;
        }
        return out;
    }
    template<typename T>
    ostream& operator << (ostream& out, const deque<T> &a){
        bool sp = 0;
        for(T i : a){
            if(sp) out << ' ';
            sp = 1;
            out << i;
        }
        return out;
    }
    template<typename T>
    ostream& operator << (ostream& out, const multiset<T> &a){
        bool sp = 0;
        for(T i : a){
            if(sp) out << ' ';
            sp = 1;
            out << i;
        }
        return out;
    }
    template<typename T>
    ostream& operator << (ostream& out, const set<T> &a){
        bool sp = 0;
        for(T i : a){
            if(sp) out << ' ';
            sp = 1;
            out << i;
        }
        return out;}
    ostream& operator << (ostream& os, __int128 a){
        string s = "";
        while(a) s += (a % 10) + 48, a /= 10;
        os << s;
        return os;
    }
    void pr(){}
    template<typename main, typename... sec> void pr(main m, sec... oth){
        cout << m;
        pr(oth...);
    }
    // Max && Min functions
    template<typename T> inline void maxs(T&a, T b){a=max(a,b);}

    template<typename T> inline void mins(T&a, T b){a=min(a,b);}

    // Input

    template<typename T, typename S>istream& operator >> (istream& in, pair<T, S> &p){return in >> p.ff >> p.ss;}
    template<typename T>
    istream& operator >> (istream& in, vector<T> &a){for(T&i:a)in>>i;return in;}
    template<class T> istream& operator >> (istream& in, deque<T> &a){for(T&i:a)in>>i;return in;}
};
namespace math{
    ll C(ll n, ll k){
        if(n < k) return 0;
        ll res = 1;
        for(int i = 0; i < k; ++ i) res = res * (n - i) / (i + 1);
        return res;
    }
    vector<bool> sieve(1e6 + 1, 1);
    ll factorial(ll n){
        ll res = 1;
        for(int i = 2; i <= n; ++ i) res *= i;
        return res;
    }
    ll binpow(ll n, ll k, ll md = 1e9 + 7){
        ll res = 1;
        while(k) {
            if(k & 1) res = (res * n) % md;
            n = (n * n) % md;
            k >>= 1;
        }
        return res;
    }
    ll gcd(ll a, ll b){
        return b ? gcd(b, a % b) : a;
    }
    ll lcm(ll a, ll b){
        return a * b / gcd(a, b);
    }
    ll phi(ll n) {
        ll res = n;
        for(ll i = 2; i * i <= n; ++ i) {
            if(n % i == 0) {
                res -= res / i;
                while(n % i == 0) n /= i;
            }
        }
        if(n > 1) res -= res / n;
        return res;
    }
    void generate(){
        sieve[0] = sieve[1] = false;
        for(int i = 2; i <= 1e6; ++ i) {
            if(sieve[i] == false) continue;
            for(int j = i + i; j <= 1e6; j += i) sieve[j] = false;
        }
    }
};

using namespace math;
using namespace io;

#define crer(x...) {io::pr(x);return;}

#define test_case
void solution();
main(){    //generate();
    #ifdef run
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("output.txt", "w", stderr);
    #else
        cin.tie(nullptr) -> sync_with_stdio(0);
    #endif
        int t = 1;
    #ifdef test_case
        cin >> t;
    #endif
        for(int test = 1; test <= t; ++ test){
            print(test);
            solution();
            cout << '\n';
        }
        return EXIT_SUCCESS;
}

#define int int64_t

void solution() {
    
}
