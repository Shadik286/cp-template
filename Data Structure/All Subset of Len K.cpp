int data[N], arr[N];
int n, k;
void subArrayOfLenK(int index, int i) {
    if(index == k) {
        // subset generated.
        for(int j = 0; j < k; j++) cout << data[j] << ' ';
        cout << '\n'; return;
    } 
    if(i >= n) return; //No subset found 
    subArrayOfLenK(index, i + 1);
    data[index] = arr[i];
    subArrayOfLenK(index + 1, i + 1);
} 
