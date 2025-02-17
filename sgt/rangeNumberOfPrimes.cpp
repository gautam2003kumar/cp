#include <bits/stdc++.h>
using namespace std;

class SegmentTree{

private:
    vector<int> prime;
    vector<int> tree;
    int n;
    vector<int> a;


public:
    SegmentTree(int n, vector<int> arr){
        this->n = n;
        tree.resize(4*n, 0);
        a = arr;
        
        prime.assign(1e6+1, 0);
        sieveOfEratosthenes(1e6);

        for(int i = 0; i < n; i++){
            a[i] = prime[arr[i]] ? 1 : 0;
        }

        build(0, 0, n-1);
    }

    void sieveOfEratosthenes(int n){
        prime.assign(n+1, true);
        prime[0] = prime[1] = false;
          
        for(int i = 2; i * i <= n; i++){
            
            if(prime[i]){
                for(int j = i*i; j <= n; j += i){
                    prime[j] = false;
                }
            }
        }
    }

    int leftNode(int i){
        return 2*i+1;
    }

    int rightNode(int i){
        return 2*i+2;
    }

    int comb(int a, int b){
        return a+b;
    }

    void build(int i, int start, int end){
        if(start == end){
            tree[i] = a[start];
            return;
        }

        int mid = (start + end) / 2;

        build(leftNode(i), start, mid);
        build(rightNode(i), mid+1, end);

        tree[i] = comb(tree[leftNode(i)], tree[rightNode(i)]);
    }

    void update(int idx, int value, int i, int start, int end){

        if(start == end){
            tree[i] = prime[value] ? 1 : 0;
            a[idx] = value;
            return;
        }

        int mid = (start + end) / 2;

        if(idx <= mid){
            update(idx, value, leftNode(i), start, mid);
        }else {
            update(idx, value, rightNode(i), mid+1, end);
        }

        tree[i] = comb(tree[leftNode(i)],tree[rightNode(i)]);
    }

    void update(int idx, int value){
        update(idx, value, 0, 0, n-1);
    }

    int query(int l, int r, int i, int start, int end){

        if(l > end || r < start){
            return 0;
        }

        if(l <= start && end <= r){
            return tree[i];
        }


        int mid = (start + end) / 2;

        int sumL = query(l, r, leftNode(i), start, mid);
        int sumR = query(l, r, rightNode(i), mid+1, end);

        return comb(sumL , sumR);
    }

    int query(int l, int r){
        return query(l, r, 0, 0, n-1);
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
