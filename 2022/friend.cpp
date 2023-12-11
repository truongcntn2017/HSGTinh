#include<bits/stdc++.h>
using namespace std;
int n, k, m;

vector<int> adj[1000002];
bool visited[1000002];

void dfs(int u){
    visited[u] = true;

    for (int v: adj[u]){
        if (!visited[v]){
            dfs(v);
        }
    }
}

int main()
{

    cin >> n >> k >> m;

    for (int i=1; i <= m; i++){
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(k);

    int counter = 0;

    for (int i=1; i<=n; i++)
        if (visited[i])
            counter++;


    cout << counter - 1;


    return 0;
}