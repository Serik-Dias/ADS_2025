#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> g;

bool check_dag_bfs(int bx, int by) {
    vector<int> in_degree(n + 1, 0);
    for(int u = 1; u <= n; u++)
        for(int v : g[u])
            if(!(u == bx && v == by))
                in_degree[v]++;
    queue<int> q;
    for(int i = 1; i <= n; i++)
        if(in_degree[i] == 0)
            q.push(i);
    int cnt = 0;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        cnt++;
        for(int v : g[u])
            if(!(u == bx && v == by)) {
                in_degree[v]--;
                if(in_degree[v] == 0) q.push(v);
            }
    }
    return cnt == n;
}

bool dfs_cycle(int u, vector<int> &vis, vector<int> &par, vector<pair<int,int>> &cyc) {
    vis[u] = 1;
    for(int v : g[u]) {
        if(vis[v] == 0) {
            par[v] = u;
            if(dfs_cycle(v, vis, par, cyc)) return true;
        } else if(vis[v] == 1) {
            int x = u;
            cyc.push_back({u,v});
            while(x != v) {
                cyc.push_back({par[x], x});
                x = par[x];
            }
            return true;
        }
    }
    vis[u] = 2;
    return false;
}

int main() {
    cin >> n >> m;
    g.assign(n + 1, {});
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        g[x].push_back(y);
    }

    vector<int> vis(n + 1, 0), par(n + 1, -1);
    vector<pair<int,int>> cyc;
    for(int i = 1; i <= n; i++)
        if(vis[i] == 0)
            if(dfs_cycle(i, vis, par, cyc)) break;

    if(cyc.empty()) {
        cout << "YES";
        return 0;
    }

    for(auto &e : cyc) {
        if(check_dag_bfs(e.first, e.second)) {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
}