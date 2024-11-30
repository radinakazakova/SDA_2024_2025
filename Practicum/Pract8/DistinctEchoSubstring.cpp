#define ll long long

class Solution {
public:

    // by hashing // accepted
    int distinctEchoSubstrings(string s) {
        ll n = s.size(), prm = 31, mod = 1000000007;
        // h[i] : store hash of s[0....i] // p[i] store prem^i
        vector<ll> h(n, 0), p(n, 0);

        // preprocessing : calculate hash array and prime power
        h[0] = s[0] % mod;
        p[0] = 1;
        for (int i = 1; i < n; i++) {
            h[i] = (h[i - 1] * prm + s[i]) % mod;
            p[i] = (p[i - 1] * prm) % mod;
        }


        // cal hash of s[i...j]  // inclusive
        auto calHash = [&](int i, int j) {
            auto res = (h[j] - (i >= 1 ? h[i - 1] * p[j - i + 1] : 0)) % mod;
            return (res + mod) % mod;
        };


        // store hashes instead of string to reduce the time
        unordered_set<ll> st;
        for (int i = 0; i < n; i++) {
            // assume ith index as start of string, so first substring s[i...i+len-1] and second is s[i+len...i+len+len-1]
            for (int len = 1; i + 2 * len <= n; len++) {
                // compare both by hashing
                if (calHash(i, i + len - 1) == calHash(i + len, i + 2 * len - 1))
                    st.insert(calHash(i, i + len - 1));
            }
        }
        return st.size();
    }

};
