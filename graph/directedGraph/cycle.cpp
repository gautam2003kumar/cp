#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges(n);

    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--; b--;
        edges[a].push_back(b);
    }

    vector<bool> vis(n), inStack(n);
    bool cycleExist = false;
    
    auto cycle = [&](int node, auto && self) -> void {

        inStack[node] = vis[node] = true;

        for(auto &i: edges[node]){
            if(!vis[i]) self(i, self);
            else if(inStack[i]) cycleExist = true;
        }

        inStack[node] = false;
    };

    for(int i = 0; i < n; i++){
        if(vis[i]) continue;
        cycle(i, cycle);
    }

    if(cycleExist){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    freopen("../../error.txt", "w", stderr);
#endif


    solve();

    return 0;
}