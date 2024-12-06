vector<int> suffix_array(string s) {
        int n = len(s);
        vector<int> c(n);
        vector<pair<pair<int, int>, int>> v(n);
        auto set_class = [&]() -> void {
            sort(all(v));
            int classes = 0;
            c[v[0].ss] = classes;
            for(int i = 1; i < n; ++ i) {
                if(v[i - 1].first != v[i].first) ++ classes;
                c[v[i].ss] = classes;
            }
        };  
        for(int i = 0; i < n; ++ i) v[i] = {{s[i], 0}, i};
        set_class();
        for(int h = 0; (1ll << h) < n; ++ h) {
            for(int i = 0; i < n; ++ i) v[i] = {{c[i], c[(i + (1ll<<h))%n]}, i};
        }
        vector<int> p(n);
        iota(all(p), 0);
        sort(all(p), [&](int r, int l) {
            return c[r] < c[l];
        });
        return p;
    }