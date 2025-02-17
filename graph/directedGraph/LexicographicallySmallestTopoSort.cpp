#include <bits/stdc++.h>
 
using namespace std;
 
void solve() {   
    int n; 
    cin >> n;
    int m; 
    cin >> m;
 
    vector<vector<int>> edges(n);
    vector<int> inDegree(n);
 
    for (int i = 0; i < m; i++) {
        int a, b; 
        cin >> a >> b;
        a--; b--;
        edges[a].push_back(b);
        inDegree[b]++;
    }
 
    auto topoSort = [&](vector<vector<int>> &edges) -> vector<int> {
        priority_queue<int, vector<int> , greater<>> pq;

        vector<int> ans;
 
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                pq.push(i);
            }
        }
 
        while (!pq.empty()) {
            int u = pq.top();
            pq.pop();
            ans.push_back(u);
 
            for (auto &v : edges[u]) {
                inDegree[v]--;
                if (inDegree[v] == 0) pq.push(v);
            }
        }
 
        return ans;
    };
 
    vector<int> ans = topoSort(edges);
 
    if (ans.size() != n) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
 
    for (auto &i : ans) {
        cout << (i + 1) << " "; 
    }
    cout << endl;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
#ifndef ONLINE_JUDGE
    freopen("../../input.txt", "r", stdin);
    freopen("../../output.txt", "w", stdout);
    freopen("../../error.txt", "w", stderr);
#endif
 
    int tc = 1; 
    cin >> tc;

    while(tc--){
        solve();
    }
 
    return 0;
}