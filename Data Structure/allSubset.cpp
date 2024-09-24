void allSubsets(vector<int>sol) {
    int n = sol.size();
    vector<vector<int>>strs;
    for(int i = 0; i < (1 << n); i++) {
        vector<int>tmp;
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) tmp.push_back(sol[j]);
        } 
        strs.push_back(tmp);
    } 
    for(auto i: strs) {
        for(auto j : i) cout << j << ' '; cout << '\n';
    }
}
