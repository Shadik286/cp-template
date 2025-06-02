map<int, int> monotonic(vector<int>&v, int n) {
    stack<pair<int, int>>st;
    vector<int> index(n);
    for(int i = 0; i < n; i++) {
        while(!st.empty() && st.top().first >= v[i]) st.pop();
        if(st.empty()) index[i] = -1;
        else index[i] = st.top().second; 
        st.push({v[i], i});   
    }  
    // for(int i = 0; i < n; i++) {
    //     cout << index[i] << ' ';
    // } cout << "\n\n"; 
    // index[i] has the index of nearest smaller number than v[i] to the left. 

    //https://codeforces.com/contest/547/problem/B
}
problem: https://codeforces.com/contest/817/problem/D
solve: 8 9 1 2 3 4 1 7 for this first 1 covers whole array, so does 2nd 1 but it would repeat some subarrays, to avoid that for second 1 range should be 2, 3, 4, 1, 7
        so kept the index of first arriving numbers in an array and when get it again, replace left most by previously arrived index if its within the range (l = max(l, indx[num])

problem: https://atcoder.jp/contests/agc005/tasks/agc005_b
solve: 
void solve() { 
    int n; cin >> n;
    vector<int>sol(n); for(auto &i: sol) cin >> i;
    pair<int,int>range[n + 1] = {{0, 0}};
    stack<pair<int,int>>st;
    // calculating the nearest left bigger number
    for(int i = 0; i < n; i++) {
        while(st.size() and st.top().first >= sol[i]) st.pop();
        if(st.size()) range[i].first = st.top().second + 1;
        else range[i].first = 0;
        st.push({sol[i], i});
    }
    st = stack<pair<int, int>>();
    // calculating the nearest right bigger number
    for(int i = n - 1; i >= 0; i--) {
        while(st.size() and st.top().first >= sol[i]) st.pop();
        if(st.size()) range[i].second = st.top().second - 1;
        else range[i].second = n - 1;
        st.push({sol[i], i});
    } 
    // range[i] = l, r. where sol[i] is the local min in the range of l, r
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int l = range[i].first, r = range[i].second;
        int left = i - l, right = r - i + 1;
        ans += (left * right * sol[i]); 
        ans += ((right) * sol[i]);
    }
    cout << ans;
}
