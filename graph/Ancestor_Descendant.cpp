/*
Givevn a rooted tree with N node and Q queries.

for each query of the form X, Y check whether X ia ancestor of y or not

N <= 1e5 , Q <= 1e5
*/

#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; 
    cin >> n;
    vector<vector<int>> adj(n + 1);

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> in(n + 1, 0), out(n + 1, 0);
    int t = 0;

    auto dfs = [&](int node, int parent, auto &&self) -> void {
        in[node] = t++;

        for (auto &v : adj[node]) {
            if (v == parent) continue;
            self(v, node, self);
        }

        out[node] = t++;
    };

    dfs(1, -1, dfs);

    for(int i = 1; i <= n; i++){
        cout << i << " : " << in[i] << " " << out[i] << endl;
    }

    int q;
    cin >> q;

    for(int i = 0; i < q; i++){
       int x , y;
        cin >> x >> y;
       cout << ((in[x] < in[y] && out[x] > out[y])  ? "YES" : "NO") << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    #endif

    solve();

    return 0;
}
