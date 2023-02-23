#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
    //ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> v(n + 1);
        for (ll i = 1; i <= n; i++) {
            cin >> v[i];
        }
        vector<ll> bit(32, 0);
        ll cnt = 0, res = n, L = 1;
        for (ll i = 1; i <= n; i++) {
            ll curr = v[i], ok = 1;
            for (ll j = 30; j >= 0; j--) {
                ll pp = (1LL << j);
                if (curr >= pp) {
                    bit[j]++;
                    curr -= pp;
                }
                if (bit[j] > 1) {
                    ok = 0;
                }
            }
            if (ok == 0) {
                res += (cnt * (cnt + 1)) / 2;
                cnt = 0;
                res += (i - L - 1);
                while (1) {
                    ll aa = v[L++], flag = 1;
                    for (ll j = 30; j >= 0; j--) {
                        ll pp = (1LL << j);
                        if (aa >= pp) {
                            bit[j]--;
                            aa -= pp;
                        }
                        if (bit[j] > 1) {
                            flag = 0;
                        }
                    }
                    if (flag) break;
                }
            }
            else {
                if ((i - L) > 1) cnt++;
            }
        }
        res += (n - L);
        cout << res << "\n";
    }
    return 0;
}
