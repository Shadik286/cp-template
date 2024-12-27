int max_sub_array_sum(vector<int>&sol) {
    int sm = 0, n = sol.size(), ans = 0;
    for(int i = 0; i < n; i++) {
        sm = max(sm + sol[i], sol[i]);
        ans = max(ans, sm);
    }
    return ans;
}
