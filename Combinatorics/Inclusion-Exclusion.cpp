-> Go through all the subsets, if the len is odd add(Inclusion) the ans, else minus(Exclusion).
vector<vector<int>> allSubsets(vector<int>sol) {
    int n = sol.size();
    vector<vector<int>>strs;
    for(int i = 0; i < (1 << n); i++) {
        vector<int>tmp;
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) tmp.push_back(sol[j]);
        } 
        strs.push_back(tmp);
    } 
    return strs;
} 
int lca(int a, int b) {
    return (a * b) / __gcd(a, b);
}
void solve() {
    int n, k; cin >> n >> k;
    vector<int>sol(k); for(auto &i: sol) cin >> i;
    int ans = 0;
    vector<vector<int>>all = allSubsets(sol); 
    for(auto i: all) {
        if(i.size() == 0) continue;
        int tt = 1;
        for(auto j: i) { 
            // tt = lca(tt, j);
            if(tt > n / j) {
                tt = n + 1; break;
            }
            tt *= j; 
        }
        if(i.size() % 2) {
            ans += (n / tt);
        } 
        else {
            ans -= (n / tt);
        }
    }
    cout << ans;
}
//https://cses.fi/problemset/task/2185/


