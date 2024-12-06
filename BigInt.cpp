#include<bits/stdc++.h>
 
using namespace std;
#define ff first
#define ss second
#define rall(vec) vec.rbegin(), vec.rend()
#define ll long long
#define eb emplace_back
#define ins insert
#define cia(a, n) for(int i = 0; i < n; ++i){cin >> a[i];}
#define all(vec) vec.begin(), vec.end()
#define gcd(a,b) __gcd(a,b)
#define dq deque<auto>
#define len(a) a.size()
#define lcm(a,b) 1ll * a * b / gcd(a,b)
#define mod 1000000007ll
#define vi vector<int>
#define vll vector<ll>
#define lw(a, l) lower_bound(a.begin(), a.end(), l)
#define up(a, r) upper_bound(a.begin(), a.end(), r)
#define str(a) to_string(a)
int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
istream& operator >> (istream& cin, vector<auto>&a);
istream& operator >> (istream& cin, vector<vector<auto>>&a);
ostream& operator << (ostream& cout, vector<auto>a);
ostream& operator << (ostream& cout, vector<vector<auto>>a);
struct BigInt{
    deque<int> d;
    int sign;
    BigInt operator -(){
        BigInt res = *this;
        res.sign *= -1;
        return res;
    }
    int& operator [](int i){return d[i];}
    size_t size(){return len(d);}
    string sr(){
        string res;
        for(int i = len(d) - 1; i > -1; -- i) res += d[i] + 48;
        return res;
    }
    void clz(){
        while(!d.empty() && d.back() == 0) d.pop_back();
        if(d.empty()){
            sign = 0;
        }
    }
    BigInt(){sign = 0;};
    BigInt(ll n){
        *this = BigInt(to_string(n));
    }
    BigInt(string s){
        if(s[0] == '-'){
            *this = BigInt(s.substr(1));
            sign *= -1;
        }
        else if(s[0] == '+'){
            *this = BigInt(s.substr(1));
        }else{
            sign = 1;
            for(int i = len(s) - 1; i >= 0; -- i) d.eb(s[i] - 48);
            clz();
        }
    }
    auto begin(){return  d.begin();}
    auto end(){return d.end();}
};
 
