vector<int> log2arr;
void build() {
    for(int i = 2; i < (int)(log2arr.size()); ++ i) log2arr[i] = log2arr[i>>1] + 1;
}
template<class T>
struct sparsetable{
    vector<vector<T>> dp;
    int sz;
    T func(T l, T r) {
        return l > r ? r : l;
    };
    sparsetable(vector<T> &a) {
        sz = (int)a.size();
        dp.resize(log2arr[sz]+1);
        dp[0] = a;
        for(int h = 1; h < (int)(dp.size()); ++ h) {
            dp[h].resize(sz - (1<<h) + 1);
            for(int i = 0; i < (int)(dp[h].size()); ++ i)
                dp[h][i] = func(dp[h-1][i], dp[h - 1][i + (1<<(h-1))]);
        }
    };
    T get(T l, T r) {
        int lg = log2arr[r-l+1];
        return func(dp[lg][l], dp[lg][r - (1<<lg) + 1]); 
    };
};
