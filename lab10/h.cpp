#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> g;
bool used[105][105];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void dfs(int x, int y){
    used[x][y] = true;
    for(int k = 0; k < 4; k++){
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if(!used[nx][ny] && g[nx][ny] == '1'){
            dfs(nx, ny);
        }
    }
}

int main(){
    cin >> n >> m;
    g.resize(n);
    for(int i = 0; i < n; i++){
        cin >> g[i];
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!used[i][j] && g[i][j] == '1'){
                ans++;
                dfs(i,j);
            }
        }
    }

    cout << ans;
    return 0;
}