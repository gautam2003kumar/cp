#include<bits/stdc++.h>
using namespace std;
#define int long long

void prob1(){
    int n, k; cin >> n >> k;
    vector<int> a(n);

    for(auto &i: a) cin >> i;

    int sum = 0, j = 0;
    int ans = n+1;

    for(int i = 0; i < n; i++){
        sum += a[i];

        while(sum >= k){
            ans = min(ans, i-j+1);
            sum -= a[j++];
        }
    }
    cout << (ans == n+1 ? -1 : ans) << endl;
}
signed main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
#endif

    prob1();

return 0;
}