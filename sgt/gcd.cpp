#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
    vector<int> tree;
    vector<int> a;
    int n;

public: 
    SegmentTree(int n, vector<int> arr) {
        this->n = n;
        a = arr;
        tree.resize(4 * n, 0);
        build(0, 0, n - 1);
    }

    int comb(int a, int b) {
        auto gcd = [&](int x, int y) -> int {
            while (y != 0) {
                int temp = y;
                y = x % y;
                x = temp;
            }
            return x;
        };
        return gcd(a, b);
    }

    int leftNode(int i) {
        return 2 * i + 1;
    }

    int rightNode(int i) {
        return 2 * i + 2;
    }

    void build(int i, int start, int end) {
        if (start == end) {
            tree[i] = a[start];
            return;
        }

        int mid = (start + end) / 2;
        build(leftNode(i), start, mid);
        build(rightNode(i), mid + 1, end);

        tree[i] = comb(tree[leftNode(i)], tree[rightNode(i)]);
    }

    void update(int idx, int value, int i, int start, int end) {
        if (start == end) {
            tree[i] = value;
            a[idx] = value;
            return;
        }

        int mid = (start + end) / 2;
        if (idx <= mid) {
            update(idx, value, leftNode(i), start, mid);
        } else {
            update(idx, value, rightNode(i), mid + 1, end);
        }

        tree[i] = comb(tree[leftNode(i)], tree[rightNode(i)]);
    }

    void update(int idx, int value) {
        update(idx, value, 0, 0, n - 1);
    }

    int query(int l, int r, int i, int start, int end) {
        if (l > end || r < start) {
            return 0;  // GCD with 0 is neutral
        }

        if (l <= start && end <= r) {
            return tree[i];
        }

        int mid = (start + end) / 2;
        int gcdL = query(l, r, leftNode(i), start, mid);
        int gcdR = query(l, r, rightNode(i), mid + 1, end);

        return comb(gcdL, gcdR);
    }

    int query(int l, int r) {
        return query(l, r, 0, 0, n - 1);
    }
};

void solve() {
    int n, q; 
    cin >> n >> q;

    vector<int> a(n);
    for (auto &i : a) cin >> i;

    SegmentTree sgt(n, a);

    for (int i = 0; i < q; i++) {
        int t; 
        cin >> t;

        if (t == 1) {
            int idx, value;
            cin >> idx >> value;
            sgt.update(idx-1, value);
        } else { 
            int l, r; 
            cin >> l >> r;
            int ans = sgt.query(l - 1, r - 1);
            cout << ans << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    int tc = 1; 
    // cin >> tc; 

    while (tc--) {
        solve();
    }

    return 0;
}
