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
    vector<int> topoSort;
    vector<bool> vis(n, false);

    auto dfs = [&](int node, auto && self)-> void {
        vis[node] = true;

        for(auto &i: edges[node]){
            if(vis[i]) continue;

            self(i, self);
        }

        topoSort.push_back(node);
    };

    for(int i = 0; i < n; i++){
        if(vis[i]) continue;
        dfs(i, dfs);
    }
    reverse(topoSort.begin(), topoSort.end());

    for(auto &i: topoSort){
        cout << i+1 << " ";
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