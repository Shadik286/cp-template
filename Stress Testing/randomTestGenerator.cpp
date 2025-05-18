#include<bits/stdc++.h>

using namespace std;

int random(int a, int b){
    if(a>b)
        swap(a,b);
    return a + rand()%(b - a + 1);
}

int main(int argc, char* argv[]){
    srand(time(0));

    int n= random(1, 10);
    cout << n << '\n';
    for(int i = 0; i < n; i++) {
        cout << random(1, 1000) << ' ';
    }
    cout << "\n";
    int q= random(1, 10);
    cout << q << '\n';
    for(int i = 0; i < q; i++) {
        for(int j = 0; j <= 9; j++) cout << j << ' ';
        cout << random(1, 1000) << '\n';
    }

}
