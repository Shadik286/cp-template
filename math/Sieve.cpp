vector<int>pms;
vector<int>fnd(N);
void prec() { 
    for(int i = 2; i < N; i++) {
        if(fnd[i]) continue;
        fnd[i] = i; pms.push_back(i);
        for(int j = i + i; j < N; j += i) {
            fnd[j] = i; 
        } 
    } 
} 
// Below function returns the primes that divides number n. (Filters out the primes that are not divisors of n) 
//https://codeforces.com/problemset/problem/1766/D to solve this problem below function is needed.
set<int>dv(int n) { 
    set<int>tmp;  
    while(n > 1) {  
        tmp.insert(fnd[n]); 
        n /= fnd[n];
    }
    return tmp;
}
