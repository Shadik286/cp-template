vector<int>divs[N];
void prec() {
    for(int i = 2; i * i < N; i++) {
        for(int j = i * i; j < N; j += i) {
            divs[j].push_back(i); 
            if(j / i != i) divs[j].push_back(j / i);
        }
    }
    for(int i = 1; i < N; i++) {
        sort(divs[i].begin(), divs[i].end());
    }
}
