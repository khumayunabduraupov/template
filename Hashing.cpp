ll Hash(string s, int b, int m) {
        ll res = 0;
        for(char i : s) res = (res * b + (i - 48)) % m;
        return res;
    }