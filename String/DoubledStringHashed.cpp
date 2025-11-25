#include <bits/stdc++.h>
using namespace std;

#define int long long

class DoubleHash {
    // --- hash parameters ---
    static const long long mod1 = 1000000007LL;
    static const long long mod2 = 1000000009LL;

    // RNG + random bases (initialized in-class; rng constructed before base1/base2)
    mt19937_64 rng{ (unsigned)chrono::steady_clock::now().time_since_epoch().count() };
    long long base1 = uniform_int_distribution<long long>(256, mod1 - 2)(rng);
    long long base2 = uniform_int_distribution<long long>(256, mod2 - 2)(rng);

    vector<long long> pow1, pow2;
    vector<long long> h1, h2;
    int n;

public:
    DoubleHash(const string &s) {
        n = (int)s.size();

        pow1.assign(n + 1, 1);
        pow2.assign(n + 1, 1);
        h1.assign(n + 1, 0);
        h2.assign(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            pow1[i] = (pow1[i - 1] * base1) % mod1;
            pow2[i] = (pow2[i - 1] * base2) % mod2;
        }

        // prefix hash
        for (int i = 0; i < n; i++) {
            h1[i + 1] = (h1[i] * base1 + (unsigned char)s[i]) % mod1;
            h2[i + 1] = (h2[i] * base2 + (unsigned char)s[i]) % mod2;
        }
    }

    // substring hash [l, r] (1-indexed inclusive)
    pair<long long, long long> getHash(int l, int r) {
        if (l < 1) l = 1;
        if (r > n) r = n;
        if (l > r) return {0, 0};

        long long x1 = (h1[r] - (h1[l - 1] * pow1[r - l + 1]) % mod1) % mod1;
        if (x1 < 0) x1 += mod1;

        long long x2 = (h2[r] - (h2[l - 1] * pow2[r - l + 1]) % mod2) % mod2;
        if (x2 < 0) x2 += mod2;               // <-- fixed: assignment was missing

        return {x1, x2};
    }
};


void solve() {
    string t, s; 
    if (!(cin >> t >> s)) return;

    int m = (int)t.size(), n = (int)s.size();

    if (m > n) {
        cout << 0 << '\n';
        return;
    }

    vector<int> ft(26, 0), fs(26, 0);

    for (int i = 0; i < m; i++) {
        ft[t[i] - 'a']++;
        fs[s[i] - 'a']++;
    }

    // store long long pairs
    set<pair<long long, long long>> st;

    DoubleHash dh(s);

    for (int i = 0; i + m <= n; i++) {
        if (i > 0) {
            fs[s[i - 1] - 'a']--;
            fs[s[i + m - 1] - 'a']++;
        }

        bool ok = true;
        for (int j = 0; j < 26; j++) if (fs[j] != ft[j]) { ok = false; break; }

        if (ok) {
            auto h = dh.getHash(i + 1, i + m); // convert to 1-indexed
            st.insert(h);
        }
    }

    cout << st.size() << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
