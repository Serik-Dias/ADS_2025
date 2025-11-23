#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    vector<int> in_degree(n + 1, 0);

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        in_degree[v]++;
    }

    queue<int> q;
    for(int i = 1; i <= n; i++)
        if(in_degree[i] == 0)
            q.push(i);

    vector<int> topo;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        topo.push_back(u);
        for(int v : g[u]) {
            in_degree[v]--;
            if(in_degree[v] == 0)
                q.push(v);
        }
    }

    if(topo.size() != n) {
        cout << "Impossible";
    } else {
        cout << "Possible\n";
        for(int i = 0; i < n; i++)
            cout << topo[i] << " ";
    }
}