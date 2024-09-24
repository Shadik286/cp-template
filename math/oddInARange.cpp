int countOdd(int l, int r) {
    int n = (r - l) >> 1;
    if(r % 2 or l % 2) n++;
    return n;
}
