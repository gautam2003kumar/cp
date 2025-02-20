#include<bits/stdc++.h>
using namespace std;
/*
Given an array of positive integers find the length of longest subarray with sum <= k
*/
void prob1(){
    int n, k; cin >> n >> k;
    vector<int> a(n);

    for(auto &i: a) cin >> i;

    int sum = 0, j = 0;
    int ans = -1;

    for(int i = 0; i < n; i++){
        sum += a[i];

        while(sum > k){
            sum -= a[j++];
        }

        ans = max(ans, i-j+1);
    }

    cout << ans << endl;
}

/*
Given an array find the length of longest subarray with not more than k distinct elements
*/
void prob2(){ 
    int n, k; cin >> n >> k;
    vector<int> a(n);

    for(auto &i: a) cin >> i;

    int j = 0;
    map<int, int> mp;
    int ans = -1;

    for(int i = 0; i < n; i++){
        
        mp[a[i]]++;
        while(mp.size() > k){
            mp[a[j]]--;
            
            if(mp[a[j]] == 0){
                mp.erase(a[j]);
            }
            j++;
        }
        ans = max(ans, i-j+1);
    }

    cout << ans << endl;
}

/*
    Given an array of positive integers find the length of smallest subarray with sum of elements >= k
*/
void prob3(){
    int n; cin >> n;
    vector<int> a(n);

    for(auto &i: a) cin >> i;
    
    
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
#endif

    prob2();

return 0;
}