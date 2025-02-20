#include<bits/stdc++.h>

using namespace std;

/*
Given 2 sorted arrays, for each element in 1st array find number of elements smaller than that in 2nd array
input:-
    1 4 5 9
    2 3 6 10

output:-
    0 2 2 3
*/

void ans(){
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);

    vector<int> ans(n);
    for(auto &i: a) cin >> i;
    for(auto &i: b) cin >> i;

    int i = 0, j = 0;

    while(i < n){
        while(a[i] > b[j] && j < m){
            j++;
        }
        ans[i] = j;
        i++;
    }

    for(auto &i: ans){
        cout << i << " ";
    }

}


void solve(){
    int n, m; cin >> n >> m;

    vector<int> a(n), b(m), c(m+n);
    for(auto &i: a) cin >> i;
    for(auto &i: b) cin >> i;

    int i = 0, j = 0, k = 0;

    while(i < n && j < m){
        if(a[i] < b[j]){
            c[k] = a[i], i++, k++;
        }else{
            c[k] = b[j], k++, j++;
        }
    }

    while(i < n){
        c[k] = a[i], k++, i++;
    }

    while(j < m){
        c[k] = b[j], k++, j++;
    }

    for(auto &i: c){
        cout << i << " ";
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);
#endif

    ans();

return 0;
}