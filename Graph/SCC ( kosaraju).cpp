void solve() { 
    int n, m; cin >> n >> m;
    vector<int>adj[n + 1], revadj[n + 1];
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        revadj[v].push_back(u);
    }
    //SCC using kosaraju's algorithm
    function<void()> kosarajus = [&]() -> void {
        vector<bool> vis(n + 1, false);
        stack<int> st;
        function<void(int)> dfs1 = [&](int u) -> void {
            vis[u] = true;
            for(auto v : adj[u]) {
                if(!vis[v]) {
                    dfs1(v);
                }
            }
            st.push(u);
        };
        for(int i = 1; i <= n; i++) {
            if(!vis[i]) {
                dfs1(i);
            }
        }
        vis.assign(n + 1, false);
        function<void(int)> dfs2 = [&](int u) -> void {
            vis[u] = true;
            for(auto v : revadj[u]) {
                if(!vis[v]) {
                    dfs2(v);
                }
            }
        };
        int scc_count = 0;
        while(!st.empty()) {
            int u = st.top();
            st.pop();
            if(!vis[u]) {
                scc_count++;
                dfs2(u);
            }
        }
        cout << scc_count << "\n";
    };
    kosarajus();
     
}
 
