// BismillahirRahmaanirRaheem
# include <bits/stdc++.h>
# define int long long
# define ll long long
# define MAXSZ 2000000
# define NUMLEN 19

using namespace std;

int trie[MAXSZ][11];    // index 10 contains # strings
int sz = 1;
int qry[10];

void query ()
{
    int ans, curr, length, idx;
    string num;
    for (int i = 0; i < 10; i++)
        cin >> qry[i];
    cin >> num;
    ans = 0;
    
    length = num.size();
    curr = 0;
    for (int i = length; i < NUMLEN; i++)
    {
        if (trie[curr][0] == 0)
        {
            cout << "0\n";
            return;
        }
        curr = trie[curr][0];
    }
    for (int i = 0; i < length; i++)
    {
        idx = num[i] - '0';
        for (int j = 0; qry[j] != idx; j++)
            ans += trie[trie[curr][qry[j]]][10];
        if (trie[curr][idx] == 0)
            break;
        curr = trie[curr][idx];
    }
    cout << ans << '\n';
    return;
}

void solve ()
{
    string num;
    int n, curr, length, idx;
    cin >> n;
    for (int j = 0; j < n; j++)
    {
        cin >> num;
        length = num.size();
        curr = 0;
        for (int i = length; i < NUMLEN; i++)
        {
            if (trie[curr][0] == 0)
                trie[curr][0] = sz++;
            curr = trie[curr][0];
            trie[curr][10]++;
        }
        for (int i = 0; i < length; i++)
        {
            idx = num[i] - '0';
            if (trie[curr][idx] == 0)
                trie[curr][idx] = sz++;
            curr = trie[curr][idx];
            trie[curr][10]++;
        }
    }
    
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
        query ();
}

int32_t main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
}