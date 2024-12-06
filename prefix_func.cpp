template<typename T>
    vector<ll> prefix_func(T s) {
    vector<ll> p(len(s), 0);
    for (ll i = 1, k; i < len(s); ++ i) {
            k = p[i - 1];
            while(s[i] - s[k] && k > 0) k = p[k - 1];
            p[i] = s[i] == s[k] ? k + 1 : 0;
        }
        return p;
    }