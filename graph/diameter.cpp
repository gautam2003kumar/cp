#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<vector<int>> g(N);
vector<int> depth(N);

void dfs( int vertex, int par = -1){
    
    for(auto &nev: g[vertex]){
        if(nev == par) continue;
        depth[nev] = depth[vertex] +1;
        dfs(nev, vertex);
    }
}

void solve(){
    int n; 
    cin >> n;

    for( int i = 1; i < n; i++){
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(8);

    int mx = -1, mxNode;
    for(int i=1; i<=n; i++){
        if(mx < depth[i]){
            mx = depth[i];
            mxNode = i;
        }
        depth[i] = 0;
    }

    dfs(mxNode);
    mx = -1;
    for(int i = 1; i <= n; i++){
        mx = max(mx, depth[i]);
    }

    cout << mx << endl;
}

int main(){
    freopen("../input.txt","r",stdin);
    freopen("../output.txt","w",stdout);

    solve();

    return 0;
}