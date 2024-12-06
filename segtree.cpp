template<class t>
struct segtree{
    vector<t> arr, tree;
    int n;
    t func(t l, t r) {
        return r ? func(r, l % r) : l;
    }
    void build(int v, int l, int r) {
        if(l==r) {
            tree[v] = arr[l-1];
            return;
        }
        int m = (l + r) >> 1;
        build(v << 1, l, m);
        build(v << 1 | 1, m + 1, r);
        tree[v] = func(tree[v<<1], tree[v<<1|1]);
    }
    segtree(vector<t>&a){
        arr=a;
        n = (int)(a.size());
        tree.resize(n<<2);
        build(1, 1, n);
    }

    void update(int v, int l, int r, int i, t delta) {
        if(l == r) {
            tree[v] = delta;
            return;
        }
        int mid = (l + r) >> 1;
        if(mid >= i)update(v * 2, l, mid, i, delta);
        else update(v * 2 + 1, mid + 1, r, i, delta);
        tree[v] = func(tree[v<<1], tree[v<<1|1]);
    }
    void update(int i, t delta) {
        update(1, 1, n, i, delta);
    }
    t get(int v, int l, int r, int L, int R) {
        if(l == L && r == R) return tree[v];
        int mid = (l + r) >> 1;
        if(R <= mid) return get(v<<1, l, mid, L, R);
        if(mid < L)return get(v << 1 | 1, mid + 1, r, L, R);
        return func(get(v << 1, l, mid,L, mid), get(v<<1|1, mid+1,r, mid + 1, R));
    }
    t get(int l, int r) {
        return get(1, 1, n, l, r);
    }
};
