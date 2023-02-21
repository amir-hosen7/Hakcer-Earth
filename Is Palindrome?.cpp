#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;
ll tree[400000][30], lazy[400000], cnt[30];

void build(ll node, ll b, ll e) {
    if (b == e) {
        ll id = s[b - 1] - 'a' + 1;
        tree[node][id] = 1;
        return;
    }
    ll mid = b + (e - b) / 2;
    build(node * 2, b, mid);
    build(node * 2 + 1, mid + 1, e);
    for (ll i = 1; i <= 26; i++) {
        tree[node][i] = tree[node * 2][i] + tree[node * 2 + 1][i];
    }
}

void propagate(ll node, ll b, ll e) {
    for (ll i = 1; i <= 26; i++) {
        tree[node][i] = 0;
    }
    tree[node][lazy[node]] =  e - b + 1;
    if (b != e) {
        lazy[node * 2] = lazy[node];
        lazy[node * 2 + 1] = lazy[node];
    }
    lazy[node] = 0;
}

void update(ll node, ll b, ll e, ll l, ll r, ll val) {
    if (lazy[node]) {
        propagate(node, b, e);
    }
    if (b > r or e < l or b > e) return;
    if (b >= l and e <= r) {
        lazy[node] = val;
        propagate(node, b, e);
        return;
    }
    ll mid = b + (e - b) / 2;
    update(node * 2, b, mid, l, r, val);
    update(node * 2 + 1, mid + 1, e, l, r, val);
    for (ll i = 1; i <= 26; i++) {
        tree[node][i] = tree[node * 2][i] + tree[node * 2 + 1][i];
    }
}

void query(ll node, ll b, ll e, ll l, ll r) {
    if (lazy[node]) {
        propagate(node, b, e);
    }
    if (b > r or e < l or b > e) {
        return;
    }
    if (b >= l and e <= r) {
        for (ll i = 1; i <= 26; i++) {
            cnt[i] += tree[node][i];
        }
        return;
    }
    ll mid = b + (e - b) / 2;
    query(node * 2, b, mid, l, r);
    query(node * 2 + 1, mid + 1, e, l, r);
}

int main() {

    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> s;
    ll n = s.size();
    build(1, 1, n);
    ll q;
    cin >> q;
    while (q--) {
        ll type;
        cin >> type;
        if (type == 1) {
            ll l, r;
            char ch;
            cin >> l >> r >> ch;
            update(1, 1, n, l, r, ch - 'a' + 1);
        }
        else {
            ll l, r;
            cin >> l >> r;
            query(1, 1, n, l, r);
            ll ck = 0;
            for (ll i = 1; i <= 26; i++) {
                if (cnt[i] % 2) ck++;
                cnt[i] = 0;
            }
            if (ck > 1) cout << "No\n";
            else cout << "Yes\n";
        }
    }
    return 0;
}

