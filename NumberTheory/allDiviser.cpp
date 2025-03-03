#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;

    int count = 1, exponent = 0;
    
    //for even even divisors
    while(n%2 == 0){
        exponent++;
        n /= 2;
    }

    count = (exponent+1);

    for(int i = 3; i * i <= n; i += 2){
        exponent = 0;
        while(n%i == 0){
            exponent++;
            n /= i;
        }
        count *= (exponent+1);
    }

    if(n > 1){
        count *= 2;
    }

    cout << count << endl;
}

signed main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
#endif

    int t; cin >> t;

    while(t--){
        solve();
    }

return 0;
}