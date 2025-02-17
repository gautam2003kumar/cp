#include<bits/stdc++.h>
using namespace std;
#define int long long

class SegmentTree {
    vector<int> sum;
    vector<int> a;
    int n;

public:
    SegmentTree(int n, vector<int>& arr) : n(n), a(arr) {
        sum.resize(4 * n, 0);
        build(0, 0, n - 1);
    }

    int leftNode(int index) {
        return index * 2 + 1;
    }

    int rightNode(int index) {
        return index * 2 + 2;
    }
    int comb(int a, int b){
        return a + b;
    }
    void build(int index, int start, int end) {
        if (start == end) {
            sum[index] = a[start];
            return;
        }

        int mid = (start + end) / 2;
        build(leftNode(index), start, mid);
        build(rightNode(index), mid + 1, end);

        sum[index] = comb(sum[leftNode(index)] , sum[rightNode(index)]);
    }

    void update(int idx, int value, int index, int start, int end) {
        if (start == end) {
            sum[index] = value;
            a[idx] = value;
            return;
        }

        int mid = (start + end) / 2;
        if (idx <= mid) {
            update(idx, value, leftNode(index), start, mid);
        } else {
            update(idx, value, rightNode(index), mid + 1, end);
        }

        sum[index] = sum[leftNode(index)] + sum[rightNode(index)];
    }

    void update(int idx, int value) {
        update(idx, value, 0, 0, n - 1);
    }

    int query(int l, int r, int index, int start, int end) {
        if (r < start || l > end) {
            return 0;
        }

        if (l <= start && end <= r) {
            return sum[index];
        }

        int mid = (start + end) / 2;
        int leftSum = query(l, r, leftNode(index), start, mid);
        int rightSum = query(l, r, rightNode(index), mid + 1, end);

        return leftSum + rightSum;
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
            sgt.update(idx , value);
        } else if (t == 2) {
            int l, r;
            cin >> l >> r;
            cout << sgt.query(l , r-1) << endl;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
#ifndef ONLINE_JUDGE
   freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
   freopen("../error.txt", "w", stderr);
#endif
    
    // int tc = 1;
    cin >> tc;
    while (tc--) {
       solve();
   }
   
   return 0;
}