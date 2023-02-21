#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++) {
        cin >> v[i];
    }
    ll flag = 0, l;
    vector<pair<ll, ll>> seg;
    for (ll i = 0; i < (n - 1); i++) {
        if (v[i] == v[i + 1]) {
            if (!flag) {
                l = i, flag = 1;
            }
        }
        else {
            if (flag) {
                seg.push_back({l + 1, i + 1});
            }
            else {
                seg.push_back({i + 1, i + 1});
            }
            flag = 0;
        }
    }
    if (flag) {
        seg.push_back({l + 1, n});
    }
    else {
        seg.push_back({n, n});
    }
    ll siz = seg.size();
    if (k >= siz) {
        cout << "0\n";
        bool ok = 0;
        for (ll i = 0; i < siz; i++) {
            for (ll j = seg[i].first; j <= seg[i].second; j++)  {
                if (k == (siz - i)) {
                    cout << j << " " << seg[i].second << "\n";
                    for (ll k = i + 1; k < siz; k++) {
                        cout << seg[k].first << " " << seg[k].second << "\n";
                    }
                    ok = 1; break;
                }
                k--;
                cout << j << " " << j << "\n";
            }
            if (ok) break;
        }
    }
    else {
        cout << "1\n";
        for (ll i = 1; i < k; i++) {
            cout << i << " " << i << "\n";
        }
        cout << k << " " << n << "\n";
    }
    return 0;
}

