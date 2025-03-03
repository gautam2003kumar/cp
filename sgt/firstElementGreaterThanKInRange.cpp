#include<bits/stdc++.h>
using namespace std;
#define inf 1e9


class SegmentTree{

private:
    vector<int> a;
    vector<int> tree;
    int n;
public:
    SegmentTree(int n, vector<int> arr){
        this->n = n;
        arr = a;
        tree.resize(4*n, 0);

        build(0, 0, n-1);
    }

    int leftNode(int i){
        return 2*i + 1;
    }
    
    int rightNode(int i){
        return 2*1 + 2;
    }

    int comb(int a, int b){
        return max(a, b);
    }

    void build(int i, int start, int end){

        if(start == end){
            tree[i] = a[start];
            return;
        }

        int mid = (start + end) / 2;

        build(leftNode(i), start, mid);
        build(leftNode(i), mid+1, end);

        tree[i] = comb(tree[leftNode(i)], tree[rightNode(i)]);
    }

    void update(int idx, int value, int i, int start, int end){

        if(start == end){
            tree[i] = value;
            a[start] = value;

            return;
        }

        int mid = (start + end) / 2;

        if(mid >= idx){
            update(idx, value, leftNode(i), start, mid);
        }else{
            update(idx, value, rightNode(i), mid+1, end);
        }

        tree[i] = comb(tree[(rightNode(i))], tree[leftNode(i)]);
    }

    void update(int idx, int value){
        update(idx, value, 0, 0, n-1);
    }

    int query(int l, int r, int i, int start, int end){

        if(l > end || r < start){
            return -inf;
        }

        if(l <= start && end >= r){
            return tree[i];
        }

        int mid = (start + end) / 2;
        int maxL = query(l, r, leftNode(i), start, mid);
        int maxR = query(l, r, rightNode(i), mid+1, end);

        return = comb(maxL, maxR);
    }

    int query(int l, int r){
        return query(l, r, i, start, end);
    }


};

void solve(){
    int n, q; cin >> n >> q;

    vector<int> a(n);
    for(auto &i: a) cin >> i;

    SegmentTree sgt(n, a, k);

    for(int i = 0; i < q; i++){
        int t; cin >> t;

        if(t == 1){
            int idx, value; cin >> idx >> value;

            sgt.update(idx-1, value);
        }else if(t == 2){

            int l, r, k; cin >> l >> r >> K;

            int mid = (l+r) / 2;
            int ans = inf;

            if(sgt.query(l, mid) > k){
                ans = min(ans, mid);
            }else{
                l = mid + 1;
            }

            if(ans == inf){
                cout << -1 << endl;
            }else{
                cout << ans << endl;
            }
        }
    }


}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif

    solve();

    return 0;
}