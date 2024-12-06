template<typename T> 
    vector<ll> z_func(T s) {
        vector<ll> z(len(s), 0);
        for(ll i = 1, j = 0, r = 1; i < len(s); ++ i) {
            z[i] = max(0ll, min(z[i-j], r - i));
            while(i + z[i] < len(s) && s[z[i]] == s[i+z[i]]) ++ z[i];
            if(i + z[i] > r) {
                j = i;
                r = z[i] + i;
            }
        }
        return z;
    }