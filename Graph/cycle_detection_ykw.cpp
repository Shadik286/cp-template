bool dfs(int u) {
  if (!cycle.empty()) return 1;
  vis[u] = 1;
  for (auto [v, id] : g[u]) {
    if (v != par[u]) {
      if (vis[v] == 0) {
        par[v] = u;
        e_id[v] = id;
        if (dfs(v)) return 1;
      }
      else if (vis[v] == 1) {
        // cycle here
        cycle.push_back(id);
        for (int x = u; x != v; x = par[x]) {
          cycle.push_back(e_id[x]);
        }
        return 1;
      }
    }
  }
  vis[u] = 2;
  return 0;
}