istream& operator >> (istream& cin, BigInt &a){
    string s;cin >> s;
    a = BigInt(s);
    return cin;
}
ostream& operator << (ostream& cout, BigInt a){
    if(a.sign == -1) cout << '-';
    if(a.sign == 0) cout << 0;
    else
        for(int i = len(a) - 1; i >= 0; -- i)
            cout << a[i];
    return cout;
}
bool operator <(BigInt a, BigInt b){
    if(a.sign != b.sign)return a.sign < b.sign;
    if(len(a) != len(b)) return len(a) * a.sign < len(b) * b.sign;
    int i = len(a) - 1;
    while(i > 0 && a[i] == b[i]) -- i;
    return a[i] * a.sign < b[i] * b.sign;
}
bool operator >(BigInt a, BigInt b){
    return b < a;
}
bool operator <=(BigInt a, BigInt b){
    return !(b < a);
}
bool operator >=(BigInt a, BigInt b){
    return !(a < b);
}
bool operator ==(BigInt a, BigInt b){
    return a.sign == b.sign && a.d == b.d;   
}
bool operator !=(BigInt a, BigInt b){
    return !(a == b);
}
BigInt operator +(BigInt, BigInt);
BigInt operator -(BigInt a, BigInt b){
    if(b.sign == 0) return a;
    if(a.sign == 0) return -b;
    if(b.sign == -1) return a + -b;
    if(a.sign == -1) return -(-a + b);
    if(a < b) return -(b-a);
    for(int i = 0; i < len(a); ++ i){
        if(i < len(b)) a[i] -= b[i];
        if(a[i] < 0){
            a[i] += 10;
            a[i + 1] --;
        }
    }
    //cout << a.d;
    a.clz();
    //cout << a;
    return a;
}
BigInt operator +(BigInt a, BigInt b){
    if(a.sign == 0) return b;
    if(b.sign == 0) return a;
    if(b.sign == -1) return a - -b;
    if(a.sign == -1) return b - -a;
    int d = 0, len = (int)(max(len(a), len(b))), s;
    BigInt c;
    c.sign = 1;
    c.d.resize(len);
    for(int i = 0; i < len; ++ i){
        if(i < a.size()) d += a[i];
        if(i < b.size()) d += b[i];
        c[i] = d % 10;
        d /= 10;
    }
    if(d > 0) c.d.push_back(d);
    return c;
}
int operator %(BigInt a, int b){
    if(b == 0) exit(1);
    int s = 0;
    for(int i = a.size() - 1; i >= 0; -- i)
        s = (s * 10ll  +a[i]) % b;
    return s * a.sign;
}
BigInt operator /(BigInt a, int b){
    if(b == 0) exit(1);
    int s = 0;
    BigInt c;
    c.sign = a.sign * (b > 0 ? 1 : -1);
    if(b < 0) b = -b;
    for(int i = len(a) - 1; i >= 0; -- i){
        c.d.eb((s * 10 + a[i]) / b);
        s = (s * 10ll + a[i] % b);
    }
    reverse(all(c.d));
    c.clz();
    return c;
}
BigInt operator *(BigInt a, BigInt b){
    BigInt c;
    c.sign = a.sign * b.sign;
    c.d.resize(len(a) + len(b));
    for(int i = 0; i < len(a); ++ i)
        for(int j = 0; j < len(b); ++ j)
            c[i + j] += a[i] * b[j];
    for(int i = 0; i < len(c); ++ i){
        if(c[i] > 9){
            c[i + 1] += c[i] / 10;
            c[i] %= 10; 
        }
    }
    c.clz();
    return c;
}
BigInt operator %(BigInt a, BigInt b){
    BigInt c;
    if(b.sign < 0) b = -b;
    for(int i = len(a) - 1; i >= 0; -- i){
        c.sign = 1;
        if(c.sign || a[i]){
            c.d.push_front(a[i]);
            while(c >= b) c = c - b;
        }
    }
    c.sign *= a.sign;
    return c;
}
BigInt operator /(BigInt a, BigInt b){
    BigInt c, d;
    d.sign = a.sign * b.sign;
    if(b.sign == -1)  b = -b; 
    if(b.sign < 0) b = -b;
    for(int i = len(a) - 1, r; i >= 0; -- i){
        c.sign = 1;
        if(c.sign || a[i]){
            c.d.push_front(a[i]);
        }
        while(c >= b){c = c - b; ++ r;}
        d.d.push_front(r);
    }
    d.clz();
    return d;
}
BigInt operator *(BigInt a, int b){
    if(a.sign == 0 || b == 0) return BigInt("0");
    BigInt c;
    c.sign = a.sign;
    if(b < 0){
        c.sign *= -1;
        b = -b;
    }
    ll d = 0;
    for(int i = 0; i < len(a); ++ i){
        d += a[i] * b;
        c.d.push_back(d % 10);
        d /= 10;
    }
    while(d){
        c.d.push_back(d % 10); d /= 10;
    }
    return c;
}
istream& operator >> (istream& cin, vector<auto>&a){
    for(auto& x : a) cin >> x;
    return cin;
}
istream& operator >> (istream& cin, vector<vector<auto>>&a){
    for(int i = 0; i < len(a); ++ i){
        for(int j= 0; j < len(a[i]); ++ j) cin >> a[i][j];
    }return cin;
}
ostream& operator << (ostream& cout, vector<auto> a){
    for(auto i : a) cout << i << ' ';
    cout << '\n';
    return cout;
}
ostream& operator << (ostream& cout, vector<vector<auto>> a){
    for(int i = 0; i < len(a); ++ i){
        for(int j = 0; j < len(a[i]); ++ j) cout << a[i][j] << (j == len(a[i]) - 1 ? '\n' : ' ');
    }
    return cout;
}
void solve();

signed main() {
    std::ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifdef selenophile
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    // cin >> t;
    while (t--)solve();
    return 0;
}

void solve() {
    
}