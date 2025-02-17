#include<bits/stdc++.h>
using namespace std;

class SegmentTree{
    
}

void solve(){
    int n, q; cin >> n >> q;

    vector<int> a(n);
    for(auto &i: a) cin >> i;

    SegmentTree sgt(n, a);

    for(int i = 0; i < q; i++){
        int t; cin >> t;

        if(t == 1){
            int idx, value; cin >> idx >> value;

            sgt.update(idx, value);
        }else{
            int l, r; cin >> l >> r;
            int minValueIndex = sgt.queries(l, r);
            
            cout << minValueIndex << endl;
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
    solve()

    return 0;
}