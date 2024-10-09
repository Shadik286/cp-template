vector<int>adj[N];

struct LCA {    //log(n) on each query

    int n, l = 20, timer = 0, m;
    vector<int>tin, tout, dept;  
    vector<vector<int>>up;

    LCA(int n, int m) { 
      this->n = n, this->m = m; 
      tin.resize(n + 1, 0), tout.resize(n + 1, 0);
      up.assign(n + 1, vector<int>(l + 2));  dept.resize(n + 1, 0);
    }  

    void input(int m) {
      for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b); adj[b].push_back(a);
      }
    }

    void dfs(int node = 1, int par = 1) {
      tin[node] = ++timer;
      up[node][0] = par;
      for(int i = 1; i <= l; i++) {
        up[node][i] = up[up[node][i-1]][i-1]; 
      } 
      for(auto child: adj[node]) {
        if(child == par) continue; 
        dept[child] = dept[node] + 1;
        dfs(child, node);
      } 
      tout[node] = ++timer;
    } 

    bool is_ancestor(int u, int v) {
      return tin[u] <= tin[v] and tout[u] >= tout[v];
    } 

    int lca(int u, int v) {
      if(is_ancestor(u, v)) return u;
      if(is_ancestor(v, u)) return v;
      for(int i = l; i >= 0; i--) {
        if(is_ancestor(up[u][i], v)) continue;
        u = up[u][i];
      } 
      return up[u][0];
    } 

    int kth(int u, int k) {
      assert(k >= 0);
      for(int i = 0; i <= l; i++) {
        if (k & (1 << i)) u = up[u][i];
      } 
      return u;
    } 

    //kth element while going from u towards v.
    int kth_form_u2v(int u, int v, int k) {
      int l = lca(u, v);
      int d = dept[u] + dept[v] - (dept[l] << 1); 
      if(k > d) k = d;
      assert(k <= d);
      if (dept[l] + k <= dept[u]) return kth(u, k);
      k -= dept[u] - dept[l];
      return kth(v, dept[v] - dept[l] - k);
    }

    int dist(int u, int v) {
      int mid = lca(u, v); 
      return dept[u] + dept[v] - (dept[mid] << 1);
    }

};
