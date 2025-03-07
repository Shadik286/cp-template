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
