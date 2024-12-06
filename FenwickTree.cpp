#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// Array Fenwcik Tree
template<class T>
struct FenwickTree {
    vector<T> tree;
    FenwickTree(int n){
        tree.resize(n);
    }
    ll sum(int r) {
        ll res = 0;
        for(;r>-1;r = (r & (r+1))-1) res += tree[r];
        return res;
    }
    ll sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }
    void add(int i, ll delta) {
        for(;i<tree.size();i|=i+1)tree[i] += delta;
    }
};


//Matrix FenwickTree
template<class T>
struct FenwickTree {
    vector<vector<T>> tree;
    FenwickTree(int n, int m){tree.resize(n, vector<T>(m));}
    void add(int I, int J, int delta) {
        for (int i = I;i<tree.size();i|= i + 1)
            for(int j = J;j<tree[i].size();j|=j+1) tree[i][j] += delta;
    }
    ll sum(int I, int J) {
        ll res = 0;
        for(int i = I;i>-1;i=(i&(i+1))-1)
            for(int j = J;j>-1;j=(j&(j+1))-1) res += tree[i][j];
        return res;
    }
    ll sum(int x1, int y1, int x2, int y2) {
        return sum(x2, y2) - sum(x1 - 1, y2) + sum(x1 - 1, y1 - 1) - sum(x2, y1 - 1);
    }
};